cmake_minimum_required( VERSION 2.8.3 )
project( zeabus_library )

find_package( catkin REQUIRED COMPONENTS 
    roscpp
    rospy
    geometry_msgs
    sensor_msgs
    tf
    roslib
)

find_package( Boost REQUIRED COMPONENTS )
find_package( zeabus_utility REQUIRED COMPONENTS )

set( SHARED_LIBS
    SynchronousPort
    ImuConnector
    Convert
    File
    Ahrs
)

set( ROS_LIBS
    Ros
    RosConvert
)

set( zeabus_library_include_path 
    "${PROJECT_SOURCE_DIR}/include"
)

set( zeabus_library_dynamic_source
    "${PROJECT_SOURCE_DIR}/dynamic_src"
)

catkin_package(
    INCLUDE_DIRS ${zeabus_library_include_path} ${zeabus_library_dynamic_source}
    LIBRARIES ${SHARED_LIBS} ${ROS_LIBS}
    CATKIN_DEPENDS zeabus_utility roscpp tf sensor_msgs geometry_msgs
    DEPENDS Boost
)

catkin_python_setup()

set( CMAKE_CXX_FLAGS "-Wall -std=c++14")

include_directories(
    "${zeabus_library_include_path}"
    "${zeabus_library_dynamic_source}"
    ${Boost_INCLUDE_DIR}
    ${catkin_INCLUDE_DIRS}
)

add_subdirectory( static_src/zeabus )
