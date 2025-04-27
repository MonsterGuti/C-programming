#include <stdio.h>

struct Vehicle
{
    char name[50];
    char type[50];
    float maxSpeed;
    float weight;
    int capacity;

};

struct Car
{
    struct Vehicle vehicleInfo;
    int numDoors;
    int enginePower;
};

struct Motorcycle {
    struct Vehicle vehicleInfo;
    int numWheels;
    int engineCapacity;
};

struct Boat {
    struct Vehicle vehicleInfo;
    float length;
    int numEngines;
};

struct Airplane {
    struct Vehicle vehicleInfo;
    int numEngines;
    float wingSpan;
};

int main()
{
    struct Car car = {{"Mercedes clk 320", "Car", 244, 1500, 4}, 2, 3200};
    struct Motorcycle motorcycle = {{"Harley Davidson", "Motorcycle", 180.0, 300.0, 2}, 2, 1200};
    struct Boat boat = {{"Speedboat", "Boat", 80.0, 500.0, 4}, 8.5, 2};
    struct Airplane airplane = {{"Boeing 747", "Airplane", 900.0, 180000.0, 400}, 4, 60.0};

    printf("Comparison of maximum speeds:\n");
    printf("Car: %s - %.2f km/h\n", car.vehicleInfo.name, car.vehicleInfo.maxSpeed);
    printf("Motorcycle: %s - %.2f km/h\n", motorcycle.vehicleInfo.name, motorcycle.vehicleInfo.maxSpeed);
    printf("Boat: %s - %.2f km/h\n", boat.vehicleInfo.name, boat.vehicleInfo.maxSpeed);
    printf("Airplane: %s - %.2f km/h\n", airplane.vehicleInfo.name, airplane.vehicleInfo.maxSpeed);

    if (car.vehicleInfo.maxSpeed > motorcycle.vehicleInfo.maxSpeed && 
        car.vehicleInfo.maxSpeed > boat.vehicleInfo.maxSpeed && 
        car.vehicleInfo.maxSpeed > airplane.vehicleInfo.maxSpeed) {
        printf("The fastest vehicle is: %s (Car)\n", car.vehicleInfo.name);
    } else if (motorcycle.vehicleInfo.maxSpeed > car.vehicleInfo.maxSpeed && 
               motorcycle.vehicleInfo.maxSpeed > boat.vehicleInfo.maxSpeed && 
               motorcycle.vehicleInfo.maxSpeed > airplane.vehicleInfo.maxSpeed) {
        printf("The fastest vehicle is: %s (Motorcycle)\n", motorcycle.vehicleInfo.name);
    } else if (boat.vehicleInfo.maxSpeed > car.vehicleInfo.maxSpeed && 
               boat.vehicleInfo.maxSpeed > motorcycle.vehicleInfo.maxSpeed && 
               boat.vehicleInfo.maxSpeed > airplane.vehicleInfo.maxSpeed) {
        printf("The fastest vehicle is: %s (Boat)\n", boat.vehicleInfo.name);
    } else {
        printf("The fastest vehicle is: %s (Airplane)\n", airplane.vehicleInfo.name);
    }

    return 0;
}