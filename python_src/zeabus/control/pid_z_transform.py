#!/usr/bin/env python2
# FILE			: pid_z_transform.py
# AUTHOR		: K.Supasan
# CREATE ON		: 2019, October 08 (UTC+0)
# MAINTAINER	: K.Supasan

# README
# Form reference 1 this is how to process of pid so I can summary about calculate is
# Form reference we will you data at time t , t-1 , t-2 so
#   I will collect data by using list and index is 0 , 1 , 2 for time t , t-1 , t-2 by order
# I find I wrong to try it by myself from ref03 we use matlab for solve equation
# About constant parameter sample_time and coefficient
#   coefficient is filter coefficient
#   sample_time will match about frequency of PID control

# REFERENCE
# ref01 : https://www.scilab.org/discrete-time-pid-controller-implementation
# ref02 : https://docs.python.org/3.1/tutorial/datastructures.html
# ref03 : https://www.mathworks.com/help/symbolic/solve-an-algebraic-equation.html
# ref04 : https://www.mathworks.com/help/symbolic/choose-function-to-rearrange-expression.html#buxwf81

class PIDZTransform:

    def __init__( self , kp = 0 , ki = 0 , kd = 0 , sample_time = 0.1 , coefficient = 5 ):
        self.set_parameter( kp , ki , kd , sample_time , coefficient )

    def set_parameter( self , kp , ki , kd , sample_time , coefficient ):
        self.b0 = ( 4*coefficient + 
                4 * kp +
                2 * ki * sample_time +
                coefficient * ki * sample_time +
                2 * coefficient * kp * sample_time )
        self.b1 = ( coefficient * ki * sample_time * sample_time -
                8 * coefficient -
                8 * kp )
        self.b2 = ( 4 * coefficient +
                4 * kp -
                2 * ki * sample_time +
                coefficient * ki * sample_time * sample_time -
                2 * coefficient * kp * sample_time )
        self.a0 = ( coefficient * sample_time * 2 + 
                4 )
        self.a1 = -8 
        self.a2 = ( coefficient * sample_time * 2 +
                4 )
        self.reset()

    def reset( self ):
        self.input = [ 0 , 0 , 0 ]
        self.output = [ 0 , 0 , 0 ]

    def calculate( self , input_data , saturation = 0):
        self.input.pop()
        self.input.insert( 0 , input_data )
        self.output.insert( 0 , # insert input at first element 
                ( self.b0 * self.input[0] + 
                        self.b1 * self.input[1] + 
                        self.b2 * self.input[2] -
                        self.a1 * self.output[1 - 1 ] + # for output we want data at time - 1
                        self.a2 * self.output[2 - 1 ] # for output we want data at time - 2
                ) / self.a0
        )
        self.output.pop()
        return self.output[0]
