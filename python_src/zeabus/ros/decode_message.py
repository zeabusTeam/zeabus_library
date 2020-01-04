#!/usr/bin/env python2
# FILE			: decode_message.py
# AUTHOR		: K.Supasan
# CREATE ON		: 2020, January 04 (UTC+0)
# MAINTAINER	: K.Supasan

# README

# REFERENCE

from sensor_msgs.msg import Joy

# axes : ( left-right botton , up-down botton , 
#           left-right right analog , up-down right analog ,
#           left-right left analog , up-dowm left analog )
# buttons : ( x , a  , o , y  , LB , RB , LT , RT , back , start , left analog , right analog )

def joy_to_dict( message_joy ):
    return { "ha" : message_joy.axes[ 4 ],  # ha is horizontal axes
            "va" : message_joy.axes[ 5 ],   # va is vertical axes
            "hra" : message_joy.axes[ 2 ],  # hra is horizontal right analog
            "vra" : message_joy.axes[ 3 ],  # vra is vertical right analog
            "hla" : message_joy.axes[ 0 ],  # hla is horizontal left analog
            "vla" : message_joy.axes[ 1 ],  # vla is vertical left analog
            "x" : False if message_joy.buttons[ 0 ] == 0 else True ,
            "a" : False if message_joy.buttons[ 1 ] == 0 else True ,
            "b" : False if message_joy.buttons[ 2 ] == 0 else True ,
            "y" : False if message_joy.buttons[ 3 ] == 0 else True ,
            "LB" : False if message_joy.buttons[ 4 ] == 0 else True ,
            "RB" : False if message_joy.buttons[ 5 ] == 0 else True ,
            "LT" : False if message_joy.buttons[ 6 ] == 0 else True ,
            "RT" : False if message_joy.buttons[ 7 ] == 0 else True ,
            "back" : False if message_joy.buttons[ 8 ] == 0 else True ,
            "start" : False if message_joy.buttons[ 9 ] == 0 else True ,
            "la" : False if message_joy.buttons[ 10 ] == 0 else True ,
            "ra" : False if message_joy.buttons[ 11 ] == 0 else True 
        } 
