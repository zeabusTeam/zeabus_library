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

    void rotation( const tf::Quaternion& quaternion , boost::array< double , 3 >* vector)
    {
        tf::Quaternion temp_quaternion( vector->at( 0 ), vector->at( 1 ) , vector->at( 2 ) , 0 );
        temp_quaternion = quaternion.inverse() * temp_quaternion * quaternion;
        vector->at( 0 ) = temp_quaternion.x();
        vector->at( 1 ) = temp_quaternion.y();
        vector->at( 2 ) = temp_quaternion.z();
    } 

    void inv_rotation( const tf::Quaternion& quaternion , boost::array< double , 3 >* vector )
    {
        tf::Quaternion temp_quaternion( vector->at( 0 ), vector->at( 1 ) , vector->at( 2 ) , 0 );
        temp_quaternion = quaternion * temp_quaternion * quaternion.inverse();
        vector->at( 0 ) = temp_quaternion.x();
        vector->at( 1 ) = temp_quaternion.y();
        vector->at( 2 ) = temp_quaternion.z();
    }

    void rotation( const tf::Quaternion& quaternion , double* vector)
    {
        tf::Quaternion temp_quaternion( vector[0], vector[1] , vector[2] , 0 );
        temp_quaternion = quaternion.inverse() * temp_quaternion * quaternion;
        vector[0] = temp_quaternion.x();
        vector[1] = temp_quaternion.y();
        vector[2] = temp_quaternion.z();
    } 

    void inv_rotation( const tf::Quaternion& quaternion , double* vector )
    {
        tf::Quaternion temp_quaternion( vector[0], vector[1] , vector[2] , 0 );
        temp_quaternion = quaternion * temp_quaternion * quaternion.inverse();
        vector[0] = temp_quaternion.x();
        vector[1] = temp_quaternion.y();
        vector[2] = temp_quaternion.z();
    }

    void rotation( const tf::Quaternion& quaternion , tf::Vector3* vector)
    {
        tf::Quaternion temp_quaternion( vector->x(), vector->y() , vector->z() , 0 );
        temp_quaternion = quaternion.inverse() * temp_quaternion * quaternion;
        *vector = tf::Vector3( temp_quaternion.x() , temp_quaternion.y() , temp_quaternion.z() );
    } 

    void inv_rotation( const tf::Quaternion& quaternion , tf::Vector3* vector )
    {
        tf::Quaternion temp_quaternion( vector->x(), vector->y() , vector->z() , 0 );
        temp_quaternion = quaternion * temp_quaternion * quaternion.inverse();
        *vector = tf::Vector3( temp_quaternion.x() , temp_quaternion.y() , temp_quaternion.z() );
    }
} // namespace math

} // namespace zeabus
