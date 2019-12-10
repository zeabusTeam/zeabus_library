// FILE			: outliner.hpp
// AUTHOR		: K.Supasan
// CREATE ON	: 2019, December 8 (UTC+0)
// MAINTAINER	: K.Supasan

// MACRO DETAIL

// README

// REFERENCE

// MACRO SET

// MACRO CONDITION

#include    <zeabus/math/array.hpp>

#ifndef _ZEABUS_FILTER_OUTLINER_HPP__
#define _ZEABUS_FILTER_OUTLINER_HPP__

namespace zeabus
{

namespace filter
{

    template
    < class vector_type , unsigned int size_array >
    class Outliner : public zeabus::math::Array< vector_type >
    {
        public:
            Outliner( vector_type init_value );

            void set_cut_size( unsigned int cut_size );

            void push_data( vector_type value );

            double get_result();

        protected:
            unsigned int cut_size; // cut_size is mean cut min and max

            unsigned int run_pos;
        
            void move_position();
            
    };

} // namespace filter

} // namespace zeabus

#include    <zeabus/filter/outliner.cpp>

#endif
