#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char type[20];
    char brand[20];
    int maxSpeed;
    float weight;
} Vehicle;

int main()
{
    int count;
    printf("Enter the number of vehicles: ");
    scanf("%d", &count);
    Vehicle *vehicles = (Vehicle *)malloc(count * sizeof(Vehicle));

    for (int i = 0; i < count; i++)
    {
        printf("\nVehicle #%d\n", i + 1);
        printf("Enter type: ");
        scanf("%s", vehicles[i].type);
        printf("Enter brand: ");
        scanf("%s", vehicles[i].brand);
        printf("Enter maximum speed: ");
        scanf("%d", &vehicles[i].maxSpeed);
        printf("Enter weight: ");
        scanf("%f", &vehicles[i].weight);
    }

    Vehicle fastest = vehicles[0];
    for (int i = 1; i < count; i++)
    {
        if (vehicles[i].maxSpeed > fastest.maxSpeed)
        {
            fastest = vehicles[i];
        }
    }

    printf("\nThe fastest vehicle is: %s (%s) with a speed of %d km/h\n", fastest.type, fastest.brand, fastest.maxSpeed);

    free(vehicles);

    return 0;
}
