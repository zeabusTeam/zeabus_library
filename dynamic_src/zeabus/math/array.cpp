// FILE			: array.cpp
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

    template< class vector_type >
    Array< vector_type >::Array( unsigned int size , vector_type init_value ) : 
            zeabus::packet::BaseClass< vector_type >::BaseClass()
    {
        this->vector.assign( size , init_value );
    } // function Constructor Array

    template< class vector_type >
    void Array< vector_type >::stable_sort( std::vector< vector_type >* ptr_vector )
    {
        (*ptr_vector) = std::vector< vector_type >( this->vector.begin() , this->vector.end() );
        std::stable_sort( ptr_vector->begin() , ptr_vector->end() );
    } // function sort

    template< class vector_type >
    double Array< vector_type >::median( int position )
    {
        double answer;
        std::vector< vector_type > temp_vector( this->vector.begin() , this->vector.end() );
        std::stable_sort( temp_vector.begin() , temp_vector.end() );
        unsigned int size_vector = temp_vector.size();
        if( ( size_vector % 2 == 0 ) && ( position == - 1 ) )
        {
            answer = ( temp_vector[  size_vector / 2 ] + temp_vector[ (size_vector / 2) - 1] ) / 2;
        }
        else if( position == - 1 )
        {
            answer = temp_vector[ ( size_vector + 1) / 2 - 1 ];
        }
        else
        {
            answer = temp_vector[ position ];
        }
        return answer;
    }

    template< class vector_type >
    double Array< vector_type >::sum()
    {
        double summation = 0;
        for( auto iter = this->begin() ; iter != this->end() ; iter++ )
        {
            summation += *iter;
        } // loop get summation
        return summation;
    } // function sum

    template< class vector_type >
    double Array< vector_type >::mean()
    {
        return this->sum() / this->size();
    } // function mean

    template< class vector_type >
    double Array< vector_type >::variance()
    {
        double temporary = 0;
        double summation = this->sum();
        for( auto iter = this->vector.begin() ; iter != this->end() ; iter++ )
        {
            temporary += pow( ( *iter ) - summation , 2 );
        }
        return temporary / this->size;
    } // function variance

    template< class vector_type >
    double Array< vector_type >::std()
    {
        return std::sqrt( this->variance() );
    }

} // namespace math

} // namespace zeabus
