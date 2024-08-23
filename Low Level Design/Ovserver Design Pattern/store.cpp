#include "Observable/stocksObservable.h"
#include "Observable/iphoneObservable.h"
#include "Observer/notificationAlartObserver.h"
#include "Observer/emailAlartObserver.h"
#include "Observer/mobileAlartObserver.h"

int main() {
    // Step 1: Create iPhoneObservable object
    stocksObservable *iPhoneStockObservable = new iPhoneObservable();

    // Step 2: Create observer objects
    notificationAlartObserver *observer1 = new emailAlartObserver("ayan564@gmail.com");
    notificationAlartObserver *observer2 = new emailAlartObserver("ayan564@gmail.com");
    notificationAlartObserver *observer3 = new mobileAlartObserver("+123456789");

    // Step 3: Add observers to the iPhoneObservable object
    iPhoneStockObservable->add(observer1);  // Use arrow operator to call member function
    iPhoneStockObservable->add(observer2);  // Use arrow operator to call member function
    iPhoneStockObservable->add(observer3);  // Use arrow operator to call member function

    // Step 4: Update stock count and notify observers
    iPhoneStockObservable->setStockCount(100);  // Use arrow operator to call member function

    // Remove one observer (email) and update stock count again
    iPhoneStockObservable->remove(observer1);  // Use arrow operator to call member function
    iPhoneStockObservable->setStockCount(50);  // Use arrow operator to call member function

    // Clean up memory
    delete iPhoneStockObservable;
    delete observer1;
    delete observer2;
    delete observer3;

    return 0;
}
