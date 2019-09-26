// FILE			: madgwick.hpp
// AUTHOR		: K.Supasan
// CREATE ON	: 2019, September 24 (UTC+0)
// MAINTAINER	: K.Supasan

// MACRO DETAIL

// README
//  This source have apply renovate code C from ref01 to class object easy to use and flexible.
//  All algorithm I don't edit all value
//  ( q0 , q1 , q2 , q3 ) = ( w , x , y , z )
//  beta value is equal 2 * proportional gain

// REFERENCE
//  ref01   : https://x-io.co.uk/open-source-imu-and-ahrs-algorithms/?fbclid=IwAR1vZrF7_U0ZxC2kvlx1dGM5MH5JM0U3K7d81IflMTLobIfJvU3ze0aFSpI

// MACRO SET

// MACRO CONDITION

#include    <cmath>

#include    <zeabus/math/ahrs/inverse_sqrt.hpp>

#ifndef _ZEABUS_MATH_AHRS_MADGWICK_HPP__
#define _ZEABUS_MATH_AHRS_MADGWICK_HPP__

namespace zeabus
{

namespace math
{

namespace ahrs
{

    class Madgwick
    {
        public:

            Madgwick( float q0 , float q1 , float q2 , float q3 , float beta = 0.1f );

            void update( float gx , float gy , float gz , float ax , float ay , float az ,
                    float mx , float my , float mz , 
                    double sampleFreq );

            void update( float gx , float gy , float gz , float ax , float ay , float az ,
                    double sampleFreq );

        protected:
            float q0, q1, q2, q3;
            float beta;

    }; // object Madgwick

// Fast inverse square-root
// See: http://en.wikipedia.org/wiki/Fast_inverse_square_root

} // namespace ahrs

} // namespace math

} // namespace zeabus

#endif // _ZEABUS_MATH_AHRS_MADGWICK_HPP__
