#include <cstdint>
#include <iostream>

class RadioBaseStation;
class RadioBaseStationImpl;

class Phone{
public:
unsigned int phoneNumber;
RadioBaseStation* rbs = nullptr;
virtual void call() = 0;
Phone(unsigned int phoneNumber): phoneNumber {phoneNumber}{}
virtual void attach(RadioBaseStation* RBS){
    rbs = RBS;
}
virtual void detach(RadioBaseStation* rbs){
    rbs = nullptr;
}
virtual void sendSMS(const std::string& msg, unsigned int pNumber){}
virtual void receiveSMS(unsigned int pNumber){}
virtual unsigned int getPhoneNumber() {return phoneNumber;}
virtual ~Phone() = default;
};