/**
 * Description: 发布消息
 * version: v1.0
 * Author: HTY
 * Date: 2022-12-11 20:03:53 
 */

#include <ecal/ecal.h>
#include <ecal/msg/string/publisher.h>

#include <iostream>
#include <thread>

int main(int argc, char* argv[])
{
    eCAL::Initialize(argc, argv, "Hello World Publisher");
    eCAL::string::CPublisher<std::string> publisher("hello_world_topic");

    int counter = 0;
    while(eCAL::Ok())
    {
        std::string message = "Hello World " + std::to_string(++counter);
        std::cout << "Sending message: " + message << std::endl;
        publisher.Send(message);
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }

    eCAL::Finalize();
    return 0;
}