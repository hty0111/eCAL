/**
 * Description: 发布自定义消息类型
 * version: v1.0
 * Author: HTY
 * Date: 2022-12-11 21:26:02 
 */

#include "Person.pb.h"

#include <ecal/ecal.h>
#include <ecal/msg/protobuf/publisher.h>

#include <iostream>
#include <thread>

int main(int argc, char* argv[])
{
    eCAL::Initialize(argc, argv, "Custom Protobuf Publisher");
    eCAL::protobuf::CPublisher<proto_messages::Person> publisher("custom_protobuf_topic");

    std::string name = "HTY";
    int id = 0;
    std::string msg = "learning eCAL";

    while(eCAL::Ok())
    {
        proto_messages::Person person_msg;
        person_msg.set_name(name);
        person_msg.set_id(++id);
        person_msg.set_msg(msg);
        publisher.Send(person_msg);
        std::cout << "Sent message.\n";

        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    eCAL::Finalize();
    return 0;
}