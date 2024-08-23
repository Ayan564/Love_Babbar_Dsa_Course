#if !defined(STOCKS_OBSERVABLE_H)
#define STOCKS_OBSERVABLE_H
#include"../Observer/notificationAlartObserver.h"

class stocksObservable {
    public:
    // this is the interface
    virtual void add(notificationAlartObserver* observer) = 0;
    virtual void remove(notificationAlartObserver* observer) = 0;
    virtual void notifySubscribers() = 0;
    virtual void setStockCount(int newStockAdded) = 0;
    virtual int getStockCount() const = 0;
};

#endif // STOCKS_OBSERVABLE_H