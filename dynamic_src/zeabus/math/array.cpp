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

    template < class data_type >
    Array< data_type >::Array( unsigned int size )
    {
        this->size = size;
        this->address = (data_type*) realloc( size * sizeof( data_type ) );
    }; // constructor function 

    template < class data_type >
    void Array< data_type >::resize( unsigned int size )
    {
        data_type* new_address = (data_type*)realloc( size * sizeof( data_type ) );
        free( this->address );
        this->address = new_address; 
    };

    template< class data_type >
    template< typename vector_type >
    void get_vector( vector_type* vector_address )
    {
        
    };

} // namespace packet

} // namespace zeabus
