#include <Arduino.h>
#include <ros.h>
#include <std_msgs/Int16.h>
#include <std_msgs/Float32.h>

// left motor - 1
#define IN1 PB3
#define IN2 PB5
#define EN1 PB14
// right motor - 2
#define IN3 PB4
#define IN4 PB10
#define EN2 PB13
// encoder pins
#define ENCA_1 PA5
#define ENCB_1 PA6
#define ENCA_2 PA1
#define ENCB_2 PA0

int left_pos = 0;
int right_pos = 0;
int lmotor_pwm = 0;
int rmotor_pwm = 0;
int state;

ros::NodeHandle nh;
std_msgs::Int16 leftencoder_msg;
std_msgs::Int16 rightencoder_msg;
std_msgs::Float32 lmotor_cmd;
std_msgs::Float32 rmotor_cmd;

void lmotor_cmd_cb(const std_msgs::Float32 &cmd)
{
  lmotor_pwm = cmd.data;
}

void rmotor_cmd_cb(const std_msgs::Float32 &cmd)
{
  rmotor_pwm = cmd.data;
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

void runMotor()
{
  if (lmotor_pwm > 0)
  {
    if (rmotor_pwm > 0)
    {
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      analogWrite(EN1, lmotor_pwm);
      // delay(10);

      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);
      analogWrite(EN2, rmotor_pwm);
    }
    else
    {
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      analogWrite(EN1, lmotor_pwm);
      // delay(10);

      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);
      analogWrite(EN2, rmotor_pwm);
    }
  }

  else
  {
    if (rmotor_pwm > 0)
    {
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      analogWrite(EN1, lmotor_pwm);
      // delay(10);

      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);
      analogWrite(EN2, rmotor_pwm);
    }

    else
    {
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      analogWrite(EN1, lmotor_pwm);
      // delay(10);

      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);
      analogWrite(EN2, rmotor_pwm);
    }
  }
}

ros::Publisher lencoder_adv("left_wheel", &leftencoder_msg);
ros::Publisher rencoder_adv("right_wheel", &rightencoder_msg);
ros::Subscriber<std_msgs::Float32> lcmd_in("lmotor_cmd", &lmotor_cmd_cb);
ros::Subscriber<std_msgs::Float32> rcmd_in("rmotor_cmd", &rmotor_cmd_cb);

void setup()
{
  // put your setup code here, to run once:
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

  runMotor();

  nh.spinOnce();
}
