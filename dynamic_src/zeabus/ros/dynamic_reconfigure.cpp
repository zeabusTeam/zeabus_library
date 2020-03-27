// FILE			: dynamic_reconfigure.cpp
// AUTHOR		: K.Supasan
// CREATE ON	: 2020, March 24 (UTC+0)
// MAINTAINER	: K.Supasan

// MACRO DETAIL

// README

// REFERENCE

// MACRO SET

// MACRO CONDITION

namespace zeabus_ros
{
    template< class config_type >
    DynamicReconfigureServer< config_type >::DynamicReconfigureServer( 
            config_type* ptr_default_config )
    {
        this->ptr_default_config = ptr_default_config;
    }

    template< class config_type >
    void DynamicReconfigureServer< config_type >::setup_variable( config_type* ptr_config_data,
            std::mutex* ptr_lock_data,
            int* ptr_level_data )
    {
        this->ptr_config_data = ptr_config_data;
        this->ptr_level_data = ptr_level_data;
        this->ptr_lock_data = ptr_lock_data;
    }

    template< class config_type >
    void DynamicReconfigureServer< config_type >::spin()
    {
        dynamic_reconfigure::Server< config_type >::CallbackType function_reconfigure = 
                boost::bind( &(this->callback) , _1 , _2 );
        this->server_reconfigure.setCallback( function_reconfigure );
    }

    template< class config_type >
    void DynamicReconfigureServer< config_type >::callback( config_type& config , uint32_t level )
    {
        int level_data = (int)level;
        if( level_data == -1 )
        {
            this->ptr_lock_data->lock();
            *( this->ptr_level_data ) = 0;
            *( this->ptr_config_data ) = *( this->ptr_default_config );
            this->ptr_lock_data->unlock();
        }
        else
        {
            this->ptr_lock_data->lock();
            *( this->ptr_level_data ) = level_data;
            *( this->ptr_config_data ) = config;
            this->ptr_lock_data->unlock();
        }
    }
}
