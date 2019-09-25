// FILE			: inverse_sqrt.cpp
// AUTHOR		: K.Supasan
// CREATE ON	: 2019, September 25 (UTC+0)
// MAINTAINER	: K.Supasan

// MACRO DETAIL

// README

// REFERENCE

// MACRO SET

// MACRO CONDITION

#include    <zeabus/math/ahrs/inverse_sqrt.hpp>

namespace zeabus
{

namespace math
{

namespace ahrs
{

    float invSqrt( float x )
    {
        float halfx = 0.5f * x;
        float y = x;
        long i = *(long*)&y;
        i = 0x5f3759df - (i>>1);
        y = *(float*)&i;
        y = y * (1.5f - (halfx * y * y));
        return y; 
    } // function invSqrt

} // namespace ahrs

} // namespace math

} // namespace zeabus
