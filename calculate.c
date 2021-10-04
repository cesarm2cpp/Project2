#include "calculate.h"

double calcParking(double parkingFees,int parkingDays){
    double sponsor = 6.0 * parkingDays;
    double parkingPrice = parkingFees-sponsor; 
    return parkingPrice;
}
double carMileage(double privateCar){
    double price = privateCar * .27;
    return price;
}
double tax(double taxiFee, double taxiDays){
    double temp = 10 * taxiDays;
    double price = (taxiDays * taxiFee) - temp;
    return price;
}
double hotel(double hotelFee, double totalDays){
    double temp = 90 * totalDays;
    double price = (hotelFee * totalDays) - temp;
    return price;
}
double bf(double b, double a, double dep){
    double meal;
    if(dep<7.0){
        meal = b - 9;
        return meal;
    }
    if(a>8.0){
        meal = b - 9;
        return meal;
    }

}
double lch(double l, double a, double dep){
    double meal;
    if(dep<12.0){
        meal = l-12.0;
        return meal;
    }
    if(a>13.0){
        meal = l-12.0;
        return meal;
    }
}
double dr(double d, double a, double dep){
    double meal;
    if(dep<18.0){
        meal = d-16.0;
        return meal;
    }
    if(a>19.0){
        meal = d-16.0; 
        return meal;
    }
}
double TotalExpense(double airFare, double rentalPrice,double privateValue,double calcPark,double taxiFee,double confSemFees,double hotelFee,double totalFood){
    double Total = airFare + rentalPrice + privateValue + calcPark + taxiFee + confSemFees + hotelFee + totalFood;
    return Total;
}
