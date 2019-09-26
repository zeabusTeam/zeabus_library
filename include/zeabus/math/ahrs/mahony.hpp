// FILE			: mahony.hpp
// AUTHOR		: K.Supasan
// CREATE ON	: 2019, September 25 (UTC+0)
// MAINTAINER	: K.Supasan

// MACRO DETAIL

// README
//  This library same madgwick.hpp

// REFERENCE
//  ref01   : https://x-io.co.uk/open-source-imu-and-ahrs-algorithms/?fbclid=IwAR1vZrF7_U0ZxC2kvlx1dGM5MH5JM0U3K7d81IflMTLobIfJvU3ze0aFSpI

// MACRO SET

// MACRO CONDITION

#include    <cmath>

#include    <zeabus/math/ahrs/inverse_sqrt.hpp>

#ifndef _ZEABUS_MATH_AHRS_MAHONY_HPP__
#define _ZEABUS_MATH_AHRS_MAHONY_HPP__

namespace zeabus
{

namespace math
{

namespace ahrs
{

    class Mahony
    {

        public:
            Mahony( float q0 , float q1 , float q2 , float q3 , // quaternion w ,x  ,y ,z)
                    float twoKp , float twoKi );

            void update( float gx , float gy ,float gz , // gravity
                    float ax , float ay , float az , // acceleration
                    float mx , float my , float mz , // magnetic
                    float sampleFreq ); // time period

            void update( float gx , float gy , float gz , // gravity 
                    float ax , float ay , float az , // acceleration
                    float sampleFreq ); // time period

        protected:
            float q0 , q1 , q2 , q3 ;
            float twoKp , twoKi;
            float integralFBx , integralFBy , integralFBz;
    }; // object mahony    

} // namespace ahrs

} // namespace math

} // namespace zeabus

#endif // _ZEABUS_MATH_AHRS_MAHONY_HPP__
