#include <string>

class Phone;

class RadioBaseStation {
public:
virtual void attachPhone(Phone* phone){}
virtual void notifyUser(const std::string& msg, unsigned int pNumber){}
virtual void showmessage(unsigned int pNumber){}
virtual ~RadioBaseStation()=default;
};