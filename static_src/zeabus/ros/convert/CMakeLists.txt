add_library( RosConvert SHARED 
    sensor_imu.cpp
    geometry_vector3.cpp
    geometry_quaternion.cpp
)

target_link_libraries( RosConvert
    ${catkin_LIBRARIES}
    Convert # Because we use library zeabus/convert bytes to float
)
