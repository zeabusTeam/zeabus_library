add_library( Ros SHARED
    node.cpp
    path_file.cpp
)

target_link_libraries( Ros
    ${catkin_LIBRARIES}
)

add_subdirectory( convert )
