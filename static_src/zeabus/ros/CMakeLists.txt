add_library( Ros SHARED
    node.cpp
)

target_link_libraries( Ros
    ${catkin_LIBRARIES}
)

add_subdirectory( convert )
