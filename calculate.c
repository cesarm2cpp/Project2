#include "calculate.h"

// Calculate Miles Driven in Private Vehicle
int calculateMiles() {// $0.27 per mile driven

}

// Calculate Parking Fees
int calculateParkingFees() {// company PARKING_COVERED_PER_DAY = 6
    if(parkingFees < 0) {
        parkingFees = 0;
    }
}

// Calculate Taxi Fees
int calculateTaxiFees() {// company TAXI_COVERED_PER_DAY = 10
    if(taxi < 0) {
        taxi = 0;
    }
}

// Calculate Hotel Fees
int calculateHotelFees() {// company HOTEL_COVERED_PER_NIGHT = 90
    if(hotelFee < 0) {
        hotelFee = 0;
    }
}

// Calculate Breakfast
int calculateBreakfast() {// company BREAKFAST_COVERED = 9
    if(breakfast < 0) {
        breakfast = 0;
    }
    return breakfast;
}

// Calculate Lunch
int calculateLunch() {// company LUNCH_COVERED = 12
    if(lunch < 0) {
        lunch = 0;
    }
    return lunch;
}

// Calculate Dinner
int calculateDinner() {// company DINNER_COVERED = 16
    if(dinner < 0) {
        dinner = 0;
    }
    return dinner;
}

// Calculate Meals
int calculateMealFees() {
    return calculateBreakfast() + calculateLunch() + calculateDinner();
}