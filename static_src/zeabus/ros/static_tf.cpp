// FILE			: static_tf.cpp
// AUTHOR		: K.Supasan
// CREATE ON	: 2019, Febuary 06 (UTC+0)
// MAINTAINER	: K.Supasan

// MACRO DETAIL

// README

// REFERENCE

// MACRO SET

// MACRO CONDITION

#include    <zeabus/ros/static_tf.hpp>

namespace zeabus_ros
{

    StaticTF::StaticTF()
    {
        this->size = 0;
    } // construct StaticTf

    StaticTF::~StaticTF()
    {
        try
        {
            this->thread_id.join();
        }
        catch ( const std::exception& e )
        {
            ;
        }
    } // construct ~StaticTF

    bool StaticTF::setup( zeabus::FileCSV* ptr_file )
    {
        this->ptr_file = ptr_file;
        unsigned int count_column = 0;
        bool success = this->ptr_file->count_column( &count_column );
        if( success && count_column == 8 )
        {
            success = this->ptr_file->count_line( &( this->size ) );
        } // That mean file you correctly format
        else
        {
            success = false;
        }
        return success;
    } // function setup csv file or will setup data for transform

    void StaticTF::spin( double rate )
    {
        (void)extract_csv_type_8( this->ptr_file , this->frame_id , this->child_frame ,
                this->translation_x , this->translation_y , this->translation_z ,
                this->rotation_x , this->rotation_y , this->rotation_z );

        this->report_information();

        free( this->tf_message );
        this->tf_message = ( geometry_msgs::TransformStamped* ) malloc( sizeof( 
                geometry_msgs::TransformStamped ) * this->size );

        for( unsigned int run = 0 ; run < this->size ; run++ )
        {
            this->tf_message[ run ].header.frame_id = this->frame_id[ run ];
            this->tf_message[ run ].child_frame_id = this->child_frame[ run ];
            this->tf_message[ run ].transform.translation.x = this->translation_x[ run ];
            this->tf_message[ run ].transform.translation.y = this->translation_y[ run ];
            this->tf_message[ run ].transform.translation.z = this->translation_z[ run ];
            this->tf_message[ run ].transform.rotation.x = this->rotation_x[ run ];
            this->tf_message[ run ].transform.rotation.y = this->rotation_y[ run ];
            this->tf_message[ run ].transform.rotation.z = this->rotation_z[ run ];
        }

        this->thread_id = std::thread( &zeabus_ros::StaticTF::broadcast , this , rate );

    } // function spin static tf broadcast data

    void StaticTF::broadcast( double value_rate )
    {
        ros::Rate rate( value_rate );
        while( ros::ok() )
        {
            this->stamp = ros::Time::now();
            for( unsigned int run = 0 ; run < this->size ; run++ )
            {
                this->tf_message[ run ].header.stamp = this->stamp;
                this->broadcaster.sendTransform( this->tf_message[ run ] );
            }
            rate.sleep();
        }
    } // broadcaster

    void StaticTF::report_information()
    {
        printf( "Static Transformation %2d data\n" , this->size );
        printf( "Frame_id      -->Child Frame   |   x   |   y   |   z   |   r   |   p   |  yaw\n" );
        for( unsigned int run = 0 ; run < this->size ; run++ )
        {
            printf("%12s-->%12s| %4.2f | %4.2f | %4.2f | %4.2f | %4.2f | %4.2f\n" , 
                    this->frame_id[ run ].c_str() , this->child_frame[ run ].c_str() ,
                    this->translation_x[run] , this->translation_y[run] , this->translation_z[run] ,
                    this->rotation_x[run] , this->rotation_y[run] , this->rotation_z[run] );
        }
    } // report_information
    
} // namespace zeabus_ros
