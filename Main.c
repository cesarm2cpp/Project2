#include <stdio.h>
#include "Tools.h"
int main()
{
    // doesn't involve different time
    int totalDays;
    double arrivalTime;
    double departTime;
    double airFare;
    double milesDriven;
    int registrationFee;

    // fees that are partly covered by company
    double parkingFees;
    int parkingDays;
    double taxiFee;
    int taxiDays;
    double hotelFee;
    int hotelDays;  // can be different from totalDays Ex: we can go 4 days and 3 nights

    totalDays = getUserInt("Please enter total travel days: ");
    printf("Total travel days: %d\n", totalDays);
    
    departTime = getBoundedNum("Enter departure time (0..24 military time) ",0,24);
    arrivalTime = getBoundedNum("Enter arrival time (0..24 military time) ",0,24);
    printf("\nConfirm the departure time is: %lf", departTime);
    printf("\nConfirm the arrival time is: %lf", arrivalTime);

    return 0;
    // char carRental[1];
    // char taxiUse[1];
    
    // printf("\nInput the total amount of days: ");
    // scanf("%d", &days);
    // printf("\nThe time of arrival: ");
    // scanf("%d", &arrival);
    // printf("\nThe time of departer:" );
    // scanf("%d", &departer);
    // printf("\nAmount of the round trip airfare: ");
    // scanf("%d", &roundTrip);
    // printf("\nDid you rent any car?(Y or N): ");
    // scanf("%s", carRental);
    // printf("\nHow many miles did you drive in your private vehicle" );
    // scanf("%d", &miles);
    // printf("\nParking fees during trip: ");
    // scanf("%d", &parkingFees);
    // printf("\nAmount of days you used the parking: ");
    // scanf("%d", &daysParking);
    // printf("\nDid you use the taxi(Y or N): ");
    // scanf("%s", taxiUse);
    // printf("\nTaxi fees: ");
    // scanf("%d", &taxi);
    // printf("\nAmount of days used on taxi: ");
    // scanf("%d", &taxiDays);
    // printf("\nConference or seminar registration fees: ");
    // scanf("%d", &confSemFees);
    // printf("\nAny hotel expenses: ");
    // scanf("%d", &hotel);
}
