#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <string.h> // if you use a struct or union.
#include "Tools_driver.c"

// Global Calculation Vars
int totalDays;
int arrivalTime;
int departureTime;
int airFare;
char carRental; // 'y' or 'n'
int miles;// $0.27 per mile driven
int parkingFees;// company= $6*daysParking, if(negative): var=0
int parkingDays;
char taxiUse; // 'y' or 'n'
int taxiFee;// company= $10*taxiDays, if(negative): var=0
int taxiDays;
int confSemFees; // NOT Currently Used
int hotelFee;// company= $90*hotelNights, if(negative): var=0
int hotelDays;
int meals;// (for allowable meals) breakfast + lunch + dinner
int breakfast;// company= $9, if(negative): var=0
int lunch;// company= $12, if(negative): var=0
int dinner;// company= $16, if(negative): var=0

// Enum: User Defined Var
enum company{PARKING_COVERED_PER_DAY = 6, TAXI_COVERED_PER_DAY = 10, HOTEL_COVERED_PER_NIGHT = 90, BREAKFAST_COVERED = 9, LUNCH_COVERED = 12, DINNER_COVERED = 16}; // used to hold const vars of company covered fees

#endif