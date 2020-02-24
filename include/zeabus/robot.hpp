// FILE			: robot.hpp
// AUTHOR		: K.Supasan
// CREATE ON	: 2020, January 22 (UTC+0)
// MAINTAINER	: K.Supasan

// MACRO DETAIL

// README

// REFERENCE
//  ref01 : https://www.boost.org/doc/libs/1_72_0/libs/qvm/doc/html/index.html#vec

// MACRO SET

// MACRO CONDITION

#include    <cmath>

#include    <boost/qvm/vec.hpp>

#include    <boost/qvm/vec_access.hpp>

#include    <boost/qvm/vec_operations.hpp>

#include    <boost/qvm/mat.hpp>

#include    <boost/qvm/mat_operations.hpp>

#include    <zeabus/math/parameter.hpp>

#ifndef _ZEABUS_ROBOT_HPP__
#define _ZEABUS_ROBOT_HPP__

const static double cos45 = cos( 45.0 * zeabus::math::PI / 180.0 );
const static double sin45 = sin( 45.0 * zeabus::math::PI / 180.0 );

namespace zeabus
{

namespace robot
{

    const static double gravity = 9.806;

    const static double mass = 35.5;

    const static double volumn = 0.04;

    const static double rho_water = 1027.0;

    const static boost::qvm::vec< double , 3 > distance_center_gravity = { 0.0 , 0.0 , 0.08 };

    const static boost::qvm::vec< double , 3 > distance_center_buoncy = { 0.0 , 0.0 , 0.1 };

    const static boost::qvm::vec< double , 3 > direction_linear_force[ 8 ] = { 
        { 0 , 0 , 1 },
        { 0 , 0 , 1 },
        { 0 , 0 , 1 },
        { 0 , 0 , 1 },
        { cos45 , -1*sin45 , 0 },
        { cos45 , sin45 , 0 },
        { -1*cos45 , -1*sin45 , 0 },
        { -1*cos45 , sin45 , 0 }
    };

    const static boost::qvm::vec< double , 3 > distance[ 8 ] = {
        { 0.44 , 0.32 , -0.023 },
        { 0.44 , -0.32 ,-0.023 },
        { -0.44 , 0.32 , -0.023 },
        { -0.44 , -0.32, -0.023 },
        {0.46 , 0.34 , -0.023 },
        {0.46 , -0.34 , -0.023 },
        {-0.46 , 0.34 , -0.023 },
        {-0.46 , -0.34 , -0.023 }
    };

    const static boost::qvm::vec< double , 3 > direction_moment[ 8 ] = {
        boost::qvm::cross( direction_linear_force[ 0 ] , distance[ 0 ] ),
        boost::qvm::cross( direction_linear_force[ 1 ] , distance[ 1 ] ),
        boost::qvm::cross( direction_linear_force[ 2 ] , distance[ 2 ] ),
        boost::qvm::cross( direction_linear_force[ 3 ] , distance[ 3 ] ),
        boost::qvm::cross( direction_linear_force[ 4 ] , distance[ 4 ] ),
        boost::qvm::cross( direction_linear_force[ 5 ] , distance[ 5 ] ),
        boost::qvm::cross( direction_linear_force[ 6 ] , distance[ 6 ] ),
        boost::qvm::cross( direction_linear_force[ 7 ] , distance[ 7 ] ),
    };

    const static boost::qvm::mat< double , 8 , 6 > direction_all = {
        boost::qvm::A< 0 >( direction_linear_force[ 0 ] ),        
        boost::qvm::A< 1 >( direction_linear_force[ 0 ] ),        
        boost::qvm::A< 2 >( direction_linear_force[ 0 ] ),        
        boost::qvm::A< 0 >(       direction_moment[ 0 ] ),        
        boost::qvm::A< 1 >(       direction_moment[ 0 ] ),        
        boost::qvm::A< 2 >(       direction_moment[ 0 ] ),        
        boost::qvm::A< 0 >( direction_linear_force[ 1 ] ),        
        boost::qvm::A< 1 >( direction_linear_force[ 1 ] ),        
        boost::qvm::A< 2 >( direction_linear_force[ 1 ] ),        
        boost::qvm::A< 0 >(       direction_moment[ 1 ] ),        
        boost::qvm::A< 1 >(       direction_moment[ 1 ] ),        
        boost::qvm::A< 2 >(       direction_moment[ 1 ] ),        
        boost::qvm::A< 0 >( direction_linear_force[ 2 ] ),        
        boost::qvm::A< 1 >( direction_linear_force[ 2 ] ),        
        boost::qvm::A< 2 >( direction_linear_force[ 2 ] ),        
        boost::qvm::A< 0 >(       direction_moment[ 2 ] ),        
        boost::qvm::A< 1 >(       direction_moment[ 2 ] ),        
        boost::qvm::A< 2 >(       direction_moment[ 2 ] ),        
        boost::qvm::A< 0 >( direction_linear_force[ 3 ] ),        
        boost::qvm::A< 1 >( direction_linear_force[ 3 ] ),        
        boost::qvm::A< 2 >( direction_linear_force[ 3 ] ),        
        boost::qvm::A< 0 >(       direction_moment[ 3 ] ),        
        boost::qvm::A< 1 >(       direction_moment[ 3 ] ),        
        boost::qvm::A< 2 >(       direction_moment[ 3 ] ),        
        boost::qvm::A< 0 >( direction_linear_force[ 4 ] ),        
        boost::qvm::A< 1 >( direction_linear_force[ 4 ] ),        
        boost::qvm::A< 2 >( direction_linear_force[ 4 ] ),        
        boost::qvm::A< 0 >(       direction_moment[ 4 ] ),        
        boost::qvm::A< 1 >(       direction_moment[ 4 ] ),        
        boost::qvm::A< 2 >(       direction_moment[ 4 ] ),        
        boost::qvm::A< 0 >( direction_linear_force[ 5 ] ),        
        boost::qvm::A< 1 >( direction_linear_force[ 5 ] ),        
        boost::qvm::A< 2 >( direction_linear_force[ 5 ] ),        
        boost::qvm::A< 0 >(       direction_moment[ 5 ] ),        
        boost::qvm::A< 1 >(       direction_moment[ 5 ] ),        
        boost::qvm::A< 2 >(       direction_moment[ 5 ] ),        
        boost::qvm::A< 0 >( direction_linear_force[ 6 ] ),        
        boost::qvm::A< 1 >( direction_linear_force[ 6 ] ),        
        boost::qvm::A< 2 >( direction_linear_force[ 6 ] ),        
        boost::qvm::A< 0 >(       direction_moment[ 6 ] ),        
        boost::qvm::A< 1 >(       direction_moment[ 6 ] ),        
        boost::qvm::A< 2 >(       direction_moment[ 6 ] ),        
        boost::qvm::A< 0 >( direction_linear_force[ 7 ] ),        
        boost::qvm::A< 1 >( direction_linear_force[ 7 ] ),        
        boost::qvm::A< 2 >( direction_linear_force[ 7 ] ),        
        boost::qvm::A< 0 >(       direction_moment[ 7 ] ),        
        boost::qvm::A< 1 >(       direction_moment[ 7 ] ),        
        boost::qvm::A< 2 >(       direction_moment[ 7 ] ) 
    };

} // namespace robot

} // namespace zeabus

#endif
