#include <cstdint>
#include <iostream>
#include <unordered_map>
#include "phone.h"
#include "RadioBaseStation.h"
#include "RadioBaseStationImpl.h"

class Iphone : public Phone {
public:
virtual void call(){
std::cout << "Calling from Iphone";
}
Iphone(unsigned int phoneNumber): Phone {phoneNumber}{}
virtual void sendSMS(const std::string& msg, unsigned int pNumber){
    rbs->notifyUser(msg, pNumber);
}
virtual void receiveSMS(const std::string& msg, unsigned int pNumber){
    std::cout << msg << std::endl;
}
virtual void attach(RadioBaseStation* RBS){
    rbs = RBS;
    rbs->attachPhone(this);
}
virtual void detach(RadioBaseStation* rbs){
    rbs = nullptr;
}
};

class Samsung : public Phone {
public:
virtual void call(){
std::cout << "Calling from Samsung";
}
Samsung(unsigned int phoneNumber): Phone {phoneNumber}{}
virtual void sendSMS(const std::string& msg, unsigned int pNumber){
    rbs->notifyUser(msg, pNumber);
}
virtual void receiveSMS(const std::string& msg, unsigned int pNumber){
    std::cout << msg << std::endl;
}
virtual void attach(RadioBaseStation* RBS){
    rbs = RBS;
    rbs->attachPhone(this);
}
virtual void detach(RadioBaseStation* rbs){
    rbs = nullptr;
}
};

enum class PhoneType : uint8_t {
    Iphone,
    Samsung,
};

class SmartphoneManufacture {

private:
    static SmartphoneManufacture* instance;
    SmartphoneManufacture() = default;
    ~SmartphoneManufacture() = default;
public:
    SmartphoneManufacture(const SmartphoneManufacture&) = delete;
    SmartphoneManufacture& operator=(const SmartphoneManufacture&) = delete;
    static SmartphoneManufacture* getInstance(){
        if ( !instance ){
            instance = new SmartphoneManufacture();
        }
        return instance;
    }
    Phone* create(PhoneType type, unsigned int phoneNumber){
        switch(type){
        case PhoneType::Iphone: 
            return new Iphone(phoneNumber);
            break;
        
        case PhoneType::Samsung:
            return new Samsung(phoneNumber);
            break;
            default:
            return 0;
        }
    }
};
SmartphoneManufacture* SmartphoneManufacture::instance;

int main(){

SmartphoneManufacture* first = SmartphoneManufacture::getInstance();

Phone* i10 = first->create(PhoneType::Iphone, 132468321);

RadioBaseStationImpl one;
//i10->rbs = &one;


Phone* s20 = first->create(PhoneType::Samsung, 445684321);
s20->call();
std::cout << std::endl;
i10->call();
i10->attach(&one);
s20->attach(&one);

std::cout << std::endl;
i10->sendSMS("testowa wiadomosc", 445684321);
delete i10;
delete s20;

i10=nullptr;
s20=nullptr;

    return 0;
}

// 1.  Write class Phone with abstract method call().
// 2.  Write class Iphone which implements class Phone.
//     In method call print string "Calling from Iphone"
// 3.  Write class Samsung which implements class Phone.
//     In method call print string "Calling from Samsung"
// 4.  Create Enum Class (size uint8_t) PhoneType with two values:
//     Iphone and Samsung
// 5.  Write class SmartphoneManufacture. This class should be singleton
//     Classical implementation you can find here: https://www.modernescpp.com/index.php/creational-patterns-singleton
//     In this class create method Phone* create(PhoneType type).
//     This method should return Iphone or Samsung depends on value passed to this function
// 6.  In main function create SmarthoneManufacture, create 2 different phones and make calls on them.

//---------------------------------------------------------------------------------------------------------
// 7.  Change SmartphoneManufacture::create method to use switch instead of if statements.
// 8.  Add to Phone class method attach(RadioBaseStation* rbs)
// 9.  Add to Phone class method detach(RadioBaseStation* rbs)
// 11. Add to Phone class method sendSMS(const std::string& msg, unsigned int pNumber)
// 12. Add to Phone class method receiveSMS(const std::string& msg, unsigned int pNumber)
// 13. Add to Phone class atribute RadioBaseStation* rbs ptr (default value nullptr)
// 14. Add to Phone class atribute unsigned int phoneNumber (create constructor in which you will provide this number) and proper getter for this atribute;
// 15. Create class RadioBaseStation and RadioBaseStationImpl with fuction notifyUser(const std::string& msg, unsigned int pNumber) (ofc in RadioBaseStattion method should be = 0)
// 16. In class RadioBaseStationImpl create atribute std::unordered_map<unsinged int, Phone*> attachedPhones (key is phone number)
// 17. In classes RadioBaseStation and RadioBaseStationImpl create method attachPhone(Phone* phone)
// 18. By using above methods create functionality to send SMS from one phone to other one. Use algorithm library to find proper phone by key