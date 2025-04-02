#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_NAME_LENGTH 50

char **flights = NULL;
char **flightStatuses = NULL;
int *passengerCounts = NULL;
char ***passengers = NULL;
char ***passengerStatuses = NULL;
int flightCount = 0;

void printHeader() {
    printf("AIRPORT MANAGEMENT SYSTEM\n");
}

void printMenu() {
    printf("\n  --- MENU ---  \n");
    printf("0. Help\n");
    printf("1. Add Flight\n");
    printf("2. Change Flight Status to Active\n");
    printf("3. Change Flight Status to Completed\n");
    printf("4. Delete Flight\n");
    printf("5. Edit Flight\n");
    printf("6. View Flights\n");
    printf("7. Add Passenger\n");
    printf("8. Change Passenger Status to OnBoard\n");
    printf("9. View Passengers for a Flight\n");
    printf("10. Exit\n");
    printf("Choose an option: ");
}

void printHelp() {
    printf("This program manages flights and passengers.\n");
}

void addFlight() {
    flights = realloc(flights, (flightCount + 1) * sizeof(char *));
    flightStatuses = realloc(flightStatuses, (flightCount + 1) * sizeof(char *));
    passengers = realloc(passengers, (flightCount + 1) * sizeof(char **));
    passengerStatuses = realloc(passengerStatuses, (flightCount + 1) * sizeof(char **));
    passengerCounts = realloc(passengerCounts, (flightCount + 1) * sizeof(int));

    if (!flights || !flightStatuses || !passengers || !passengerStatuses || !passengerCounts) {
        printf("Memory allocation failed!\n");
        return;
    }

    flights[flightCount] = malloc(11 * sizeof(char));
    flightStatuses[flightCount] = malloc(21 * sizeof(char));
    passengers[flightCount] = NULL;
    passengerStatuses[flightCount] = NULL;
    passengerCounts[flightCount] = 0;

    printf("Enter flight number: ");
    fgets(flights[flightCount], 11, stdin);
    flights[flightCount][strcspn(flights[flightCount], "\n")] = 0;
    strcpy(flightStatuses[flightCount], "Planned");

    flightCount++;
    printf("Flight added!\n");
}

void changeFlightStatusToActive() {
    char flightNumber[11];
    printf("Enter flight number: ");
    fgets(flightNumber, sizeof(flightNumber), stdin);
    flightNumber[strcspn(flightNumber, "\n")] = 0;

    for (int i = 0; i < flightCount; i++) {
        if (strcmp(flights[i], flightNumber) == 0) {
            strcpy(flightStatuses[i], "Active");
            printf("Flight status changed to Active!\n");
            return;
        }
    }
    printf("Flight not found.\n");
}

void changeFlightStatusToCompleted() {
    char flightNumber[11];
    printf("Enter flight number: ");
    fgets(flightNumber, sizeof(flightNumber), stdin);
    flightNumber[strcspn(flightNumber, "\n")] = 0;

    for (int i = 0; i < flightCount; i++) {
        if (strcmp(flights[i], flightNumber) == 0) {
            strcpy(flightStatuses[i], "Completed");
            printf("Flight status changed to Completed!\n");
            return;
        }
    }
    printf("Flight not found.\n");
}

void deleteFlight() {
    char flightNumber[11];
    printf("Enter flight number: ");
    fgets(flightNumber, sizeof(flightNumber), stdin);
    flightNumber[strcspn(flightNumber, "\n")] = 0;

    for (int i = 0; i < flightCount; i++) {
        if (strcmp(flights[i], flightNumber) == 0) {
            free(flights[i]);
            free(flightStatuses[i]);

            for (int j = 0; j < passengerCounts[i]; j++) {
                free(passengers[i][j]);
                free(passengerStatuses[i][j]);
            }
            free(passengers[i]);
            free(passengerStatuses[i]);

            for (int j = i; j < flightCount - 1; j++) {
                flights[j] = flights[j + 1];
                flightStatuses[j] = flightStatuses[j + 1];
                passengerCounts[j] = passengerCounts[j + 1];
                passengers[j] = passengers[j + 1];
                passengerStatuses[j] = passengerStatuses[j + 1];
            }

            flightCount--;
            flights = realloc(flights, flightCount * sizeof(char *));
            flightStatuses = realloc(flightStatuses, flightCount * sizeof(char *));
            passengers = realloc(passengers, flightCount * sizeof(char **));
            passengerStatuses = realloc(passengerStatuses, flightCount * sizeof(char **));
            passengerCounts = realloc(passengerCounts, flightCount * sizeof(int));

            printf("Flight deleted!\n");
            return;
        }
    }
    printf("Flight not found.\n");
}

