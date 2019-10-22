#!/usr/bin/env python2
# FILE			: yaml_handle.py
# AUTHOR		: K.Supasan
# CREATE ON		: 2019, October 22 (UTC+0)
# MAINTAINER	: K.Supasan

# README

# REFERENCE
# ref01 : http://zetcode.com/python/yaml
# ref02 : https://www.guru99.com/python-check-if-file-exists.html
# ref03 : https://stackoverflow.com/questions/8380006/file-open-function-with-try-except-python-2-7-1
# ref04 : https://stackoverflow.com/questions/287871/how-to-print-colored-text-in-terminal-in-python

import rospy
import rospkg
import yaml
from os import path
from termcolor import colored

class YamlHandle:

    def __init__( self , package_name , subdirectory , file_name ):
        self.fullpath = rospack.get_path( package_name ) + \
                "/" + subdirectory + "/" + file_name

    def check_file( self ):
        return path.exists( self.fullpath )

    # We don't ensure for your have data or not please check before use this function
    def load_data( self ):
        data = {}
        try:
            file_system = open( self.fullpath , "r" )
            data = yaml.load( self.fullpath )
            file_system.close()
        except:
            print colored( "FATAL : " , "red") + self.fullpath + " don\'t available to download"
        return data

    def save_data( self ):
        with open( self.fullpath , 'w' ) as file_system :
            data = yaml.dump( users , file_system )
        return data
