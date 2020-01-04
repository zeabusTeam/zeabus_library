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
    return { "ha" : message_joy.axes[ 0 ], # ha is horizontal axes
            "va" : message_joy.axes[ 1 ], # va is vertical axes
            "hra" : message_joy.axes[ 2 ],  # hra is horizontal right analog
            "vra" : message_joy.axes[ 3 ], # vra is vertical right analog
            "hla" : message_joy.axes[ 4 ], # hla is horizontal left analog
            "vla" : message_joy.axes[ 5 ] # vla is vertical left analog
            "x" : False if message_joy.buttons[ 0 ] == 0 else False ,
            "a" : False if message_joy.buttons[ 1 ] == 0 else False ,
            "b" : False if message_joy.buttons[ 2 ] == 0 else False ,
            "y" : False if message_joy.buttons[ 3 ] == 0 else False ,
            "LB" : False if message_joy.buttons[ 4 ] == 0 else False ,
            "RB" : False if message_joy.buttons[ 5 ] == 0 else False ,
            "LT" : False if message_joy.buttons[ 6 ] == 0 else False ,
            "RT" : False if message_joy.buttons[ 7 ] == 0 else False ,
            "back" : False if message_joy.buttons[ 8 ] == 0 else False ,
            "start" : False if message_joy.buttons[ 9 ] == 0 else False ,
            "la" : False if message_joy.buttons[ 10 ] == 0 else False ,
            "ra" : False if message_joy.buttons[ 11 ] == 0 else False 
        } 
