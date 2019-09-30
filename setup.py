#!/usr/bin/env python2
# FILE			: setup.py
# AUTHOR		: K.Supasan
# CREATE ON		: 2019, September 30 (UTC+0)
# MAINTAINER	: K.Supasan

# README

# REFERENCE
#   ref1    : http://wiki.ros.org/rospy_tutorials/Tutorials/Makefile?fbclid=IwAR2A9UVzczVQoIe31XKCcw6TY180kRGY0WTpahvKoLr72S99Lrg5FKCUa9A
#   ref2    : https://github.com/zeabusTeam/SAUVC2019/blob/master/zeabus_extension/setup.py

from distutils.core import setup
from catkin_pkg.python_setup import generate_distutils_setup

setup_args = generate_distutils_setup(
    packages = ['zeabus']
    , package_dir = { '' : 'python_src' }
    , author ='K.Supasan'
    , maintainer = 'K.Supasan' 
    , maintainer_email = 'supasan.k@ku.th'
    , desciption = "This library will create for API of python language for zeabus team"
    , version = "0.0.0"
)

setup( **setup_args )
