#include <stdio.h>
#include <stdlib.h>
#include "calculate.h"

int main()
{
    int totalDays;
    float arrivalTime;
    float departTime;
    float airFare;
    float carRent;
    float miles;
    float privateCar;
    float milesDriven;
    float registrationFee;
    float confSemFees;
    float rentalPrice;
    float rentalValue;
    float privateValue;
    float breakfast;
    float lunch;
    float dinner;
    float totalFood;
    float calcPark;
    float TotalOverall;

    // fees that are partly covered by company
    float parkingFees;
    int parkingDays;
    float taxiFee;
    int taxiDays;
    float hotelFee;
    int hotelDays;  // can be different from totalDays Ex: we can go 4 days and 3 nights
    char carRental[10];
    char taxiUse[10];
    char privateC[10];
    float minTime = 0.0; //min number is 1
    float maxTime = 24.0; //max number is 10
    
    printf("Total travel days:");
    scanf("%d", &totalDays);
    do{
        if(totalDays<minTime){
            printf("Time is not negative");
            printf("Total travel days:");
            scanf("%d", &totalDays);
        }
    }while(totalDays<minTime);
    
    
    printf("\nEnter departure time (0..24 military time):");
    scanf("%f", &departTime);
    do{
        if(departTime > maxTime || departTime < minTime ){
            printf("\nTime is out of bound");
            printf("\nEnter departure time (0..24 military time):");
            scanf("%f", &departTime);
        }
    }
    while(departTime > maxTime || departTime < minTime);
    
    printf("\nEnter arrival time (0..24 military time):");
    scanf("%f", &arrivalTime);
        do{
        if(arrivalTime > maxTime || arrivalTime < minTime){
            printf("\nTime is out of bound");
            printf("\nEnter departure time (0..24 military time):");
            scanf("%f", &arrivalTime);
        }
    }
    while(arrivalTime > maxTime || arrivalTime < minTime);

    printf("\nAmount of the round trip airfare:$");
    scanf("%f", &airFare);
    do{
        if(airFare < minTime)
        {
            printf("\nMoney is never negative");
            printf("\nAmount of the round trip airfare:$");
            scanf("%f", &airFare);
        }
    }while(airFare<minTime);

    
    printf("\nDid you rent any car?(y or n):");
    scanf("%s", carRental);
    if(strcmp(carRental, "y")==0)
    {
        printf("\nHow much was the car you had rented?:$" );
        scanf("%f", &rentalPrice);
        do{
            if(rentalPrice<minTime){
                printf("\nNo such thing as negative money!");
                printf("\nHow much was the car you had rented?:$" );
                scanf("%f", &rentalPrice);
            }
        }while(rentalPrice<minTime);
    }else{
        printf("\nNo car was rented");
        rentalPrice = 0.0;
    }
    
    printf("\nDid you use your private car?(y or n):");
    scanf("%s", privateC);
    if(strcmp(privateC, "y")==0){
        printf("\nHow many miles did you drive in your private vehicle? ");        
        scanf("%f", &privateCar);
        do{
            if(privateCar<minTime){
                printf("\nNo such thing as negative mile!");
                printf("\nHow many miles did you drive in your private vehicle:" );
                scanf("%f", &privateCar);
            }
        }while(privateCar<minTime);
        privateValue = carMileage(privateCar);
    }else{
        printf("\nDid not use private car");
        privateValue = 0.0;
    }
    if(rentalPrice || privateCar != 0){
    printf("\nParking fees during trip:$");
    scanf("%f", &parkingFees);
    do{
        if(parkingFees<minTime){
            printf("\nMoney is never negative");
            printf("\nParking fees during trip:$");
            scanf("%f", &parkingFees);
        }
        else if(parkingFees > minTime){
            printf("\nAmount of days you used the parking: ");
            scanf("%d", &parkingDays);
            do{
                if(parkingDays<minTime){
                printf("\nAmount of days you used the parking: ");
                scanf("%d", &parkingDays);
                }
            }while(parkingDays<minTime);
        }
    }while(parkingFees<minTime);
    }
    
    printf("\nDid you use the taxi(y or n):");
    scanf("%s", taxiUse);
    if(strcmp(taxiUse, "y")==0){
        printf("\nTaxi fees:$");
        scanf("%f", &taxiFee);
        do{
            if(taxiFee<minTime){// taxiUse -> taxiFee
                printf("\nFees are not negative");
                printf("\nTaxi fees:$");
                scanf("%f", &taxiFee);
            }
            else if(taxiFee > minTime){
                printf("\nAmount of days used on taxi:");
                scanf("%d", &taxiDays);
                do{
                    if(taxiDays<minTime){
                        printf("\nAmount of days used on taxi:");
                        scanf("%d", &taxiDays);
                    }
                }while(taxiDays<minTime);
                taxiFee = tax(taxiFee, taxiDays);
            }
        }while(taxiFee<minTime);// taxiUse -> taxiFee
    }
    else{
        printf("\nNo taxi was used");
    }

    printf("\nConference or seminar registration fees:$");
    scanf("%f", &confSemFees);
    do{
        if(confSemFees<minTime){
            printf("\nMoney isnt negative!");
            printf("\nConference or seminar registration fees:$");
            scanf("%f", &confSemFees);
        }
    }while(confSemFees<minTime);
    printf("\nAny hotel expenses:$");
    scanf("%f", &hotelFee);
    do{
        if(hotelFee<minTime){
            printf("\nMoney isn't negative!");
            printf("\nAny hotel expenses:$");
            scanf("%f", &hotelFee);
        }
    }while(hotelFee<minTime);
    hotelFee = hotel(hotelFee, totalDays);
    
    printf("\nAmount spent on breakfast:$");
    scanf("%f", &breakfast);
    do{
        if(breakfast<minTime){
            printf("\nAmount spent on breakfast:$");
            scanf("%f", &breakfast);
        }
    }while(breakfast<minTime);
    printf("\nAmount spent on lunch:$");
    scanf("%f", &lunch);
    do{
        if(lunch<minTime){
            printf("\nAmount spent on lunch:$");
            scanf("%f", &lunch);
        }
    }while(lunch<minTime);
    printf("\nAmount spent on dinner:$");
    scanf("%f", &dinner);
    do{
        if(dinner<minTime){
            printf("\nAmount spent on dinner:$");
            scanf("%f", &dinner);
        }
    }while(dinner<minTime);
    
    totalFood = breakfast + lunch + dinner;
    calcPark = calcParking(parkingFees, parkingDays);
    TotalOverall = TotalExpense(airFare, rentalPrice, privateValue, calcPark, taxiFee, confSemFees, hotelFee, totalFood);
    float defaultPark = 6 * totalDays;
    float defaultTaxi = 10 * totalDays;
    float defaultHotel = 90 * totalDays;
    float temp = Totaltemp(airFare, rentalPrice, privateValue, confSemFees);
    float TotalAllow = temp + defaultPark + defaultHotel + 37;
    printf("\n--------------------------");
    printf("\nTOTAl EXPENSES LIST");
    printf("\n--------------------------");
    printf("\nTrip:$%.2f", airFare);
    printf("\nRental:$%.2f", rentalPrice);
    printf("\nMileage:$%.2f", privateValue );
    printf("\nParking:$%.2f", calcPark);
    printf("\nTaxi:$%.2f", taxiFee);
    printf("\nConference:$%.2f", confSemFees);
    printf("\nHotels:$%.2f", hotelFee);
    printf("\nBreakfast:$%.2f", bf(breakfast, arrivalTime, departTime));
    printf("\nLunch:$%.2f", lch(lunch, arrivalTime, departTime));
    printf("\nDinner:$%.2f",dr(dinner, arrivalTime, departTime));
    printf("\nTotal Expenses:$%.2f", TotalOverall);
    printf("\n--------------------------");
    printf("\nTOTAL ALLOWABLE EXPENSES");
    printf("\n--------------------------");
    printf("\nTrip:$%.2f", airFare);
    printf("\nRental:$%.2f", rentalPrice);
    printf("\nMileage:$%.2f", privateValue );
    printf("\nParking:$%.2f", defaultPark);
    printf("\nTaxi:$%.2f", defaultTaxi);
    printf("\nConference:$%.2f", confSemFees);
    printf("\nHotels:$%.2f", defaultHotel);
    printf("\nBreakfast:$9");
    printf("\nLunch:$12");
    printf("\nDinner:$16");
    printf("\nTotal allowable Expenses:$%.2f", TotalAllow);
    printf("\n--------------------------");
    printf("\nResult of trip");
    printf("\n--------------------------");
    float valueCheck = (TotalOverall - TotalAllow);
    if(valueCheck > 0){
        printf("\nYou owe the company:$%.2f",valueCheck);
    }
    if(valueCheck < 0 ){
        float conv = abs(valueCheck);
        printf("\nYou saved the company:$%.2f",conv);
    }
    return 0;
}
