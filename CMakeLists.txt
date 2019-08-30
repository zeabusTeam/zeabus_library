cmake_minimum_required( VERSION 2.8.3 )
project( zeabus_library )

find_package( catkin REQUIRED COMPONENTS )

find_package( Boost REQUIRED COMPONENTS )
find_package( zeabus_utility REQUIRED COMPONENTS )

set( SHARED_LIBS
    SynchronousPort
)

set( zeabus_library_include_path 
    "${PROJECT_SOURCE_DIR}/include"
)

set( zeabus_library_dynamic_source
    "${PROJECT_SOURCE_DIR}/dynamic_src/zeabus"
)

catkin_package(
    INCLUDE_DIRS ${zeabus_library_include_path}
    LIBRARIES ${SHARED_LIBS}
    CATKIN_DEPENDS zeabus_utility roscpp tf
    DEPENDS Boost
)

set( CMAKE_CXX_FLAGS "-Wall -std=c++14")

include_directories(
    "${zeabus_library_include_path}"
    "${zeabus_library_dynamic_source}"
    ${Boost_INCLUDE_DIR}
    ${catkin_INCLUDE_DIRS}
)

add_subdirectory( static_src/zeabus )
