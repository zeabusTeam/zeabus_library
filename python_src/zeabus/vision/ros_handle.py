#!/usr/bin/env python2
# FILE          : ros_handle.py
# AUTHOR        : K.Supasan
# CREATE ON     : 2020, January 14 (UTC+0)
# MAINTAINER    : K.Supasan

# README

# REFERENCE
# ref01 : http://docs.ros.org/melodic/api/rospy/html/rospy.topics.Publisher-class.html

import rospy

from thread import allocate_lock

class Publisher:

    def __init__( self ):
        self.publish_dict = {}

    def register( self , key , topic , type_message , queue_size = 10 ):
        if key in self.publish_dict.keys():
            self.unregister( key )
        
        self.publish_dict[ key ] = rospy.Publisher( topic , type_message , queue_size = queue_size )

    def unregister( self , key ):
        self.publish_dict[ key ].unregister()

    def pub( self , key , message ):
        self.publish_dict[ key ].publish( message )

    def __del__( self ):
        for key in self.publish_dict.keys():
            self.publish_dict[ key ].unregister()

class Subscriber:

    def __init__( self , topic , type_message ):
        self.lock_message = allocate_lock()
        self.message = type_message()
        self.subscriber_message = rospy.Subscriber( topic , type_message , self.callback_message )

    def callback_message( self , message ):
        with self.lock_message:
            self.message = message

    def load_message( self ):
        data = None
        with self.lock_message:
             data = self.message
        return data

