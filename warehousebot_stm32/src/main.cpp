#include "ros/ros.h"
#include "std_msgs/Int16.h"

#define ENCA 3
#define ENCB 2

int left_pos = 0;
int right_pos = 0;

ros::NodeHandle nh;
std_msgs::Int16 leftencoder_msg;
//std_msgs::Int16 rightencoder_msg;
ros::Publisher pub_leftencoder("left_wheel", &leftencoder_msg);
//ros::Publisher pub_rightencoder("right_wheel", &rightencoder_msg);

void readLeftEncoder()
{
    int leftencoderValue = digitalRead(ENCB);
    if (leftencoderValue > 0)
    {
        left_pos++;
    }
    else
    {
        left_pos--;
    }
}

void readRighttEncoder()
{
    int rightencoderValue = digitalRead(ENCB); // change pin
    if (rightencoderValue > 0)
    {
        right_pos++;
    }
    else
    {
        right_pos--;
    }
}

void setup()
{
    pinMode(ENCA, INPUT);
    pinMode(ENCB, INPUT);
    attachInterrupt(digitalPinToInterrupt(ENCA), readLeftEncoder, RISING);

    nh.initNode();
    nh.advertise(pub_leftencoder);
    //nh.advertise(pub_rightencoder);
}

void loop()
{
    leftencoder_msg.data = left_pos;
    //rightencoder_msg.data = readRighttEncoder(ENCB);

    pub_leftencoder.publish(&leftencoder_msg);
    //pub_rightencoder.publish(&rightencoder_msg);

    nh.spinOnce();
}
