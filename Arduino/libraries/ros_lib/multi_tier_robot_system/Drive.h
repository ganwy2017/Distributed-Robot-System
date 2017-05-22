#ifndef _ROS_multi_tier_robot_system_Drive_h
#define _ROS_multi_tier_robot_system_Drive_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace multi_tier_robot_system
{

  class Drive : public ros::Msg
  {
    public:
      typedef uint8_t _left_type;
      _left_type left;
      typedef uint8_t _right_type;
      _right_type right;
      typedef bool _left_dir_type;
      _left_dir_type left_dir;
      typedef bool _right_dir_type;
      _right_dir_type right_dir;
      typedef uint8_t _id_type;
      _id_type id;

    Drive():
      left(0),
      right(0),
      left_dir(0),
      right_dir(0),
      id(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->left >> (8 * 0)) & 0xFF;
      offset += sizeof(this->left);
      *(outbuffer + offset + 0) = (this->right >> (8 * 0)) & 0xFF;
      offset += sizeof(this->right);
      union {
        bool real;
        uint8_t base;
      } u_left_dir;
      u_left_dir.real = this->left_dir;
      *(outbuffer + offset + 0) = (u_left_dir.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->left_dir);
      union {
        bool real;
        uint8_t base;
      } u_right_dir;
      u_right_dir.real = this->right_dir;
      *(outbuffer + offset + 0) = (u_right_dir.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->right_dir);
      *(outbuffer + offset + 0) = (this->id >> (8 * 0)) & 0xFF;
      offset += sizeof(this->id);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->left =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->left);
      this->right =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->right);
      union {
        bool real;
        uint8_t base;
      } u_left_dir;
      u_left_dir.base = 0;
      u_left_dir.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->left_dir = u_left_dir.real;
      offset += sizeof(this->left_dir);
      union {
        bool real;
        uint8_t base;
      } u_right_dir;
      u_right_dir.base = 0;
      u_right_dir.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->right_dir = u_right_dir.real;
      offset += sizeof(this->right_dir);
      this->id =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->id);
     return offset;
    }

    const char * getType(){ return "multi_tier_robot_system/Drive"; };
    const char * getMD5(){ return "62d0da1a5f11f9d7e3811cc797a962f7"; };

  };

}
#endif