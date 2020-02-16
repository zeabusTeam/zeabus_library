#!/usr/bin/env python2
# FILE			: __init__.py
# AUTHOR		: K.Supasan
# CREATE ON		: 2019, December 30 (UTC+0)
# MAINTAINER	: K.Supasan

# README

# REFERENCE

import rospy

import tf

from thread import allocate_lock

from std_msgs.msg import Header, String
from ..ros import message as nm # new message
from ..math.quaternion import Quaternion
from .constant import Control as pm # parameter
from zeabus_utility.srv import SendFloat, SendBool , ServiceBool, ServiceMask
from zeabus_utility.msg import Float64Array, ControlCommand
from nav_msgs.msg import Odometry

class ControlHandle:

    def __init__( self , node_name ):
        self.header = nm.header( node_name )

        self.publish_message = rospy.Publisher( "/mission/control" , String , queue_size = 10 )

        self.publish_addition_force = rospy.Publisher( pm._TOPIC_ADDITION_FORCE , 
                Float64Array,
                queue_size = 10 )

        self.publish_target_velocity = rospy.Publisher( pm._TOPIC_TARGET_VELOCITY , 
                ControlCommand,
                queue_size = 10 )

        self.listener_tf = tf.TransformListener()

        self.pose = [ 0 , 0 , 0 , 0 , 0 , 0 ]
        self.velocity = [ 0 , 0 , 0 , 0 , 0 , 0 ]
        self.lock_state = all
        self.listener_state = rospy.Subscriber(
                pm._TOPIC_INPUT_STATE,
                Odometry,
                self.callback_state
        )
        self.shutdowm_listen_state()

        self.rate = rospy.Rate( 10 ) # I suggest to use sleep for control 10 Hz

    def install_listen_state( self ):
        self.listener_state = rospy.Subscriber(
                pm._TOPIC_INPUT_STATE,
                Odometry,
                self.callback_state
        )

    def shutdowm_listen_state( self ):
        self.listener_state.unregister()

    def check_error( self , x=None , y=None , z=None , roll=None , pitch=None , yaw=None ):
        result = True
        linear_error , angular_error = self.get_error()
        if x != None and result :
            result = abs( linear_error[0]  ) < x
        if y != None and result :
            result = abs( linear_error[1]  ) < y
        if z != None and result :
            result = abs( linear_error[2]  ) < z
        if roll != None and result :
            result = abs( angular_error[2]  ) < roll
        if pitch != None and result :
            result = abs( angular_error[1]  ) < pitch
        if yaw != None and result :
            result = abs( angular_error[0]  ) < yaw
        return result

    def get_error( self ):
        try:
            ( translation , rotation ) = self.listener_tf.lookupTransform(
                    pm._FRAME_ROBOT,
                    pm._FRAME_ROBOT_TARGET,
                    rospy.Time()
            )
        except( tf.LookupExcepthin , tf.ConnectivityException , tf.ExtrapolationException ):
            translation = ( 0 , 0 , 0 )
            rotation = ( 0 , 0 , 0 , 1 )

        return ( translation , Quaternion( rotation ).get_euler() )

    def get_target( self ):
        try:
            ( translation , rotation ) = self.listener_tf.lookupTransform(
                    pm._FRAME_ODOM,
                    pm._FRAME_ROBOT,
                    rospy.Time()
            )
        except( tf.LookupExcepthin , tf.ConnectivityException , tf.ExtrapolationException ):
            translation = ( 0 , 0 , 0 )
            rotation = ( 0 , 0 , 0 , 1 )

        return ( translation , Quaternion( rotation ).get_euler() )
        
    def activate( self , data ):
        return self.call( rospy.ServiceProxy( pm._TOPIC_ACTIVATE , SendBool ) , data )

    def reset_all( self , data ):
        return self.call( rospy.ServiceProxy( pm._TOPIC_RESET_ALL , SendBool ) , data )

    def plane_xy( self , data ):
        return self.call( rospy.ServiceProxy( pm._TOPIC_PLANE_XY , SendFloat ) , data )
        
    def absolute_depth( self , data ):
        return self.call( rospy.ServiceProxy( pm._TOPIC_ABSOLUTE_YAW , SendFloat )  , data )

    def absolute_yaw( self , data ):
        return self.call( rospy.ServiceProxy( pm._TOPIC_ABSOLUTE_YAW , SendFloat )  , data )

    def absolute_pitch( self , data ):
        return self.call( rospy.ServiceProxy( pm._TOPIC_ABSOLUTE_PITCH , SendFloat )  , data )

    def absolute_roll( self , data ):
        return self.call( rospy.ServiceProxy( pm._TOPIC_ABSOLUTE_ROLL , SendFloat )  , data )

    def relative_depth( self , data ):
        return self.call( rospy.ServiceProxy( pm._TOPIC_RELATIVE_DEPTH , SendFloat )  , data )

    def relative_yaw( self , data ):
        return self.call( rospy.ServiceProxy( pm._TOPIC_RELATIVE_YAW , SendFloat )  , data )

    def relative_pitch( self , data ):
        return self.call( rospy.ServiceProxy( pm._TOPIC_RELATIVE_PITCH , SendFloat )  , data )

    def relative_roll( self , data ):
        return self.call( rospy.ServiceProxy( pm._TOPIC_RELATIVE_ROLL , SendFloat )  , data )

    def set_mask( self,  x=True , y=True , z=True , roll=True , pitch=True , yaw=True ):
        data = ( x , y , z , roll , pitch , yaw )
        return self.call_mask( True , data )

    def get_mask( self ):
        return self.call_mask( False )

    def call( self , client , data ):
        result = None
        try:
            self.header.stamp = rospy.get_rostime()
            result = client( self.header , data )
        except rospy.ServiceException , error :
            print( "Service call filed : {:s}".format( error ))
        return result

    def call_mask( self , activate , data = (True , True , True , True , True , True ) ):
        result = ( False , False , False , False , False , False)
        try:
            result = rospy.ServiceProxy( pm._TOPIC_MASK , ServiceMask )( activate , data )
        except rospy.ServiceException , error :
            print( "Service Mask failure : {:s}".format( error ))
        return result
        
    def pub( self , data ):
        self.publish_message.publish( String( self.header.frame_id + " : " + data ) )

    def add_force( self , frame , summary = None,
                x = 0 , y = 0 , z = 0 , roll = 0 , pitch = 0 , yaw = 0 ):
        if summary == None :
            self.publish_addition_force.publish( nm.float64_array( frame ,
                    ( x , y , z , roll , pitch , yaw ) ) )
        else:
            self.publish_addition_force.publish( nm.float64_array( frame , summary ) )


    def target_velocity( self , frame ,
            x = None , y = None , z = None , roll = None , pitch = None , yaw = None ):
        # first step I will find mark
        target = []
        mask = []
        mask.append( True if x != None else False )
        mask.append( True if y != None else False )
        mask.append( True if z != None else False )
        mask.append( True if roll != None else False )
        mask.append( True if pitch != None else False )
        if roll != None or pitch != None or yaw != None :
            mask.append( True )
        else:
            mask.append( False )

        target.append( x if x != None else 0 )
        target.append( y if y != None else 0 )
        target.append( z if z != None else 0 )
        target.append( roll if roll != None else 0 )
        target.append( pitch if pitch != None else 0 )
        target.append( yaw if yaw != None else 0 )

        self.publish_target_velocity.publish( nm.control_command( frame , target , mask ) )
        

    def callback_state( self , message ):
        with self.lock_state():
            self.pose[ 0 ] = message.pose.pose.position.x
            self.pose[ 1 ] = message.pose.pose.position.y
            self.pose[ 2 ] = message.pose.pose.position.z
            self.pose[ 3 : 6 ] = Quaternion( ( 
                    message.pose.pose.orientation.x,
                    message.pose.pose.orientation.y,
                    message.pose.pose.orientation.z,
                    message.pose.pose.orientation.w ) ).get_euler()[ 0 : 3 ]
            self.velocity[ 0 ] = message.twist.twist.linear.x
            self.velocity[ 1 ] = message.twist.twist.linear.y
            self.velocity[ 2 ] = message.twist.twist.linear.z
            self.velocity[ 3 ] = message.twist.twist.angular.x
            self.velocity[ 4 ] = message.twist.twist.angular.y
            self.velocity[ 5 ] = message.twist.twist.angular.z

    def __getitem__( self , index , position = True ):
        return self.pose[ index ] if position else self.velocity[ index ]

    def sleep( self ):
        self.rate.sleep()

    def ok( self ):
        return not rospy.is_shutdown()
