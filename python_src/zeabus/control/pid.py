#!/usr/bin/env python2
# FILE			: pid.py
# AUTHOR		: K.Supasan
# CREATE ON		: 2019, October 30 (UTC+0)
# MAINTAINER	: K.Supasan

# README

# REFERENCE

from ..math.general import equal

class PID:

    def __init__( self , kp = 0 , ki = 0 , kd = 0 , 
            ks = 0 , sample_time = 0.1 , coefficient = 5 ):
        self.input = 0;
        self.output = 0 ;
        self.kp = 0
        self.ki = 0
        self.kd = 0
        self.ks = 0
        self.offset = 0 
        self.sample_time = sample_time 
        self.i_term = 0
        self.set_parameter( kp , ki , kd , ks , sample_time , coefficient )

    def set_parameter( self , kp , ki , kd , ks , sample_time , coefficient , offset = 0 ):
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
        elif not equal( self.ks , ks ):
            have_reset = True
        else:
            None
        self.kp = kp
        self.ki = ki
        self.kd = kd
        self.sample_time = sample_time
        self.ks = ks
        self.offset = offset
        if have_reset :
            self.reset()

    def reset( self ):
        self.input = 0
        self.output = 0;
        self.i_term = 0
        
    def calculate( self , input_data , saturation = 0):
        # Original Summation term
        self.i_term += self.ki * ( self.input + input_data ) / 2.0 * self.sample_time 
        # Saturation part
        self.i_term -= self.ks * saturation
        # Differential part
        self.d_term = self.kd * ( input_data - self.input ) / self.sample_time
        # Have plus all term
        self.output = self.i_term + self.d_term + self.kp*input_data + self.offset
        # Save data to make delay unit
        self.input = input_data
        return self.output
