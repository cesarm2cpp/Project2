#include "calculate.h"

float calcParking(float parkingFees,int parkingDays){
    float sponsor = PARKING_COVERED_PER_DAY * parkingDays;
    float parkingPrice = parkingFees-sponsor; 
    return parkingPrice;
}
float carMileage(float privateCar){
    float price = privateCar * GAS_PRICE_PER_MILE;
    return price;
}
float tax(float taxiFee, float taxiDays){
    float temp = TAXI_COVERED_PER_DAY * taxiDays;
    float price = (taxiDays * taxiFee) - temp;
    return price;
}
float hotel(float hotelFee, float totalDays){
    float temp = HOTEL_COVERED_PER_NIGHT * totalDays;
    float price = (hotelFee * totalDays) - temp;
    return price;
}
float bf(float b, float a, float dep){
    float meal;
    if(dep<7.0){
        meal = b - BREAKFAST_COVERED;
        return meal;
    }
    if(a>8.0){
        meal = b - BREAKFAST_COVERED;
        return meal;
    }
}
float lch(float l, float a, float dep){
    float meal;
    if(dep<12.0){
        meal = l-LUNCH_COVERED;
        return meal;
    }
    if(a>13.0){
        meal = l-LUNCH_COVERED;
        return meal;
    }
}
float dr(float d, float a, float dep){
    float meal;
    if(dep<18.0){
        meal = d-DINNER_COVERED;
        return meal;
    }
    if(a>19.0){
        meal = d-DINNER_COVERED; 
        return meal;
    }
}
float TotalExpense(float airFare, float rentalPrice,float privateValue,float calcPark,float taxiFee,float confSemFees,float hotelFee,float totalFood){
    float Total = airFare + rentalPrice + privateValue + calcPark + taxiFee + confSemFees + hotelFee + totalFood;
    return Total;
}

float Totaltemp(float airFare,float rentalPrice,float privateValue, float confSemFees){
    float Total = airFare + rentalPrice + privateValue + confSemFees;
    return Total;
}
