#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/joint_state.hpp"

using namespace std::chrono_literals;

std::vector<std::string> joint_names = {
    "HeadYaw",
    "HeadPitch",
    "LShoulderPitch",
    "LShoulderRoll",
    "LElbowYaw",
    "LElbowRoll",
    "LWristYaw",
    "LHipYawPitch",
    "LHipRoll",
    "LHipPitch",
    "LKneePitch",
    "LAnklePitch",
    "LAnkleRoll",
    "RHipRoll",
    "RHipPitch",
    "RKneePitch",
    "RAnklePitch",
    "RAnkleRoll",
    "RShoulderPitch",
    "RShoulderRoll",
    "RElbowYaw",
    "RElbowRoll",
    "RWristYaw",
    "LHand",
    "RHand",
};

class ZeroJointStatePublisher : public rclcpp::Node
{
public:
    ZeroJointStatePublisher() : Node("ZeroJointStatePublisher")
    {
        publisher_ = this->create_publisher<sensor_msgs::msg::JointState>("/joint_states", 10);
        timer_ = this->create_wall_timer(
            500ms, std::bind(&ZeroJointStatePublisher::timer_callback, this));

        for (std::string joint : joint_names)
        {
            state.name.push_back(joint);
            state.position.push_back(0);
        }
    }

private:
    void timer_callback()
    {
        RCLCPP_INFO(this->get_logger(), "Publishing zero state");

        state.header.stamp = now();
        publisher_->publish(state);
    }

    rclcpp::TimerBase::SharedPtr timer_;
    rclcpp::Publisher<sensor_msgs::msg::JointState>::SharedPtr publisher_;

    sensor_msgs::msg::JointState state;
};

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<ZeroJointStatePublisher>());
    rclcpp::shutdown();
    return 0;
}