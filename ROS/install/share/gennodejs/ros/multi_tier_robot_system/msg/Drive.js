// Auto-generated. Do not edit!

// (in-package multi_tier_robot_system.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------

class Drive {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.left = null;
      this.right = null;
      this.left_dir = null;
      this.right_dir = null;
    }
    else {
      if (initObj.hasOwnProperty('left')) {
        this.left = initObj.left
      }
      else {
        this.left = 0;
      }
      if (initObj.hasOwnProperty('right')) {
        this.right = initObj.right
      }
      else {
        this.right = 0;
      }
      if (initObj.hasOwnProperty('left_dir')) {
        this.left_dir = initObj.left_dir
      }
      else {
        this.left_dir = false;
      }
      if (initObj.hasOwnProperty('right_dir')) {
        this.right_dir = initObj.right_dir
      }
      else {
        this.right_dir = false;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type Drive
    // Serialize message field [left]
    bufferOffset = _serializer.uint8(obj.left, buffer, bufferOffset);
    // Serialize message field [right]
    bufferOffset = _serializer.uint8(obj.right, buffer, bufferOffset);
    // Serialize message field [left_dir]
    bufferOffset = _serializer.bool(obj.left_dir, buffer, bufferOffset);
    // Serialize message field [right_dir]
    bufferOffset = _serializer.bool(obj.right_dir, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type Drive
    let len;
    let data = new Drive(null);
    // Deserialize message field [left]
    data.left = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [right]
    data.right = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [left_dir]
    data.left_dir = _deserializer.bool(buffer, bufferOffset);
    // Deserialize message field [right_dir]
    data.right_dir = _deserializer.bool(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 4;
  }

  static datatype() {
    // Returns string type for a message object
    return 'multi_tier_robot_system/Drive';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'cc315fdef9b03fd8f24388694d69978e';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    uint8 left
    uint8 right
    bool left_dir
    bool right_dir
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new Drive(null);
    if (msg.left !== undefined) {
      resolved.left = msg.left;
    }
    else {
      resolved.left = 0
    }

    if (msg.right !== undefined) {
      resolved.right = msg.right;
    }
    else {
      resolved.right = 0
    }

    if (msg.left_dir !== undefined) {
      resolved.left_dir = msg.left_dir;
    }
    else {
      resolved.left_dir = false
    }

    if (msg.right_dir !== undefined) {
      resolved.right_dir = msg.right_dir;
    }
    else {
      resolved.right_dir = false
    }

    return resolved;
    }
};

module.exports = Drive;
