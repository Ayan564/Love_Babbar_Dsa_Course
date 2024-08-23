#if !defined(EMAIL_ALART_OBSERVER_H)
#define EMAIL_ALART_OBSERVER_H

#include "notificationAlartObserver.h"
#include <string>
#include <iostream>

class emailAlartObserver : public notificationAlartObserver {
private:
    std::string email; // Recipient email address

public:
    emailAlartObserver(const std::string& email) : email(email) {}

    void update() override {
        // Handle the email notification
        std::cout << "Sending email to " << email << ": The stock count has changed!" << std::endl;
    }

};

#endif // EMAIL_ALART_OBSERVER_H