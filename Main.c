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
    

    printf("Total travel days:");
    scanf("%d", &totalDays);
    
    printf("Enter departure time (0..24 military time)");
    scanf("%lf", &arrivalTime);
    printf("Enter arrival time (0..24 military time)");
    scanf("%lf", &departTime);

    printf("\nAmount of the round trip airfare: ");
    scanf("%lf", &airFare);
    printf("\nDid you rent any car?(y or n):");
    scanf("%s", carRental);
    if(carRental == "y")
    {
        printf("\nHow many miles did you drive in your private vehicle:" );
        scanf("%d", &miles);
    }
    else if(carRental == "n"){
        printf("No car was rented");
    }
    printf("\nParking fees during trip: ");
    scanf("%lf", &parkingFees);
    printf("\nAmount of days you used the parking: ");
    scanf("%d", &parkingDays);
    printf("\nDid you use the taxi(y or n):");
    scanf("%s", taxiUse);
    if(taxiUse == "y")
    {
        printf("\nTaxi fees: ");
        scanf("%lf", &taxiFee);
    }
    else{
        printf("No taxi was used");
    }
    printf("\nAmount of days used on taxi: ");
    scanf("%d", &taxiDays);
    printf("\nConference or seminar registration fees: ");
    scanf("%lf", &confSemFees);
    printf("\nAny hotel expenses: ");
    scanf("%lf", &hotelFee);

    return 0;
}
