#include <cstdint>
#include <iostream>
#include <unordered_map>
#include <string>

using phone_number=unsigned int;
class Phone;


class RadioBaseStationImpl : public RadioBaseStation {
public:
std::unordered_map<phone_number, Phone*> attachedPhones;
std::unordered_map<phone_number, std::string> messages;
virtual void notifyUser(const std::string& msg, unsigned int pNumber){
    messages [pNumber] = msg;
    attachedPhones[pNumber]->receiveSMS(msg, pNumber);
}
virtual void attachPhone(Phone* phone){
    attachedPhones [phone->phoneNumber] = phone;
}
virtual void showmessage(unsigned int pNumber){
    std::cout << messages [pNumber];
}
~RadioBaseStationImpl()=default;
RadioBaseStationImpl()=default;

};