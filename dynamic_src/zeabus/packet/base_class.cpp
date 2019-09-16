// FILE			: base_class.cpp
// AUTHOR		: K.Supasan
// CREATE ON	: 2019, September 11 (UTC+0)
// MAINTAINER	: K.Supasan

// MACRO DETAIL

// README

// REFERENCE

// MACRO SET

// MACRO CONDITION

namespace zeabus
{

namespace packet
{

    template< class vector_type >
    BaseClass< vector_type >::BaseClass(){} // init constuctor don't do anything

    template< class vector_type >
    BaseClass< vector_type >::~BaseClass()
    {
        this->clear();
        this->fit_memory();
    } // deconstructor

    template< class vector_type >
    void BaseClass< vector_type >::print_memory()
    {
        std::cout   << "size : capacity are ";
        std::cout.width(5);
        std::cout   << this->vector.size() << " : " << this->vector.capacity() << "\n";
        std::cout.width(0);
    } // BaseClass< vector_type >::print_memory

    template< class vector_type >
    void BaseClass< vector_type >::fit_memory()
    {
        this->vector.shrink_to_fit();
    } // BaseClass< vector_type >::fit_memory

    template< class vector_type >
    void BaseClass< vector_type >::resize( unsigned int size )
    {
        this->vector.resize( size );
    } // BaseClass< vector_type >::resize   

    template< class vector_type >
    void BaseClass< vector_type >::reserve( unsigned int size )
    {
        this->vector.reserve( size );
    } // BaseClass< vector_type >::reserve

    template< class vector_type >
    void BaseClass< vector_type >::clear()
    {
        this->vector.clear();
    } // BaseClass< vector_type >::clear

    template< class vector_type >
    void BaseClass< vector_type >::print_data_hex( std::string message )
    {
        std::cout   << message << std::hex;
        for( auto it = this->vector.begin() ; it != this->vector.end() ; it++ )
        {
            std::cout   << unsigned( *it ) << ' ';
        }
        std::cout   << "\n" << std::dec ;
    }

    template< class vector_type >
    void BaseClass< vector_type >::print_data( std::string message )
    {
        std::cout   << message;
        for( auto it = this->vector.begin() ; it != this->vector.end() ; it++ )
        {
            std::cout << *it << ' ';
        } // loop print
        std::cout   << "\n";
    } // BaseClass< vector_type >::print_data

    template< class vector_type >
    void BaseClass< vector_type >::push( vector_type data )
    {
        this->vector.push_back( data );
    } // BaseClass< vector_type >::push

    template< class vector_type >
    template< typename... pack_type >
    void BaseClass< vector_type >::push( vector_type data , pack_type... pack )
    {
        this->push( data );
        this->push( pack... );
    } // BaseClass< vector_type >::push

    template< class vector_type >
    vector_type& BaseClass< vector_type >::operator[]( unsigned int position )
    {
        return this->vector[ position ];
    } // BaseClass< vector_type >::operator[]

    template< class vector_type >
    unsigned int BaseClass< vector_type >::size()
    {
        return this->vector.size();
    } // BaseClass< vector >::size()

    template< class vector_type >
    std::vector< vector_type >* BaseClass<vector_type>::pointer()
    {
        return &( this->vector );
    } // BaseClass< vector_type >::pointer()

    template< class vector_type >
    std::vector< vector_type >::iterator BaseClass< vector_type >::end()
    {
        return this->vector.end();
    }

} // namespace packet

} // namespace zeabus
