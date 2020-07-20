#include "ros/ros.h"
#include "ros_tutorials_service/SrvTutorial.h"

#define PLUS 1
#define MINUS 2 
#define MULTIPLICATION 3
#define DIVSION 4

bool calculation(ros_tutorials_service::SrvTutorial::Request &req,
  ros_tutorials_service::SrvTutorial::Response &res)
{
  switch(req.operation)
  {
    case PLUS:
    res.result = req.a + req.b;break;
    case MINUS:
    res.result = req.a - req.b;break;
    case MULTIPLICATION:
    res.result = req.a * req.b;break;
    case DIVSION:
    if (req.b == 0)
    {
      res.result = 0; break;
    }
    else
    {
      res.result = req.a / req.b;break;
    }
    default:
    res.result = req.a + req.b;break;
  }

  ROS_INFO("Request:x = %ld, y = %ld", (long int) req.a, (long int) req.b);
  ROS_INFO("req.operation = %ld", req.operation);
  ROS_INFO("sending back response:%ld", (long int) res.result);

  return true;
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "service_server");
  ros::NodeHandle nh;
  ros::ServiceServer ros_tutorials_service_server = nh.advertiseService("ros_tutorial_srv",calculation);
  ROS_INFO("read srv serer!");
  ros::Rate r(10);
  while(1)
  {
    ros::spinOnce();
    r.sleep();
  }
  return 0;
}