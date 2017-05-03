;; Auto-generated. Do not edit!


(when (boundp 'multi_tier_robot_system::Drive)
  (if (not (find-package "MULTI_TIER_ROBOT_SYSTEM"))
    (make-package "MULTI_TIER_ROBOT_SYSTEM"))
  (shadow 'Drive (find-package "MULTI_TIER_ROBOT_SYSTEM")))
(unless (find-package "MULTI_TIER_ROBOT_SYSTEM::DRIVE")
  (make-package "MULTI_TIER_ROBOT_SYSTEM::DRIVE"))

(in-package "ROS")
;;//! \htmlinclude Drive.msg.html


(defclass multi_tier_robot_system::Drive
  :super ros::object
  :slots (_left _right _left_dir _right_dir ))

(defmethod multi_tier_robot_system::Drive
  (:init
   (&key
    ((:left __left) 0)
    ((:right __right) 0)
    ((:left_dir __left_dir) nil)
    ((:right_dir __right_dir) nil)
    )
   (send-super :init)
   (setq _left (round __left))
   (setq _right (round __right))
   (setq _left_dir __left_dir)
   (setq _right_dir __right_dir)
   self)
  (:left
   (&optional __left)
   (if __left (setq _left __left)) _left)
  (:right
   (&optional __right)
   (if __right (setq _right __right)) _right)
  (:left_dir
   (&optional __left_dir)
   (if __left_dir (setq _left_dir __left_dir)) _left_dir)
  (:right_dir
   (&optional __right_dir)
   (if __right_dir (setq _right_dir __right_dir)) _right_dir)
  (:serialization-length
   ()
   (+
    ;; uint8 _left
    1
    ;; uint8 _right
    1
    ;; bool _left_dir
    1
    ;; bool _right_dir
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; uint8 _left
       (write-byte _left s)
     ;; uint8 _right
       (write-byte _right s)
     ;; bool _left_dir
       (if _left_dir (write-byte -1 s) (write-byte 0 s))
     ;; bool _right_dir
       (if _right_dir (write-byte -1 s) (write-byte 0 s))
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; uint8 _left
     (setq _left (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; uint8 _right
     (setq _right (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; bool _left_dir
     (setq _left_dir (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;; bool _right_dir
     (setq _right_dir (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;;
   self)
  )

(setf (get multi_tier_robot_system::Drive :md5sum-) "cc315fdef9b03fd8f24388694d69978e")
(setf (get multi_tier_robot_system::Drive :datatype-) "multi_tier_robot_system/Drive")
(setf (get multi_tier_robot_system::Drive :definition-)
      "uint8 left
uint8 right
bool left_dir
bool right_dir

")



(provide :multi_tier_robot_system/Drive "cc315fdef9b03fd8f24388694d69978e")


