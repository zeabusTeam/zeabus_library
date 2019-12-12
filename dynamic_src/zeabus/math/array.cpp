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
        this->already_sum = true;
        this->summation = init_value * size ;
    } // function Constructor Array

    template< class vector_type >
    void Array< vector_type >::stable_sort( std::vector< vector_type >* ptr_vector )
    {
        (*ptr_vector) = std::vector< vector_type >( this->vector.begin() , this->vector.end() );
        std::stable_sort( ptr_vector->begin() , ptr_vector->end() );
    } // function sort

    template< class vector_type >
    double Array< vector_type >::get_median()
    {
        double answer;
        std::vector< vector_type > temp_vector( this->vector.begin() , this->vector.end() );
        std::stable_sort( temp_vector.begin() , temp_vector.end() );
        unsigned int size_vector = temp_vector.size();
        if( size_vector % 2 == 0 )
        {
            answer = ( temp_vector[  size_vector / 2 ] + temp_vector[ (size_vector / 2) - 1] ) / 2;
        }
        else
        {
            answer = temp_vector[ ( size_vector + 1) / 2 - 1 ];
        }
        return answer;
    }

    template< class vector_type >
    double Array< vector_type >::get_sum( bool sum_again )
    {
        if( sum_again || !( this->already_sum ) )
        {
            this->find_summation();
        } // condition have to find again 
        return this->summation;
    } // function get_sum

    template< class vector_type >
    double Array< vector_type >::get_mean()
    {
        return this->summation / this->size();
    } // function get_mean

    template< class vector_type >
    double Array< vector_type >::get_variance()
    {
        double temporary = 0;
        (void)this->get_sum();
        for( auto iter = this->vector.begin() ;
                iter != this->end() ;
                iter++ )
        {
            temporary += pow( ( *iter ) - this->summation , 2 );
        }
        return temporary / this->size;
    } // function get_variance

    template< class vector_type >
    void Array< vector_type >::find_summation()
    {
        this->summation = 0;
        this->already_sum = true;
        for( auto iter = this->begin() ;
                iter != this->end() ; 
                iter++ )
        {
            this->summation += *iter;
        } // loop get summation
    } // function find_summation
    
} // namespace math

} // namespace zeabus
