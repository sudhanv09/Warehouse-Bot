#!/usr/bin/env python

import rospy
from geometry_msgs.msg import Twist, Point
from nav_msgs.msg import Odometry

x = 0.0
y = 0.0

def odomCb(msg):
    global x
    global y

    x = msg.pose.pose.position.x
    y = msg.pose.pose.position.y


rospy.init_node("controller")

sub = rospy.Subscriber("/husky_velocity_controller/odom", Odometry, odomCb)
pub = rospy.Publisher(
    "/husky_velocity_controller/cmd_vel", Twist, queue_size=1)

speed = Twist()
rate = rospy.Rate(10)

goal = Point()
goal.x = 5.0
goal.y = 0.0

while not rospy.is_shutdown():
    rob_x = goal.x - x
    rob_y = goal.y - y

    speed.linear.x = 0.5

    pub.publish(speed)
    rate.sleep()
