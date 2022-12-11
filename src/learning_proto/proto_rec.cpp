/**
 * Description:
 * version: v1.0
 * Author: HTY
 * Date: 2022-12-11 21:26:39 
 */

#include "Person.pb.h"

#include <ecal/ecal.h>
#include <ecal/msg/protobuf/subscriber.h>

#include <iostream>
#include <thread>


void CustomProtobufCallback(const proto_messages::Person & msg)
{
    std::cout << "Received message:\n ";
    std::cout << "name: " << msg.name() << std::endl;
    std::cout << "id: " << msg.id() << std::endl;
    std::cout << "message: " << msg.msg() << std::endl;
    std::cout << std::endl;
}

int main(int argc, char* argv[])
{
    eCAL::Initialize(argc, argv, "Custom Protobuf Subscriber");
    eCAL::protobuf::CSubscriber<proto_messages::Person> subscriber("custom_protobuf_topic");
    subscriber.AddReceiveCallback(std::bind(&CustomProtobufCallback, std::placeholders::_2));

    while (eCAL::Ok())
    {
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    eCAL::Finalize();
    return 0;
}