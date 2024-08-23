#include"vehicle.h"
#include"normalDriveStrategy.h"
#include"sportDriveStrategy.h"

int main(){

    // Using constructor injection method
    // object created in heap
    DriveStrategy* normal = new NormalDriveStrategy();
    Vehicle myVehicalNormal(normal);
    myVehicalNormal.drive();
    delete normal;
    // object created in stack
    SportDriveStrategy sport;
    Vehicle myVehicalSport(&sport);
    myVehicalSport.drive();

    // // Using setter method
    // // object created in stack
    // Vehicle myVehical;
    // NormalDriveStrategy normal;
    // myVehical.setDriveStrategy(&normal);
    // myVehical.drive();
    // // object created in heap
    // DriveStrategy* sport = new SportDriveStrategy();
    // myVehical.setDriveStrategy(sport);
    // myVehical.drive();

    return 0;
}