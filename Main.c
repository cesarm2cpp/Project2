#include <stdio.h>
#include <stdlib.h>
#include "calculate.h"

int main()
{
    int totalDays;
    double arrivalTime;
    double departTime;
    double airFare;
    double carRent;
    double miles;
    double privateCar;
    double milesDriven;
    double registrationFee;
    double confSemFees;
    double rentalPrice;
    double rentalValue;
    double privateValue;
    double breakfast;
    double lunch;
    double dinner;
    double totalFood;
    double calcPark;
    double TotalOverall;

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
    scanf("%lf", &departTime);
    do{
        if(departTime < minTime){
            printf("\nTime can't be negative");
            printf("\nEnter departure time (0..24 military time):");
            scanf("%lf", &arrivalTime);
        }
        if(departTime > maxTime)
        {
            printf("\nThat time does not exist");
            printf("\nEnter departure time (0..24 military time):");
            scanf("%lf", &arrivalTime);
        }
    }
    while(departTime > maxTime || departTime < minTime);
    
    printf("\nEnter arrival time (0..24 military time):");
    scanf("%lf", &arrivalTime);
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
    while(arrivalTime > maxTime || arrivalTime < minTime);

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

    
    printf("\nDid you rent any car?(y or n):");
    scanf("%s", carRental);
    if(carRental, "y")
    {
        printf("\nHow much was the car you had rented?:" );
        scanf("%lf", &rentalPrice);
        do{
            if(rentalPrice<minTime){
                printf("\nNo such thing as negative money!");
                printf("\nHow much was the car you had rented?:" );
                scanf("%lf", &rentalPrice);
            }
        }while(rentalPrice<minTime);
    }else{
        printf("No car was rented");
        rentalPrice = 0.0;
    }
    
    printf("\nDid you use your private car?");
    scanf("%s", privateC);
    if(privateC, "y"){
        printf("How many miles did you drive in your private vehicle? ");        
        scanf("%lf", &privateCar);
        do{
            if(privateCar<minTime){
                printf("\nNo such thing as negative mile!");
                printf("\nHow many miles did you drive in your private vehicle:" );
                scanf("%lf", &privateCar);
            }
        }while(privateCar<minTime);
        privateValue = carMileage(privateCar);
    }else{
        printf("\nDid not use private car");
        privateValue = 0.0;
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
            printf("\nAmount of days used on taxi:");
            scanf("%d", &taxiDays);
        }
    }while(taxiDays<minTime);
    taxiFee = tax(taxiFee, taxiDays);
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
    hotelFee = hotel(hotelFee, totalDays);
    
    printf("Amount spent on breakfast:");
    scanf("%lf", &breakfast);
    printf("Amount spent on lunch:");
    scanf("%lf", &lunch);
    printf("Amount spent on dinner:");
    scanf("%lf", &dinner);
    totalFood = breakfast + lunch + dinner;
    calcPark = calcParking(parkingFees, parkingDays);
    TotalOverall = TotalExpense(airFare, rentalPrice, privateValue, calcPark, taxiFee, confSemFees, hotelFee, totalFood);
    double defaultPark = 6 * totalDays;
    double defaultTaxi = 10 * totalDays;
    double defaultHotel = 90 * totalDays;
    double temp = Totaltemp(airFare, rentalPrice, privateValue, confSemFees);
    double TotalAllow = temp + defaultPark + defaultHotel + 37;
    
    printf("\nTOTAl EXPENSES LIST");
    printf("\n--------------------------");
    printf("\nTrip:$%lf", airFare);
    printf("\nRental:$%lf", rentalPrice);
    printf("\nMileage:$%lf", privateValue );
    printf("\nParking:$%lf", calcPark);
    printf("\nTaxi:$%lf", taxiFee);
    printf("\nConference:$%lf", confSemFees);
    printf("\nHotels:$%lf", hotelFee);
    printf("\nBreakfast:$%lf", bf(breakfast, arrivalTime, departTime));
    printf("\nLunch:$%lf", lch(lunch, arrivalTime, departTime));
    printf("\nDinner:$%lf",dr(dinner, arrivalTime, departTime));
    printf("\nTotal Expenses:$%lf", TotalOverall);
    
    printf("\nTOTAL ALLOWABLE EXPENSES");
    printf("\n--------------------------");
    printf("\nTrip:$%lf", airFare);
    printf("\nRental:$%lf", rentalPrice);
    printf("\nMileage:$%lf", privateValue );
    printf("\nParking:$%lf", defaultPark);
    printf("\nTaxi:$%lf", defaultTaxi);
    printf("\nConference:$%lf", confSemFees);
    printf("\nHotels:$%lf", defaultHotel);
    printf("\nBreakfast:$9");
    printf("\nLunch:$12");
    printf("\nDinner:$16");
    printf("\nTotal allowable Expenses:$%lf", TotalAllow);
    
    double valueCheck = TotalOverall - TotalAllow;
    if(valueCheck > 0){
        printf("\nYou owe the company:$%lf",valueCheck);
    }
    if(valueCheck < 0 ){
        double conv = abs(valueCheck);
        printf("\nYou saved the company:$%lf",conv);
    }
    return 0;
}
