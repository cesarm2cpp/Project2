#include <stdio.h>
#include "Tools.h"

int main()
{
    // doesn't involve different time
    int totalDays;
    double arrivalTime;
    double departTime;
    double airFare;
    double carRent;
    int miles;
    double privateCar;
    double milesDriven;
    double registrationFee;
    double confSemFees;

    // fees that are partly covered by company
    double parkingFees;
    int parkingDays;
    double taxiFee;
    int taxiDays;
    double hotelFee;
    int hotelDays;  // can be different from totalDays Ex: we can go 4 days and 3 nights
    char carRental[10];
    char taxiUse[10];
    double minTime = 0.0; //min number is 1
    double maxTime = 24.0; //max number is 10
    
    printf("Total travel days:");
    scanf("%d", &totalDays);
    
    printf("Enter departure time (0..24 military time):");
    scanf("%lf", &arrivalTime);
    do{
        if(arrivalTime < minTime){
            printf("\nTime can't be negative");
            printf("\nEnter departure time (0..24 military time):");
            scanf("%lf", &arrivalTime);
        }
        if(arrivalTime > maxTime)
        {
            printf("\nThat time does not exist");
            printf("\nEnter departure time (0..24 military time):");
            scanf("%lf", &arrivalTime);
        }
    }
    while(arrivalTime > maxTime || arrivalTime < minTime);
    
    printf("\nEnter arrival time (0..24 military time):");
    scanf("%lf", &departTime);

    printf("Amount of the round trip airfare: ");
    scanf("%lf", &airFare);
    printf("Did you rent any car?(y or n):");
    scanf("%s", carRental);
    if(carRental, "y")
    {
        printf("How many miles did you drive in your private vehicle:" );
        scanf("%d", &miles);
    }
    else{
        printf("No car was rented");
    }
    printf("\nParking fees during trip: ");
    scanf("%lf", &parkingFees);
    printf("Amount of days you used the parking: ");
    scanf("%d", &parkingDays);
    printf("Did you use the taxi(y or n):");
    scanf("%s", taxiUse);
    if(taxiUse, "y")
    {
        printf("Taxi fees: ");
        scanf("%lf", &taxiFee);
    }
    else{
        printf("No taxi was used");
    }
    printf("\nAmount of days used on taxi:");
    scanf("%d", &taxiDays);
    printf("Conference or seminar registration fees:");
    scanf("%lf", &confSemFees);
    printf("Any hotel expenses:");
    scanf("%lf", &hotelFee);

    return 0;
}
