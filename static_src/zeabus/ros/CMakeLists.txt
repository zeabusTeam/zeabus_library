add_library( Ros SHARED
    node.cpp
)

target_link_libraries( Ros
    ${Boost_LIBRARIES}
)
