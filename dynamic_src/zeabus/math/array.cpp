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
    Array< vector_type >::Array( unsigned int size , vector_type init_value ) : BaseClass()
    {
        this->vector.assign( size , init_value );
        this->already_sum = true;
        this->summation = init_value * size ;
    } // function Constructor Array

    template< class vector_type >
    void stable_sort( std::vector< vector_type >* ptr_vector )
    {
        std::vector< vector_type > temp_vector( this->begin() , this->last() );
        std::stable_sort( temp_vector.begin() , temp_vector.end() );
        ptr_vector->swap( temp_vector );
        delete temp_vector;
        
    } // function sort

    template< class vector_type >
    double get_sum( bool sum_again )
    {
        if( sum_again || !( this->already_sum ) )
        {
            this->find_summation();
        } // condition have to find again 
        return this->summation;
    } // function get_sum

    template< class vector_type >
    double get_mean()
    {
        return this->summation / this->size();
    } // function get_mean

    template< class vector_type >
    double get_variance()
    {
        double temporary = 0;
        (void)this->get_sum();
        for( std::vector< vector_type >::iterator iter = this->begin() ;
                iter != this->end() ;
                iter++ )
        {
            temporary += pow( ( *iter ) - this->summation , 2 );
        }
        return temporary / this->size;
    } // function get_variance

    template< class vector_type >
    void find_summation()
    {
        this->summation = 0;
        this->already_sum = true;
        for( std::vector< vector_type >::iterator iter = this->begin() ;
                iter != this->end() ; 
                iter++ )
        {
            this->summation += *iter;
        } // loop get summation
    } // function find_summation
    

} // namespace packet

} // namespace zeabus
