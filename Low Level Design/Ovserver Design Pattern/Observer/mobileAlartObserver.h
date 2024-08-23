#if !defined(MOBILE_ALAER_OBSERVER_H)
#define MOBILE_ALAER_OBSERVER_H

#include "notificationAlartObserver.h"
#include <string>
#include <iostream>

class mobileAlartObserver : public notificationAlartObserver {
private:
    std::string phoneNumber; // Phone number
    
public:
    // Constructor injection for phone number
    mobileAlartObserver(const std::string& phoneNumber) 
        : phoneNumber(phoneNumber) {}

    // Override update method
    void update() override {
        std::cout << "Sending SMS to " << phoneNumber << ": The stock count has changed!" << std::endl;
    }

};

#endif // MOBILE_ALAER_OBSERVER_H