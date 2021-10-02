#include "calculate.h"
/* TODO: 1.add meal vars breakfast, lunch, and dinner to main
2.change departer to departure
*/ 

// Calculate Miles Driven in Private Vehicle
int calculateMiles() {// $0.27 per mile driven
    miles = miles * 0.27;
    return miles;
}

// Calculate Parking Fees
int calculateParkingFees() {// company PARKING_COVERED_PER_DAY = 6
    parkingFees = (parkingFees - PARKING_COVERED_PER_DAY);
    if(parkingFees < 0) {
        parkingFees = 0;
    }
    return parkingFees;
}

// Calculate Taxi Fees
int calculateTaxiFees() {// company TAXI_COVERED_PER_DAY = 10
    taxi = (taxi - TAXI_COVERED_PER_DAY);
    if(taxi < 0) {
        taxi = 0;
    }
    return taxi;
}

// Calculate Hotel Fees
int calculateHotelFees() {// company HOTEL_COVERED_PER_NIGHT = 90
    hotelFee = (hotelFee - HOTEL_COVERED_PER_NIGHT);
    if(hotelFee < 0) {
        hotelFee = 0;
    }
    return hotelFee;
}

// Calculate Breakfast
int calculateBreakfast() {// company BREAKFAST_COVERED = 9
    /* On first day, breakfast is allowed if the time of departure is before 7am. On the last day, breakfast is allowed if arrival is after 8am. */
    int breakfastNumber = 0;
    if(departure < 7 && arrival > 8) {// on day 1 depature < 7am and arrival on last day > 8am. both
        breakfastNumber = days;
    } else if (departure < 7 && arrival < 8) {// departure < 7am and arrival < 8am. no arrival breakfast
        breakfastNumber = days - 1;
    } else if (departure > 7 && arrival > 8) {// departure > 7am and arrival > 8am. no departure breakfast
        breakfastNumber = days - 1;
    } else if (departure > 7 && arrival < 8) {// 1st day and last day no breakfast. departure > 7am && arrival < 8am
        breakfastNumber = days - 2;
    }
    breakfast = (breakfast - BREAKFAST_COVERED) * breakfastNumber;
    if(breakfast < 0) {
        breakfast = 0;
    }
    return breakfast;
}

// Calculate Lunch
int calculateLunch() {// company LUNCH_COVERED = 12
    /* On the first day, lunch is allowed if time of departure is before 12pm. On last day, lunch is allowed if the time of arrival is after 1pm */
    int lunchNumber = 0;
    if(departure < 12 && arrival > 1) {// on day 1 departure < 12pm and arrival on last day > 1pm. both allowed
        lunchNumber = days;
    } else if(departure < 12 && arrival < 1) {// departure < 12pm and arrival < 1pm. no arrival lunch
        lunchNumber = days - 1;
    } else if(departure > 12 && arrival > 1) {// departure > 12pm and arrival > 1pm. no departure lunch
        lunchNumber = days - 1;
    } else if(departure > 12 && arrival < 1) {// 1st day and last day no lunch. departure > 12pm && arrival < 1pm
        lunchNumber = days - 2;
    }
    lunch = (lunch - LUNCH_COVERED) * lunchNumber;
    if(lunch < 0) {
        lunch = 0;
    }
    return lunch;
}

// Calculate Dinner
int calculateDinner() {// company DINNER_COVERED = 16
    int dinnerNumber = 0;
    if(departure < 6 && arrival > 7) {// on day 1 departure < 6pm and arrival on last day > 7pm. both allowed
        dinnerNumber = days;
    } else if(departure < 6 && arrival < 7) {// departure < 6pm and arrival < 7pm. no arrival dinner
        dinnerNumber = days - 1;
    } else if(departure > 6 && arrival > 7) {// depature > 6pm and arrival > 7pm. no departure dinner
        dinnerNumber = days - 1;
    } else if(departure > 6 && arrival < 7) {// 1st day and last day no dinner. departure > 6pm && arrival < 7pm
        dinnerNumber = days - 2;
    }
    dinner = (dinner - DINNER_COVERED) * dinnerNumber;
    if(dinner < 0) {
        dinner = 0;
    }
    return dinner;
}

// Calculate Meals
int calculateMealFees() {
    return calculateBreakfast() + calculateLunch() + calculateDinner();
}