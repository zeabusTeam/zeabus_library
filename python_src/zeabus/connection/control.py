#!/usr/bin/env python2
# FILE			: __init__.py
# AUTHOR		: K.Supasan
# CREATE ON		: 2019, December 30 (UTC+0)
# MAINTAINER	: K.Supasan

# README

# REFERENCE

import rospy

from std_msgs.msg import Header, String
from ..ros import message as nm # new message
from . import constant as pm # paramet
from zeabus_utility.srv import SendFloat, SendBool

class ControlHandle:

    def __init__( self , node_name ):
        self.header = nm.header( node_name )

        self.publish_message = rospy.Publisher( "/mission/control" , String , queue_size = 10 )

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

    def call( self , client , data ):
        result = None
        try:
            self.header.stamp = rospy.get_rostime()
            result = client( self.header , data )
        except rospy.ServiceException , error :
            print( "Service call filed : {:s}".format( error ))
        return result

    def pub( self , data ):
        self.publish_message.publish( String( self.header.frame_id + " : " + data ) )


