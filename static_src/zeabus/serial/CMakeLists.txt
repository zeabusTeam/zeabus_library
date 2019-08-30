add_library( SynchronousPort SHARED
    base_class.cpp
)

target_link_libraries( SynchronousPort ${Boost_LIBRARIES} )
