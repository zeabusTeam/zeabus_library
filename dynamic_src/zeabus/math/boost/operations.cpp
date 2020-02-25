// FILE			: operations.cpp
// AUTHOR		: K.Supasan
// CREATE ON	: 2019, Febuary 24 (UTC+0)
// MAINTAINER	: K.Supasan

// MACRO DETAIL

// README

// REFERENCE

// MACRO SET

// MACRO CONDITION

namespace zeabus_boost
{
    template< typename T , int R , int C >
    inline void mat_concat( boost::qvm::mat< T , R * 2 , C >* target ,
            const boost::qvm::mat< T , R , C > source1,
            const boost::qvm::mat< T , R , C > source2 )
    {
        std::memcpy( (void*)&(target->a[0][0]), (void*)&(source1.a[0][0]), sizeof( double )*R*C);
        std::memcpy( (void*)&(target->a[R][0]), (void*)&(source2.a[0][0]), sizeof( double )*R*C);
    }
}
