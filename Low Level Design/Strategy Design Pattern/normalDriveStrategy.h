#if !defined(NORMAL_DRIVE_STRATTEGY_H)
#define NORMAL_DRIVE_STRATTEGY_H
#include"driveStrategy.h"
#include<iostream>

class SportDriveStrategy : public DriveStrategy
{
    public:
    void drive() override
    {
        std::cout << "Sports drive capebility." << std::endl;
    }
};


#endif // NORMAL_DRIVE_STRATTEGY_H
