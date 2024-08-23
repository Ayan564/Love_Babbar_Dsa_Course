#if !defined(SPORT_DRIVE_STRATEGY_H)
#define SPORT_DRIVE_STRATEGY_H

#include"driveStrategy.h"
#include<iostream>

class NormalDriveStrategy : public DriveStrategy
{
    public:
    void drive() override
    {
        std::cout << "Normal drive capebility." << std::endl;
    }
};


#endif // SPORT_DRIVE_STRATEGY_H

