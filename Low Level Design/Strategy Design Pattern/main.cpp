#include"vehicle.h"
#include"normalDriveStrategy.h"
#include"sportDriveStrategy.h"

int main(){

    // object created in heap
    DriveStrategy* normal = new NormalDriveStrategy();
    Vehicle myVehical;
    myVehical.setDriveStrategy(normal);
    myVehical.drive();
    delete normal;

    // object created in stack
    SportDriveStrategy sport;
    myVehical.setDriveStrategy(&sport);
    myVehical.drive();

    return 0;
}