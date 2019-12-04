#!/usr/bin/env python2
# FILE			: pid.py
# AUTHOR		: K.Supasan
# CREATE ON		: 2019, October 30 (UTC+0)
# MAINTAINER	: K.Supasan

# README

# REFERENCE

class PID:

    def __init__( self , kp = 0 , ki = 0 , kd = 0 , sample_time = 0.1 , coefficient = 5 ):
        self.set_parameter( kp , ki , kd , sample_time , coefficient )
        self.input = [ 0 , 0 ];
        self.output = 0 ;
        self.kp = 0
        self.ki = 0
        self.kd = 0
        self.sample_time = 0

    def set_parameter( self , kp , ki , kd , sample_time , coefficient ):
        self.kp = kp
        self.ki = ki
        self.kd = kd
        self.sample_time = sample_time
        self.reset()

    def reset( self ):
        self.input = 0
        self.output = 0;
        self.i_term = 0
        
    def calculate( self , input_data , saturation = 0):
        self.i_term = ( self.ki * ( self.input + input_data )/2.0 * self.sample_time + 
                        -saturation + 
                        self.i_term )
        self.d_term = self.kd * ( input_data - self.input ) / self.sample_time
        self.output = self.i_term + self.d_term + self.kp*input_data
        self.input = input_data
        return self.output
