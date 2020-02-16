#!/usr/bin/env python2
# FILE			: constant.py
# AUTHOR		: K.Supasan
# CREATE ON		: 2019, December 30 (UTC+0)
# MAINTAINER	: K.Supasan

# README

# REFERENCE

class Control( object ):
    _TOPIC_RELATIVE_YAW = "/target/relative/yaw"
    _TOPIC_RELATIVE_ROLL = "/target/relative/roll"
    _TOPIC_RELATIVE_PITCH = "/target/relative/pitch"
    _TOPIC_RELATIVE_DEPTH = "/target/relative/depth"

    _TOPIC_ABSOLUTE_YAW = "/target/absolute/yaw"
    _TOPIC_ABSOLUTE_ROLL = "/target/absolute/roll"
    _TOPIC_ABSOLUTE_PITCH = "/target/absolute/pitch"
    _TOPIC_ABSOLUTE_DEPTH = "/target/absolute/depth"

    _TOPIC_RESET_ALL = "/target/reset/all"
    _TOPIC_PLANE_XY = "/target/velocity/plane_xy"

    _TOPIC_ACTIVATE = "/control/activate"
    _TOPIC_MASK = "/control/mask"

    _TOPIC_ADDITION_FORCE = "/control/system/force"
    _TOPIC_TARGET_VELOCITY = "/control/interface/target"
    _TOPIC_INPUT_STATE = "/localize/zeabus"

    _FRAME_ROBOT = "base_link"
    _FRAME_ROBOT_TARGET = _FRAME_ROBOT + "_target"
    _FRAME_ODOM = "odom"
