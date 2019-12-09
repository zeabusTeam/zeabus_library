// FILE			: outliner.cpp
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

namespace filter
{

    template< class vector_type , unsigned int size_array >
    Outliner< vector_type , size_array >::Outliner( vector_type init_value ) 
            : Array( size_array , init_value )
    {
        this->set_cut_size( 1 );
        this->run_pos = 0;
    } // function constructor

    template< class vector_type , unsigned int size_array >
    void Outliner< vector_type , size_array >::set_cut_size( unsigned int cut_size )
    {
        this->cut_size = cut_size;
    } // function set_cut_size

    template< class vector_type , unsigned int size_array >
    double Outliner< vector_type , size_array >::get_result()
    {
        std::vector< vector_type >* ptr_vector;
        this->stable_sort( ptr_vector );

        std::vector< vector_type >::iterator iter_start = ptr_vector->begin();
        std::vector< vector_type >::iterator iter_end = ptr_vector->end();
        double answer = this->summation;
        for( unsigned int run = 0 ; run < this->cut_size ; run++ )
        {
            answer -= *iter_start;
            answer -= *iter_end;
            iter_start++;
            iter_end++;
        } 
        return answer / ( this->size - ( this->cut_size * 2 ) );
    } // function get_result

    template< class vector_type , unsigned int size_array >
    void Outliner< vector_type , size_array >::push_data( vector_type value )
    {
        this->summation -= (*this)[ this->run_pos ];
        (*this)[ this->run_pos ] = value:
        this->summation += value;
        this->move_posiion();
    } // function push_data

    template< class vector_type , unsigned int size_array >
    void Outliner< vector_type , size_array >::move_position()
    {
        this->run_pos += 1;
        this->run_pos %= size_array;
    } // function move_position

} // namespace filter

} // namespace zeabus

