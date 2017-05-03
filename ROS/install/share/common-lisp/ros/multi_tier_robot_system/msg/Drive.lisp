; Auto-generated. Do not edit!


(cl:in-package multi_tier_robot_system-msg)


;//! \htmlinclude Drive.msg.html

(cl:defclass <Drive> (roslisp-msg-protocol:ros-message)
  ((left
    :reader left
    :initarg :left
    :type cl:fixnum
    :initform 0)
   (right
    :reader right
    :initarg :right
    :type cl:fixnum
    :initform 0)
   (left_dir
    :reader left_dir
    :initarg :left_dir
    :type cl:boolean
    :initform cl:nil)
   (right_dir
    :reader right_dir
    :initarg :right_dir
    :type cl:boolean
    :initform cl:nil))
)

(cl:defclass Drive (<Drive>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <Drive>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'Drive)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name multi_tier_robot_system-msg:<Drive> is deprecated: use multi_tier_robot_system-msg:Drive instead.")))

(cl:ensure-generic-function 'left-val :lambda-list '(m))
(cl:defmethod left-val ((m <Drive>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader multi_tier_robot_system-msg:left-val is deprecated.  Use multi_tier_robot_system-msg:left instead.")
  (left m))

(cl:ensure-generic-function 'right-val :lambda-list '(m))
(cl:defmethod right-val ((m <Drive>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader multi_tier_robot_system-msg:right-val is deprecated.  Use multi_tier_robot_system-msg:right instead.")
  (right m))

(cl:ensure-generic-function 'left_dir-val :lambda-list '(m))
(cl:defmethod left_dir-val ((m <Drive>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader multi_tier_robot_system-msg:left_dir-val is deprecated.  Use multi_tier_robot_system-msg:left_dir instead.")
  (left_dir m))

(cl:ensure-generic-function 'right_dir-val :lambda-list '(m))
(cl:defmethod right_dir-val ((m <Drive>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader multi_tier_robot_system-msg:right_dir-val is deprecated.  Use multi_tier_robot_system-msg:right_dir instead.")
  (right_dir m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <Drive>) ostream)
  "Serializes a message object of type '<Drive>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'left)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'right)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'left_dir) 1 0)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'right_dir) 1 0)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <Drive>) istream)
  "Deserializes a message object of type '<Drive>"
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'left)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'right)) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'left_dir) (cl:not (cl:zerop (cl:read-byte istream))))
    (cl:setf (cl:slot-value msg 'right_dir) (cl:not (cl:zerop (cl:read-byte istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<Drive>)))
  "Returns string type for a message object of type '<Drive>"
  "multi_tier_robot_system/Drive")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'Drive)))
  "Returns string type for a message object of type 'Drive"
  "multi_tier_robot_system/Drive")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<Drive>)))
  "Returns md5sum for a message object of type '<Drive>"
  "cc315fdef9b03fd8f24388694d69978e")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'Drive)))
  "Returns md5sum for a message object of type 'Drive"
  "cc315fdef9b03fd8f24388694d69978e")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<Drive>)))
  "Returns full string definition for message of type '<Drive>"
  (cl:format cl:nil "uint8 left~%uint8 right~%bool left_dir~%bool right_dir~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'Drive)))
  "Returns full string definition for message of type 'Drive"
  (cl:format cl:nil "uint8 left~%uint8 right~%bool left_dir~%bool right_dir~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <Drive>))
  (cl:+ 0
     1
     1
     1
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <Drive>))
  "Converts a ROS message object to a list"
  (cl:list 'Drive
    (cl:cons ':left (left msg))
    (cl:cons ':right (right msg))
    (cl:cons ':left_dir (left_dir msg))
    (cl:cons ':right_dir (right_dir msg))
))
