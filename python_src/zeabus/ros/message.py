#!/usr/bin/env python2
# FILE			: message.py
# AUTHOR		: K.Supasan
# CREATE ON		: 2019, October 22 (UTC+0)
# MAINTAINER	: K.Supasan

# README
#   This package will help you to manage about init value of ros message

# REFERENCE

import rospy

from std_msgs.msg import Header
from nav_msgs.msg import Odometry
from geometry_msgs.msg import Quaternion, TwistStamped, Twist , Vector3
from zeabus_utility.msg import Int16Array8, ControlCommand, Float64Array8 , Float64Array

def header( frame_id ):
    answer = Header()
    answer.stamp = rospy.get_rostime()
    answer.frame_id = frame_id
    return answer

def vector3( vector ):
    answer = Vector3()
    answer.x = vector[0]
    answer.y = vector[1]
    answer.z = vector[2]
    return answer

def twist_stamped( linear = ( 0 , 0 , 0 ) , angular = ( 0 , 0 , 0 ) ):
    answer = TwistStamped()
    answer.twist = twist()
    return answer

def twist( linear = ( 0 , 0 , 0 ) , angular = ( 0 , 0 , 0 ) ):
    answer = Twist()
    answer.linear = vector3( linear )
    answer.angular = vector3( linear )
    return answer

def quaternion( x = 0 , y = 0, z = 0, w  = 1 ):
    answer = Quaternion()
    answer.x = x
    answer.y = y
    answer.z = z
    answer.w = w
    return answer

def odometry():
    answer = Odometry()
    answer.pose.pose.position.x = 0
    answer.pose.pose.position.y = 0
    answer.pose.pose.position.z = 0
    answer.pose.pose.orientation = quaternion()
    answer.twist.twist = twist()
    return answer 

def int16_array8( init_value = ( 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 )):
    answer = Int16Array8()
    answer.data = init_value
    return answer

def float64_array8( init_value = ( 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ) ):
    answer = Float64Array8()
    answer.data = init_value
    return answer

def float64_array( frame , init_value = ( 0 , 0 , 0 , 0 , 0 , 0 ) )
    answer = Float64Array()
    answer.header.stamp = rospy.get_rostime()
    answer.header.frame_id = frame
    answer.data = init_value
    return answer

def control_command():
    answer = ControlCommand()
    answer.target = ( 0 , 0 , 0 , 0 , 0 , 0 )
    answer.mask = ( False , False , False , False , False ,False )
    return answer
    