void editFlight() {
    char flightNumber[11];
    printf("Enter flight number to edit: ");
    fgets(flightNumber, sizeof(flightNumber), stdin);
    flightNumber[strcspn(flightNumber, "\n")] = 0;

    for (int i = 0; i < flightCount; i++) {
        if (strcmp(flights[i], flightNumber) == 0) {
            printf("Enter new flight number: ");
            fgets(flights[i], 11, stdin);
            flights[i][strcspn(flights[i], "\n")] = 0;
            printf("Flight number updated!\n");
            return;
        }
    }
    printf("Flight not found.\n");
}

void printFlights() {
    if (flightCount == 0) {
        printf("No flights available.\n");
        return;
    }

    printf("No. | Flight Number | Status\n");
    printf("-------------------------------\n");
    for (int i = 0; i < flightCount; i++) {
        printf("%d | %s | %s\n", i + 1, flights[i], flightStatuses[i]);
    }
}

void addPassenger() {
    char flightNumber[11];
    printf("Enter flight number: ");
    fgets(flightNumber, sizeof(flightNumber), stdin);
    flightNumber[strcspn(flightNumber, "\n")] = 0;

    for (int i = 0; i < flightCount; i++) {
        if (strcmp(flights[i], flightNumber) == 0) {
            passengers[i] = realloc(passengers[i], (passengerCounts[i] + 1) * sizeof(char *));
            passengerStatuses[i] = realloc(passengerStatuses[i], (passengerCounts[i] + 1) * sizeof(char *));
            if (!passengers[i] || !passengerStatuses[i]) {
                printf("Memory allocation failed!\n");
                return;
            }

            printf("Enter passenger name: ");
            passengers[i][passengerCounts[i]] = malloc(MAX_NAME_LENGTH * sizeof(char));
            fgets(passengers[i][passengerCounts[i]], MAX_NAME_LENGTH, stdin);
            passengers[i][passengerCounts[i]][strcspn(passengers[i][passengerCounts[i]], "\n")] = 0;

            passengerStatuses[i][passengerCounts[i]] = malloc(21 * sizeof(char));
            strcpy(passengerStatuses[i][passengerCounts[i]], "CustomerServiceDesc");

            passengerCounts[i]++;
            printf("Passenger added!\n");
            return;
        }
    }
    printf("Flight not found.\n");
}

void changePassengerStatusToOnBoard() {
    char flightNumber[11];
    printf("Enter flight number: ");
    fgets(flightNumber, sizeof(flightNumber), stdin);
    flightNumber[strcspn(flightNumber, "\n")] = 0;

    for (int i = 0; i < flightCount; i++) {
        if (strcmp(flights[i], flightNumber) == 0) {
            char passengerName[MAX_NAME_LENGTH];
            printf("Enter passenger name: ");
            fgets(passengerName, sizeof(passengerName), stdin);
            passengerName[strcspn(passengerName, "\n")] = 0;

            for (int j = 0; j < passengerCounts[i]; j++) {
                if (strcmp(passengers[i][j], passengerName) == 0) {
                    strcpy(passengerStatuses[i][j], "OnBoard");
                    printf("Passenger status changed to OnBoard!\n");
                    return;
                }
            }
            printf("Passenger not found.\n");
            return;
        }
    }
    printf("Flight not found.\n");
}

void printPassengersForFlight() {
    char flightNumber[11];
    printf("Enter flight number: ");
    fgets(flightNumber, sizeof(flightNumber), stdin);
    flightNumber[strcspn(flightNumber, "\n")] = 0;

    for (int i = 0; i < flightCount; i++) {
        if (strcmp(flights[i], flightNumber) == 0) {
            printf("Passenger Name | Status\n");
            printf("----------------------------\n");
            for (int j = 0; j < passengerCounts[i]; j++) {
                printf("%s | %s\n", passengers[i][j], passengerStatuses[i][j]);
            }
            return;
        }
    }
    printf("Flight not found.\n");
}

int main() {
    int choice;
    printHeader();
    do {
        printMenu();
        scanf("%d", &choice);
        getchar();
        switch (choice) {
        case 0:
            printHelp();
            break;
        case 1:
            addFlight();
            break;
        case 2:
            changeFlightStatusToActive();
            break;
        case 3:
            changeFlightStatusToCompleted();
            break;
        case 4:
            deleteFlight();
            break;
        case 5:
            editFlight();
            break;
        case 6:
            printFlights();
            break;
        case 7:
            addPassenger();
            break;
        case 8:
            changePassengerStatusToOnBoard();
            break;
        case 9:
            printPassengersForFlight();
            break;
        case 10:
            for (int i = 0; i < flightCount; i++) {
                free(flights[i]);
                free(flightStatuses[i]);
                for (int j = 0; j < passengerCounts[i]; j++) {
                    free(passengers[i][j]);
                    free(passengerStatuses[i][j]);
                }
                free(passengers[i]);
                free(passengerStatuses[i]);
            }
            free(flights);
            free(flightStatuses);
            free(passengers);
            free(passengerStatuses);
            free(passengerCounts);
            printf("Exiting\n");
            break;
        default:
            printf("Invalid choice!\n");
        }
    } while (choice != 10);

    return 0;
}