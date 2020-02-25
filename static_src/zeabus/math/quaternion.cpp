// FILE			: quaternion.cpp
// AUTHOR		: K.Supasan
// CREATE ON	: 2020, Febuary 25 (UTC+0)
// MAINTAINER	: K.Supasan

// MACRO DETAIL

// README

// REFERENCE

// MACRO SET

// MACRO CONDITION

#include    <zeabus/math/quaternion.hpp>

namespace zeabus
{

namespace math
{
    void get_euler( const tf::Quaternion source,
            double* roll , double* pitch , double* yaw )
    {
        *yaw = atan2( 2 * ( source.x() * source.y() + source.w() * source.z() ),
                pow( source.w() , 2 ) + pow( source.x() , 2 ) - 
                        pow( source.y() , 2 ) - pow( source.z() , 2 )  );
        *pitch = atan2( -2.0*( source.x() * source.z() - source.w() * source.y() ),
                sqrt( 1.0 - pow( 2.0*( source.x() * source.z() - source.w() * source.y() ) , 2 ) ) );
        *roll = atan2( 2.0 * ( source.y() * source.z() + source.w() * source.x() ) ,
                pow( source.w() , 2 ) - pow( source.x() , 2 ) - 
                        pow( source.y() , 2 ) + pow( source.z() , 2 )  );
    }    

    void get_euler( const geometry_msgs::Quaternion source,
            double* roll , double* pitch , double* yaw )
    {
        *yaw = atan2( 2 * ( source.x * source.y + source.w * source.z ),
                pow( source.w , 2 ) + pow( source.x , 2 ) - 
                        pow( source.y , 2 ) - pow( source.z , 2 )  );
        *pitch = atan2( -2.0*( source.x * source.z - source.w * source.y ),
                sqrt( 1.0 - pow( 2.0*( source.x * source.z - source.w * source.y ) , 2 ) ) );
        *roll = atan2( 2.0 * ( source.y * source.z + source.w * source.x ) ,
                pow( source.w , 2 ) - pow( source.x , 2 ) - 
                        pow( source.y , 2 ) + pow( source.z , 2 )  );
    }    
} // namespace math

} // namespace zeabus
