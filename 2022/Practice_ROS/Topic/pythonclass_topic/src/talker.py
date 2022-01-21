#!/usr/bin/env python

import rospy
from std_msgs.msg import String

def talker():
    print("ready for talk")
    while not rospy.is_shutdown():
        talker_str = raw_input("input message:")
        print("talker_str is :", talker_str)
        pub.publish(talker_str)
        rate.sleep()

if __name__ == "__main__":
    pub = rospy.Publisher('pythonclass', String, queue_size=10)
    rospy.init_node('talker', anonymous = True, disable_signals = True)
    rate = rospy.Rate(10)
    try:
        talker()
    except KeyboardInterrupt:
        pass
