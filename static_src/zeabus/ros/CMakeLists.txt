add_library( Ros SHARED
    node.cpp
    path_file.cpp
    dynamic_reconfigure.cpp
)

target_link_libraries( Ros
    ${catkin_LIBRARIES}
)

add_subdirectory( convert )

add_library( RosHandle SHARED
    static_tf.cpp
)

target_link_libraries( RosHandle 
    ${catkin_LIBRARIES}
    RosConvert
    File
    Ros
)
