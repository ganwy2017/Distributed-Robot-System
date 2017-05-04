/*
 * Author: Samuel Westlake, Plymouth University, 2017
 * Email: samuelwestlake@hotmail.co.uk
 * 
 * This program will publish data in cm from three sonar devices 
 * This program subscribes to a message called drive from a buggy and uses this to control two motors 
 * 
 * Todo: drive must be unique to control multiple buggies... 
 */

#include <ros.h>
#include <std_msgs/Int64.h>

// Custom libraries
#include <buggy_project/Drive.h>
#include <UltraSound.h>

// Define pins for motor control
#define brakePinL 8
#define brakePinR 9
#define dirPinL   13
#define dirPinR   12
#define drivePinL 11
#define drivePinR 3

// Define sonar pins 
#define trigPin1 4
#define echoPin1 5
#define trigPin2 6
#define echoPin2 7
#define trigPin3 2
#define echoPin3 10

void driveCallback(const buggy_project::Drive& drive_msg)
{
  int left = drive_msg.left;
  int right = drive_msg.right;
  int leftDir = HIGH;
  int rightDir = HIGH;
  if (left < 0){
    left *= -1;
    int leftDir = LOW;
  }
  if (right < 0){
    right *= -1;
    int rightDir = LOW;
  }
  digitalWrite(dirPinL, leftDir);
  digitalWrite(dirPinR, rightDir);
  analogWrite(drivePinL, leftDir);
  analogWrite(drivePinR, rightDir);
}

// Init ROS node
ros::NodeHandle nh;

// Init Subscriber                                                            
ros::Subscriber <buggy_project::Drive> subDrive("drive", driveCallback);  

// Init ROS messages     
std_msgs::Int32 sonarMessage1;    
std_msgs::Int32 sonarMessage2;    
std_msgs::Int32 sonarMessage3; 

// Init ROS publishers
ros::Publisher pubSonar1("buggy0/sonar0", &sonarMessage1);                             
ros::Publisher pubSonar2("buggy0/sonar1", &sonarMessage2);
ros::Publisher pubSonar3("buggy0/sonar2", &sonarMessage3);
 
// Create sonar objects  
UltraSound sonar1(trigPin1, echoPin1);                                         
UltraSound sonar2(trigPin2, echoPin2);
UltraSound sonar3(trigPin3, echoPin3);

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
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  pinMode(trigPin3, OUTPUT);
  pinMode(echoPin3, INPUT);

  // Initialise values for motor pins
  digitalWrite(brakePinR, LOW);
  digitalWrite(dirPinL, HIGH);
  digitalWrite(brakePinR, LOW);
  digitalWrite(dirPinR, HIGH);
  
  nh.initNode();
  nh.subscribe(subDrive);
  nh.advertise(pubSonar1);
  nh.advertise(pubSonar2);
  nh.advertise(pubSonar3);
}

void loop()
{
  int pingTime1;
  int dist1;   
  int pingTime2;
  int dist2;
  int pingTime3;
  int dist3;
  
  nh.spinOnce();

  pingTime1 = sonar1.ping();
  pingTime2 = sonar2.ping();
  pingTime3 = sonar3.ping();
  
  dist1 = sonar1.centimetersInAir(pingTime1);
  dist2 = sonar2.centimetersInAir(pingTime2);
  dist3 = sonar3.centimetersInAir(pingTime3);

  sonarMessage1.data = dist1;  
  sonarMessage2.data = dist2;  
  sonarMessage3.data = dist3;  

  pubSonar1.publish(&sonarMessage1);
  pubSonar2.publish(&sonarMessage2);
  pubSonar3.publish(&sonarMessage3);
  
  delay(1);
}
