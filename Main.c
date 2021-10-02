#include <stdio.h>
#include "Tools.h"
#include "calculate.c"

int writeCalculations(int miles, double milesDriven, double parkingFees) {
    printf("Miles Fees: %f\n", calculateMiles(miles, milesDriven));
    printf("Parking Fees: %f\n", parkingFees);
}

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
    do{
        if(totalDays<minTime){
            printf("Time is not negative");
            printf("Total travel days:");
            scanf("%d", &totalDays);
        }
    }while(totalDays<minTime);
    
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
        do{
        if(arrivalTime < minTime){
            printf("\nTime can't be negative");
            printf("\nEnter departure time (0..24 military time):");
            scanf("%lf", &departTime);
        }
        if(arrivalTime > maxTime)
        {
            printf("\nThat time does not exist");
            printf("\nEnter departure time (0..24 military time):");
            scanf("%lf", &departTime);
        }
    }
    while(departTime > maxTime || departTime < minTime);

    printf("Amount of the round trip airfare: ");
    scanf("%lf", &airFare);
    do{
        if(airFare < minTime)
        {
            printf("\nMoney is never negative");
            printf("\nAmount of the round trip airfare: ");
            scanf("%lf", &airFare);
        }
    }while(airFare<minTime);
    
    printf("Did you rent any car?(y or n):");
    scanf("%s", carRental);
    if(carRental, "y")
    {
        printf("How many miles did you drive in your private vehicle:" );
        scanf("%d", &miles);
        do{
            if(miles<minTime){
                printf("\nNo such thing as negative mile!");
                printf("\nHow many miles did you drive in your private vehicle:" );
                scanf("%d", &miles);
            }
        }while(miles<minTime);
    }
    else{
        printf("No car was rented");
    }
    printf("\nParking fees during trip: ");
    scanf("%lf", &parkingFees);
    do{
        if(parkingFees<minTime){
            printf("\nMoney is never negative");
            printf("\nParking fees during trip: ");
            scanf("%lf", &parkingFees);
        }
    }while(parkingFees<minTime);
    
    printf("Amount of days you used the parking: ");
    scanf("%d", &parkingDays);
    do{
        if(parkingDays<minTime){
            printf("\nDays are not in negative");
            printf("\nAmount of days you used the parking: ");
            scanf("%d", &parkingDays);
        }
    }while(parkingDays<minTime);
    
    printf("Did you use the taxi(y or n):");
    scanf("%s", taxiUse);
    if(taxiUse, "y")
    {
        printf("Taxi fees: ");
        scanf("%lf", &taxiFee);
        do{
            if(taxiFee<minTime){// taxiUse -> taxiFee
                printf("\nFees are not negative");
                printf("\nTaxi fees: ");
                scanf("%lf", &taxiFee);
            }
        }while(taxiFee<minTime);// taxiUse -> taxiFee
    }
    else{
        printf("No taxi was used");
    }
    printf("\nAmount of days used on taxi:");
    scanf("%d", &taxiDays);
    do{
        if(taxiDays<minTime){
            printf("\nAmount of days used");
            printf("\nAmount of days used on taxi:");
            scanf("%d", &taxiDays);
        }
    }while(taxiDays<minTime);
    printf("Conference or seminar registration fees:");
    scanf("%lf", &confSemFees);
    do{
        if(confSemFees<minTime){
            printf("\nMoney isnt negative!");
            printf("\nConference or seminar registration fees:");
            scanf("%lf", &confSemFees);
        }
    }while(confSemFees<minTime);
    printf("Any hotel expenses:");
    scanf("%lf", &hotelFee);
    do{
        if(hotelFee<minTime){
            printf("\nMoney isn't negative!");
            printf("\nAny hotel expenses:");
            scanf("%lf", &hotelFee);
        }
    }while(hotelFee<minTime);

    writeCalculations(miles, milesDriven, parkingFees);
    
    return 0;
}

