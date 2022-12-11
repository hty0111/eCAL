/**
 * Description: 接收消息
 * version: v1.0
 * Author: HTY
 * Date: 2022-12-11 20:36:58 
 */

#include <ecal/ecal.h>
#include <ecal/msg/string/subscriber.h>

#include <iostream>
#include <thread>

void HelloWorldCallback(const std::string & msg)
{
    std::cout << "Received message " + msg << std::endl;
}

int main(int argc, char* argv[])
{
    eCAL::Initialize(argc, argv, "Hello World Subscriber");
    eCAL::string::CSubscriber<std::string> subscriber("hello_world_topic");
    subscriber.AddReceiveCallback(std::bind(&HelloWorldCallback, std::placeholders::_2));

    while (eCAL::Ok())
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }

    eCAL::Finalize();
    return 0;
}