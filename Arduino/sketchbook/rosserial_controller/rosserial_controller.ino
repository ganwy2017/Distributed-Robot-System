/*
 * Author: Samuel Westlake, Plymouth University, 2017
 * Email: samuelwestlake@hotmail.co.uk
 * 
 * This program will publish data in cm from three sonar devices 
 * This program subscribes to a message called drive from a buggy and uses this to control two motors 
 */

// Third party pibraries
#include <ros.h>
#include <std_msgs/Int32.h>

// Custom libraries
#include <UltraSound.h>
#include <Drive.h>

// Define pins for motor control
#define brakePinL 8
#define brakePinR 9
#define dirPinL   13
#define dirPinR   12
#define drivePinL 11
#define drivePinR 3

// Define sonar pins 
#define trigPin0 4
#define echoPin0 5
#define trigPin1 6
#define echoPin1 7
#define trigPin2 2
#define echoPin2 10
#define trigPin3 A4
#define echoPin3 A5
#define trigPin4 A2
#define echoPin4 A3

// Counter for safe-guarding against disconnection
// If counter falls to zero, motors will stop
int counter = 0;    

void driveCallback(const multi_tier_robot_system::Drive& message)
{
    digitalWrite(dirPinL, message.left_dir);
    digitalWrite(dirPinR, message.right_dir);
    analogWrite(drivePinL, message.left);
    analogWrite(drivePinR, message.right);
    counter = 10;   
}

void publishSonar(UltraSound& sonar, ros::Publisher& pub, std_msgs::Int32& message)
{
  int pingTime = sonar.ping();                            // Ping sonar device                     
  int distance = sonar.centimetersInAir(pingTime);        // Convert ping time into distnace
  message.data = distance;                                // Set message data to distance value
  pub.publish(&message);                                  // Publish sonar data
}

// Init ROS node
ros::NodeHandle nh;

// Init Subscriber                                                            
ros::Subscriber <multi_tier_robot_system::Drive> subDrive("buggy0/drive", driveCallback);

// Init ROS messages     
std_msgs::Int32 sonarMessage0;    
std_msgs::Int32 sonarMessage1;    
std_msgs::Int32 sonarMessage2;
std_msgs::Int32 sonarMessage3;    
std_msgs::Int32 sonarMessage4;  

// Init ROS publishers
ros::Publisher pubSonar0("buggy0/sonar0", &sonarMessage0);                             
ros::Publisher pubSonar1("buggy0/sonar1", &sonarMessage1);
ros::Publisher pubSonar2("buggy0/sonar2", &sonarMessage2);
ros::Publisher pubSonar3("buggy0/sonar3", &sonarMessage3);
ros::Publisher pubSonar4("buggy0/sonar4", &sonarMessage4);
 
// Create sonar objects  
UltraSound sonar0(trigPin0, echoPin0);                                         
UltraSound sonar1(trigPin1, echoPin1);
UltraSound sonar2(trigPin2, echoPin2);
UltraSound sonar3(trigPin3, echoPin3);                                         
UltraSound sonar4(trigPin4, echoPin4);

void setup()
{
  // Set pin modes for motors
  pinMode(brakePinL, OUTPUT);
  pinMode(dirPinL, OUTPUT);
  pinMode(drivePinL, OUTPUT);
  pinMode(brakePinR, OUTPUT);
  pinMode(dirPinR, OUTPUT);
  pinMode(drivePinR, OUTPUT);

  // Set pin modes for sonar devices
  pinMode(trigPin0, OUTPUT);
  pinMode(echoPin0, INPUT);
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  pinMode(trigPin3, OUTPUT);
  pinMode(echoPin3, INPUT);
  pinMode(trigPin4, OUTPUT);
  pinMode(echoPin4, INPUT);

  // Initialise values for motor pins
  digitalWrite(brakePinR, LOW);
  digitalWrite(dirPinL, HIGH);
  digitalWrite(brakePinR, LOW);
  digitalWrite(dirPinR, HIGH);
  
  nh.initNode();
  nh.subscribe(subDrive);       
  nh.advertise(pubSonar0);
  nh.advertise(pubSonar1);
  nh.advertise(pubSonar2);
  nh.advertise(pubSonar3);
  nh.advertise(pubSonar4);
}

void loop()
{  
  nh.spinOnce();

  // Get and publish data for each sonar device
  publishSonar(sonar0, pubSonar0, sonarMessage0); 
  publishSonar(sonar1, pubSonar1, sonarMessage1);
  publishSonar(sonar2, pubSonar2, sonarMessage2);
  publishSonar(sonar3, pubSonar3, sonarMessage3);
  publishSonar(sonar4, pubSonar4, sonarMessage4);
  if (counter > 0) 
  {
    counter -= 1;
  }
  else 
  {
    analogWrite(drivePinL, 0);
    analogWrite(drivePinR, 0); 
  }
  delay(1);
}
