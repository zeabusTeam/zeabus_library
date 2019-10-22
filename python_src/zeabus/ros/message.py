#!/usr/bin/env python2
# FILE			: message.py
# AUTHOR		: K.Supasan
# CREATE ON		: 2019, October 22 (UTC+0)
# MAINTAINER	: K.Supasan

# README
#   This package will help you to manage about init value of ros message

# REFERENCE

from nav_msgs.msg import Odometry
from geometry_msgs.msg import Quaternion, TwistStamped, Twist , Vector3

def vector3( vector ):
    answer = Vector3()
    answer.x = vector[0]
    answer.y = vector[1]
    answer.z = vector[2]
    return answer

def twist_stamped( linear = ( 0 , 0 , 0 ) , angular = ( 0 , 0 , 0 ) ):
    answer = TwistStamped()
    answer.twsit = twist()
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
    answer.twist.twsit = twist()
    return answer 
