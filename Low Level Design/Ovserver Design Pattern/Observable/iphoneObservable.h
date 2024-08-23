#if !defined(IPHONE_OBSERVABLE_H)
#define IPHONE_OBSERVABLE_H

#include "../Observer/notificationAlartObserver.h"
#include "stocksObservable.h"
#include <vector>
#include <algorithm>

class iPhoneObservable : public stocksObservable {
public:
    std::vector<notificationAlartObserver*> observers; // List of observers
    int stockCount = 0; // Current stock count
    // Add an observer to the list
    void add(notificationAlartObserver* observer) override {
        observers.push_back(observer);
    }

    // Remove an observer from the list
    void remove(notificationAlartObserver* observer) override {
        observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
    }

    // Notify all observers of the stock count change
    void notifySubscribers() override {
        for (auto observer : observers) {
            observer->update();
        }
    }

    // Set a new stock count and notify observers
    void setStockCount(int newStockCount) override {
        if(stockCount == 0){
        notifySubscribers();
        }
        stockCount += newStockCount;
    }

    // Get the current stock count
    int getStockCount() const override {
        return stockCount;
    }


};

#endif // IPHONE_OBSERVABLE_H
