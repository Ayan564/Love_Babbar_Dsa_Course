#if !defined(VEHICLE_H)
#define VEHICLE_H
#include "driveStrategy.h"

class Vehicle
{
    private:
    DriveStrategy *strategy; //  pointer to the strategy

    public:
    
    // constructor injection
    void setDriveStrategy(DriveStrategy* newStrategy) {
        strategy = newStrategy;
    }

    void drive() {
        strategy->drive();  // Delegate to the strategy
    }

    ~Vehicle() {
        delete strategy;  // Clean up the strategy if dynamically allocated
    }
};

#endif // VEHICLE_H