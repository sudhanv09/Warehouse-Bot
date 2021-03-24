#include <Arduino.h>
#include <ros.h>
#include <std_msgs/Int16.h>
#include <std_msgs/Float32.h>
#include <actionlib_msgs/GoalStatusArray.h>
#include <sensor_msgs/BatteryState.h>

#define IN1 D9
#define IN2 D10
#define EN1 D11
// change pins
#define IN3 D8
#define IN4 D7
#define EN2 D4

#define ENCA_1 D3
#define ENCB_1 D2
// change pins
#define ENCA_2 D1
#define ENCB_2 D0

int left_pos = 0;
int right_pos = 0;
int lmotor_pwm = 0;
int rmotor_pwm = 0;
int robot_state;


ros::NodeHandle nh;
std_msgs::Int16 leftencoder_msg;
std_msgs::Int16 rightencoder_msg;
std_msgs::Float32 lmotor_cmd;
std_msgs::Float32 rmotor_cmd;
actionlib_msgs::GoalStatusArray robot_status;

void lmotor_cmd_cb(const std_msgs::Float32 &cmd)
{
  lmotor_pwm = cmd.data;
}

void rmotor_cmd_cb(const std_msgs::Float32 &cmd)
{
  rmotor_pwm = cmd.data;
}

void getGoalStatus(const actionlib_msgs::GoalStatusArray &cmd)
{
  robot_state = cmd.status_list->status;
}

void readLeftEncoder()
{
  int lenc_val = digitalRead(ENCB_1);
  if (lenc_val > 0)
  {
    left_pos++;
  }
  else
  {
    left_pos--;
  }
}

void readRightEncoder()
{
  int renc_val = digitalRead(ENCB_2);
  if (renc_val > 0)
  {
    right_pos++;
  }
  else
  {
    right_pos--;
  }
}

void runMotor(int lmotor_pwm, int rmotor_pwm)
{
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(EN1, lmotor_pwm);
  delay(10);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(EN2, rmotor_pwm);
  delay(10);
}

void scissorMotor()
{

}

void gripper()
{

}

ros::Publisher lencoder_adv("left_wheel", &leftencoder_msg);
ros::Publisher rencoder_adv("right_wheel", &rightencoder_msg);
ros::Subscriber<std_msgs::Float32> lcmd_in("lmotor_cmd", &lmotor_cmd_cb);
ros::Subscriber<std_msgs::Float32> rcmd_in("rmotor_cmd", &rmotor_cmd_cb);
ros::Subscriber<actionlib_msgs::GoalStatusArray> robot_state("/move_base/status", &getGoalStatus);

void setup()
{
  // put your setup code here, to run once:
  pinInit();

  nh.initNode();
  nh.advertise(lencoder_adv);
  nh.subscribe(lcmd_in);

  nh.advertise(rencoder_adv);
  nh.subscribe(rcmd_in);
}

void loop()
{
  // put your main code here, to run repeatedly:
  leftencoder_msg.data = left_pos;
  lencoder_adv.publish(&leftencoder_msg);
  rightencoder_msg.data = right_pos;
  rencoder_adv.publish(&rightencoder_msg);

  runMotor(lmotor_pwm, rmotor_pwm);

  if (robot_state == 3) 
  {
    
  }

  nh.spinOnce();
}

void pinInit()
{

pinMode(ENCA_1, INPUT);
pinMode(ENCB_1, INPUT);
pinMode(ENCA_2, INPUT);
pinMode(ENCB_2, INPUT);
pinMode(IN1, OUTPUT);
pinMode(IN2, OUTPUT);
pinMode(EN1, OUTPUT);
pinMode(IN3, OUTPUT);
pinMode(IN4, OUTPUT);
pinMode(EN2, OUTPUT);

attachInterrupt(digitalPinToInterrupt(ENCA_1), readLeftEncoder, RISING);
attachInterrupt(digitalPinToInterrupt(ENCA_2), readRightEncoder, RISING);
}


