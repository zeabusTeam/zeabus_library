// FILE			: base_class.cpp
// AUTHOR		: K.Supasan
// CREATE ON	: 2019, October 24 (UTC+0)
// MAINTAINER	: K.Supasan

// MACRO DETAIL

// README

// REFERENCE

// MACRO SET

// MACRO CONDITION

namespace zeabus_ros
{

namespace subscriber
{

    template< class data_type >
    BaseClass< data_type >::BaseClass( ros::NodeHandle* ptr_node_handle , data_type* ptr_data )
    {
        this->ptr_node_handle = ptr_node_handle;
        this->ptr_data = ptr_data;
    } // function constructor

    template< class data_type >
    BaseClass< data_type >::BaseClass()
    {
        std::cout   << "Warning You don't setup node_handle and ptr_data exactly\n";
    } // function constructor

    template< class data_type >
    void BaseClass< data_type >::setup_base( ros::NodeHandle* ptr_node_handle , data_type* ptr_data){
        this->ptr_node_handle = ptr_node_handle;
        this->ptr_data = ptr_data;
    } // function setup after constructor

    template< class data_type >
    void BaseClass< data_type >::callback( const data_type& message )
    {
#ifdef _SHOW_CALLBACK_
        std::cout   << "Callback receive message\n";
#endif // _SHOW_CALLBACK_

        this->ptr_mutex_data->lock();
        *( this->ptr_data ) = message;
        this->ptr_mutex_data->unlock();
    } // function callback

    template< class data_type >
    void BaseClass< data_type >::callback_timestamp( const data_type& message )
    {
#ifdef _SHOW_CALLBACK_
        std::cout   << "Callback Timestamp receive message\n";
#endif // _SHOW_CALLBACK_

        this->ptr_mutex_data->lock();
        *( this->ptr_data ) = message;
        this->ptr_data->header.stamp = ros::Time::now();
        this->ptr_mutex_data->unlock();
    } // function callback

    template< class data_type >
    void BaseClass< data_type >::setup_mutex_data( std::mutex* ptr_mutex_data )
    {   
        this->ptr_mutex_data = ptr_mutex_data;
    } // function setup_mutex_data

    template< class data_type >
    void BaseClass< data_type >::setup_subscriber( std::string topic , unsigned int queue_size )
    {
        this->subscribe_server = this->ptr_node_handle->subscribe( topic, 
                queue_size, 
                &zeabus_ros::subscriber::BaseClass< data_type >::callback,
                this );
    } // function setup_subscriber

    template< class data_type >
    void BaseClass< data_type >::setup_subscriber_timestamp( std::string topic, 
            unsigned int queue_size )
    {
        this->subscribe_server = this->ptr_node_handle->subscribe( topic, 
                queue_size, 
                &zeabus_ros::subscriber::BaseClass< data_type >::callback_timestamp,
                this );
    } // function setup_subscriber
} // namespace subscriber

} // namespace zeabus_ros
