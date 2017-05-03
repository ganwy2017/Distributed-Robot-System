#ifndef _ROS_laptop_node_drive_h
#define _ROS_laptop_node_drive_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace laptop_node
{

  class drive : public ros::Msg
  {
    public:
      typedef uint8_t _driveL_type;
      _driveL_type driveL;
      typedef uint8_t _driveR_type;
      _driveR_type driveR;
      typedef bool _dirL_type;
      _dirL_type dirL;
      typedef bool _dirR_type;
      _dirR_type dirR;

    drive():
      driveL(0),
      driveR(0),
      dirL(0),
      dirR(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->driveL >> (8 * 0)) & 0xFF;
      offset += sizeof(this->driveL);
      *(outbuffer + offset + 0) = (this->driveR >> (8 * 0)) & 0xFF;
      offset += sizeof(this->driveR);
      union {
        bool real;
        uint8_t base;
      } u_dirL;
      u_dirL.real = this->dirL;
      *(outbuffer + offset + 0) = (u_dirL.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->dirL);
      union {
        bool real;
        uint8_t base;
      } u_dirR;
      u_dirR.real = this->dirR;
      *(outbuffer + offset + 0) = (u_dirR.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->dirR);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->driveL =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->driveL);
      this->driveR =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->driveR);
      union {
        bool real;
        uint8_t base;
      } u_dirL;
      u_dirL.base = 0;
      u_dirL.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->dirL = u_dirL.real;
      offset += sizeof(this->dirL);
      union {
        bool real;
        uint8_t base;
      } u_dirR;
      u_dirR.base = 0;
      u_dirR.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->dirR = u_dirR.real;
      offset += sizeof(this->dirR);
     return offset;
    }

    const char * getType(){ return "laptop_node/drive"; };
    const char * getMD5(){ return "49712a8add5ad45f0375cddf5b3665cb"; };

  };

}
#endif