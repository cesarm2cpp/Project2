#include <stdio.h>
#include "Tools.h"
#include "calculate.c"

<<<<<<< HEAD
int writeCalculations(int miles, double parkingFees, int parkingDays, char taxiUse[10], double taxiFee, int taxiDays, double hotelFee, int hotelDays, double arrivalTime, double departTime, int totalDays, double breakfastFees, double lunchFees, double dinnerFees) {
=======
int writeCalculations(int miles, double parkingFees, int parkingDays, char taxiUse[10], double taxiFee, int taxiDays, double hotelFee, int totalDays,double carRental) {
>>>>>>> 1bd37a5deb3285a724c15c1e8eddef66be36977b
    printf("Miles Fees: %d\n", calculateMiles(miles));
    printf("Parking Fees: %d\n", calculateParkingFees(parkingFees, parkingDays));
    if(taxiUse, 'y') {
        printf("Taxi Fees: %d\n", calculateTaxiFees(taxiUse, taxiFee, taxiDays));
    }
    printf("Hotel Fees: %d\n", calculateHotelFees(hotelFee, hotelDays, totalDays));
    printf("Breakfast Fees: %d\n", calculateBreakfast(arrivalTime, departTime, totalDays, breakfastFees));
    printf("Lunch Fees: %d\n", calculateLunch(arrivalTime, departTime, totalDays, lunchFees));
    printf("Dinner Fees: %d\n", calculateDinner(arrivalTime, departTime, totalDays, dinnerFees));
    printf("Meal Fees: %d\n", claculateMealFees(arrivalTime, departTime, totalDays, breakfastFees, lunchFees, dinnerFees));
    
    return 0;
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
    char privateC[10];
    double minTime = 0.0; //min number is 1
    double maxTime = 24.0; //max number is 10

    // Abigail Vars
    double breakfastFees;
    double lunchFees;
    double dinnerFees;
    
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
        if(departTime < minTime){
            printf("\nTime can't be negative");
            printf("\nEnter departure time (0..24 military time):");
            scanf("%lf", &departTime);
        }
        if(departTime > maxTime)
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
        printf("How much was the car you had rented?:" );
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
    
    printf("\nDid you use your private car?)
    scanf("%s", privateC);
    if(privateC, "y"){
        printf("How many miles did you drive in your private vehicle? "):
        scanf("%d", &privateCar);
        do{
            if(privateCar<minTime){
                printf("\nNo such thing as negative mile!");
                printf("\nHow many miles did you drive in your private vehicle:" );
                scanf("%d", &miles);
            }
        }while(privateCar<minTime);
    }else{
        printf("\nDid not use private car");
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
            if(taxiFee<minTime){// Abigail taxiUse -> taxiFee
                printf("\nFees are not negative");
                printf("\nTaxi fees: ");
                scanf("%lf", &taxiFee);
            }
        }while(taxiFee<minTime);// Abigail taxiUse -> taxiFee
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
    printf("Total breakfast fees:");
    scanf("%lf", &breakfastFees);
    printf("Total lunch fees:");
    scanf("%lf", &lunchFees);
    printf("Total Dinner Fees:");
    scanf("%lf", &dinnerFees);

<<<<<<< HEAD
    writeCalculations(miles, parkingFees, parkingDays, taxiUse, taxiFee, taxiDays, hotelFee, hotelDays, arrivalTime, departTime, totalDays, breakfastFees, lunchFees, dinnerFees);
=======
    writeCalculations(miles, parkingFees, parkingDays, carRental, taxiUse, taxiFee, taxiDays, hotelFee, totalDays);
>>>>>>> 1bd37a5deb3285a724c15c1e8eddef66be36977b
    
    return 0;
}

