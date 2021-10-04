#ifndef CALCULATE_H
#define CALCULATE_H

#include <stdio.h>
#include <string.h> // if you use a struct or union.

double calcParking(double parkingFees,int parkingDays);
double carMileage(double privateCar);
double tax(double taxiFee, double taxiDays);
double hotel(double hotelFee, double totalDays);
double bf(double b, double a, double dep);
double lch(double l, double a, double dep);
double dr(double d, double a, double dep);
double TotalExpense(double airFare, double rentalPrice,double privateValue,double calcPark,double taxiFee,double confSemFees,double hotelFee,double totalFood);
double Totaltemp(double airFare,double rentalPrice,double privateValue, double confSemFees);

#endif
