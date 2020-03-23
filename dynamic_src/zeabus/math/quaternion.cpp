// FILE			: quaternion.cpp
// AUTHOR		: K.Supasan
// CREATE ON	: 2019, December 8 (UTC+0)
// MAINTAINER	: K.Supasan

// MACRO DETAIL

// README

// REFERENCE

// MACRO SET

// MACRO CONDITION

namespace zeabus
{

namespace math
{

    inline void rotation( const tf::Quaternion& rot_quaternion , tf::Quaternion* quaternion )
    {
        *quaternion = rot_quaternion.inverse() * (*quaternion) * rot_quaternion;
    }

    inline void inv_rotation( const tf::Quaternion& rot_quaternion , tf::Quaternion* quaternion )
    {
        *quaternion = rot_quaternion * (*quaternion) * rot_quaternion.inverse();
    }

} // namespace math

} // namespace zeabus
