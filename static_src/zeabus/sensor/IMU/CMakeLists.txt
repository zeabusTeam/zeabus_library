add_library( ImuConnector SHARED
    connector.cpp
)

target_link_libraries( ImuConnector 
    SynchronousPort
    ${Boost_LIBRARIES} 
)
