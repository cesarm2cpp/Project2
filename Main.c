#include <stdio.h>
#include <stdlib.h>
#include "calculate.h"
// #include "Tools.h"
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
    float parkingFees=0;
    int parkingDays = 0;
    float taxiFee;
    int taxiDays;
    float hotelFee;
    int hotelDays;  // can be different from totalDays Ex: we can go 4 days and 3 nights
    char carRental[10];
    char taxiUse[10];
    char privateC[10];
    float minTime = 0.0; //min number is 1
    float maxTime = 24.0; //max number is 10
    
/*------------------------------------- 1. Get all user inputs -------------------------------------*/
    totalDays = getUserInt("Total Travel Days: ");
    departTime = getBoundedFloat("\nEnter departure time [0..24) - military time: ",minTime,maxTime);
    arrivalTime = getBoundedFloat("\nEnter departure time [0..24) - military time: ",minTime,maxTime);
    airFare = getUserFloat("\nAmount of the round tip airfare: $");

    printf("\nDid you rent any car?(y or n):");
    scanf("%s", carRental);
    clean_stdin();
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
    clean_stdin();
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
    clean_stdin();
    do{
        if(parkingFees<minTime){
            printf("\nMoney is never negative");
            printf("\nParking fees during trip:$");
            scanf("%f", &parkingFees);
            clean_stdin();
        }
        else if(parkingFees > minTime){
            printf("\nAmount of days you used the parking: ");
            scanf("%d", &parkingDays);
            clean_stdin();
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
        clean_stdin();
        do{
            if(taxiFee<minTime){// taxiUse -> taxiFee
                printf("\nFees are not negative");
                printf("\nTaxi fees:$");
                scanf("%f", &taxiFee);
                clean_stdin();
            }
            else if(taxiFee > minTime){
                printf("\nAmount of days used on taxi:");
                scanf("%d", &taxiDays);
                do{
                    if(taxiDays<minTime){
                        printf("\nAmount of days used on taxi:");
                        scanf("%d", &taxiDays);
                        clean_stdin();
                    }
                }while(taxiDays<minTime);
                taxiFee = tax(taxiFee, taxiDays);
            }
        }while(taxiFee<minTime);// taxiUse -> taxiFee
    }
    else{
        printf("\nNo taxi was used");
    }
    confSemFees = getUserFloat("\nConference or seminar registration fees: $");
    hotelFee = getUserFloat("\nAny hotel expenses: $");
    hotelFee = hotel(hotelFee, totalDays);
    
    breakfast = getUserFloat("\nAmount spent on breakfast: $");
    lunch = getUserFloat("\nAmount spent on lunch: $");
    dinner = getUserFloat("\nAmount spent on dinner:$");
 /*------------------------------------- 2. Make calculations -------------------------------------*/
    totalFood = breakfast + lunch + dinner;
    calcPark = calcParking(parkingFees, parkingDays);
    TotalOverall = TotalExpense(airFare, rentalPrice, privateValue, calcPark, taxiFee, confSemFees, hotelFee, totalFood);
    float defaultPark = 6 * totalDays;
    float defaultTaxi = 10 * totalDays;
    float defaultHotel = 90 * totalDays;
    float temp = Totaltemp(airFare, rentalPrice, privateValue, confSemFees);
    float TotalAllow = temp + defaultPark + defaultHotel + 37;

    /*------------------------------------- 3. Display -------------------------------------*/
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
