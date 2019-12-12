// FILE			: array.hpp
// AUTHOR		: K.Supasan
// CREATE ON	: 2019, December 5 (UTC+0)
// MAINTAINER	: K.Supasan

// MACRO DETAIL

// README

// REFERENCE
//  ref01   : https://en.cppreference.com/w/cpp/algorithm/stable_sort

// MACRO SET

// MACRO CONDITION

#include    <iostream>

#include    <cmath>

#include    <zeabus/packet/base_class.hpp>

#ifndef _ZEABUS_MATH_ARRAY_HPP__
#define _ZEABUS_MATH_ARRAY_HPP__

namespace zeabus
{

namespace math
{

    template< class vector_type >
    class Array : public zeabus::packet::BaseClass< vector_type >
    {
        public:
            Array( unsigned int size = 0 , vector_type init_value = 0 );

            void stable_sort( std::vector< vector_type >* ptr_vector );

            double get_sum( bool sum_again = true );
        
            double get_mean();
    
            double get_variance();

            double get_median();

        protected:
            double summation;

            bool already_sum;

            void find_summation();

    };

} // namespace math

} // namespace zeabus

#include    <zeabus/math/array.cpp>

#endif // _ZEABUS_MATH_ARRAY_HPP__
