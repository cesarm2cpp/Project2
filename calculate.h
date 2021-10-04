#ifndef CALCULATE_H
#define CALCULATE_H

#include <stdio.h>
#include <string.h> // if you use a struct or union.
#include "Tools.h"

float calcParking(float parkingFees,int parkingDays);
float carMileage(float privateCar);
float tax(float taxiFee, float taxiDays);
float hotel(float hotelFee, float totalDays);
float bf(float b, float a, float dep);
float lch(float l, float a, float dep);
float dr(float d, float a, float dep);
float TotalExpense(float airFare, float rentalPrice,float privateValue,float calcPark,float taxiFee,float confSemFees,float hotelFee,float totalFood);
float Totaltemp(float airFare,float rentalPrice,float privateValue, float confSemFees);

#endif
