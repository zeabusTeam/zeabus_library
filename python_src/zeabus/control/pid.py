#!/usr/bin/env python2
# FILE			: pid.py
# AUTHOR		: K.Supasan
# CREATE ON		: 2019, October 30 (UTC+0)
# MAINTAINER	: K.Supasan

# README

# REFERENCE

from ..math.general import equal

class PID:

    def __init__( self , kp = 0 , ki = 0 , kd = 0 , sample_time = 0.1 , coefficient = 5 ):
        self.set_parameter( kp , ki , kd , sample_time , coefficient )
        self.input = [ 0 , 0 ];
        self.output = 0 ;
        self.kp = 0
        self.ki = 0
        self.kd = 0
        self.offset = 0 
        self.sample_time = 0

    def set_parameter( self , kp , ki , kd , sample_time , coefficient , offset = 0 ):
        have_reset = False
        if not equal( self.kp , kp ) :
            have_reset = True
        elif not equal( self.ki , ki ):
            have_reset = True
        elif not equal( self.kd , kd ):
            have_reset = True
        elif not equal( self.offset , offset ):
            have_reset = True
        elif not equal( self.sample_time , sample_time ):
            have_reset = True
        else:
            None
        self.kp = kp
        self.ki = ki
        self.kd = kd
        self.sample_time = sample_time
        if have_reset :
            self.offset = offset

    def reset( self ):
        self.input = 0
        self.output = 0;
        self.i_term = 0
        
    def calculate( self , input_data , saturation = 0):
        self.i_term = ( self.ki * ( self.input + input_data )/2.0 * self.sample_time +  # Area Part
                        -saturation * self.ki + # Saturation Part 
                        self.i_term ) # Summation Part
        self.d_term = self.kd * ( input_data - self.input ) / self.sample_time
        self.output = self.i_term + self.d_term + self.kp*input_data + self.offset
        self.input = input_data
        return self.output
