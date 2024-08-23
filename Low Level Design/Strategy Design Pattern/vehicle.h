#if !defined(VEHICLE_H)
#define VEHICLE_H
#include "driveStrategy.h"

class Vehicle
{
    private:
    DriveStrategy *strategy; //  pointer to the strategy

    public:

    Vehicle() : strategy(nullptr) {}  // Constructor initializes with nullptr

    // Constructor Injection: The strategy is provided during object creation
    Vehicle(DriveStrategy* newStrategy) : strategy(newStrategy) {}
    
    // Setter Method (Not Constructor Injection)
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