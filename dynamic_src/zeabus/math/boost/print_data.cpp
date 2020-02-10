// FILE			: print_data.cpp
// AUTHOR		: K.Supasan
// CREATE ON	: 2019, Febuary 10 (UTC+0)
// MAINTAINER	: K.Supasan

// MACRO DETAIL

// README

// REFERENCE

// MACRO SET

// MACRO CONDITION

namespace zeabus_boost
{

    template< class T , int R , int C >
    void print( const boost::qvm::mat< T , R , C > data )
    {
        for( int row = 0 ; row < R ; row++ )
        {
            printf("\t");
            for( int column = 0 ; column < C ; column++ )
            {
                printf( "%8.3f " , (double) data.a[ row ][ column ] );
            }
            printf("\n");
        }
    }

    template< class T , int S >
    void print( const boost::qvm::vec< T , S > data )
    {
        printf( "\t");
        for( int size = 0 ; size < S ; size++ )
        {
            printf( "%8.3f " , (double) data.a[ size ] );
        }
        printf("\n");
    }
}
