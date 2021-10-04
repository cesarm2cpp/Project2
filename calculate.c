#include "calculate.h"
/* TODO: 1.add meal vars breakfast, lunch, and dinner to main
2.change departer to departure
*/  

// Calculate Miles Driven in Private Vehicle
int calculateMiles(int miles) {// $0.27 per mile driven
    double milesDriven;
    milesDriven = miles * GAS_PRICE_PER_MILE;
    
    return milesDriven;
}

// Calculate Parking Fees
int calculateParkingFees(double parkingFees, int parkingDays) {// company PARKING_COVERED_PER_DAY = 6
    parkingFees = parkingFees - (PARKING_COVERED_PER_DAY * parkingDays);
    if(parkingFees < 0) {
        parkingFees = 0;
    }
    return parkingFees;
}

// Calculate Taxi Fees
int calculateTaxiFees(char taxiUse[10], double taxiFee, int taxiDays) {// company TAXI_COVERED_PER_DAY = 10
    if(taxiUse, 'y') {
        taxiFee = taxiFee - (TAXI_COVERED_PER_DAY * taxiDays);
        if(taxiFee < 0) {
            taxiFee = 0;
        }
    } 
    
    return taxiFee;
}

// Calculate Hotel Fees
int calculateHotelFees(double hotelFee, int hotelDays, int totalDays) {// company HOTEL_COVERED_PER_NIGHT = 90
    hotelDays = totalDays - 1;
    hotelFee = hotelFee - (HOTEL_COVERED_PER_NIGHT * (hotelDays));
    if(hotelFee < 0) {
        hotelFee = 0;
    }
    return hotelFee;
}

// Calculate Breakfast
int calculateBreakfast(double arrivalTime, double departTime, int totalDays, double breakfastFees) {// company BREAKFAST_COVERED = 9
    /* On first day, breakfast is allowed if the time of departure is before 7am. On the last day, breakfast is allowed if arrival is after 8am. */
    printf("Total Days BfOne: %d\n", totalDays);
    double breakfast; // company= $9, if(negative): var=0
    int breakfastNumber = 0;
    printf("Depart Breakfast: %d\n", departTime);
    printf("Arrival Breakfast: %d\n", arrivalTime);
    if(departTime < 7 && arrivalTime > 8) {// on day 1 depature < 7am and arrival on last day > 8am. both
        breakfastNumber = totalDays;
        breakfast = breakfastFees - (BREAKFAST_COVERED * breakfastNumber);
    } else if (departTime > 7 && arrivalTime > 8) {// departure > 7am and arrival > 8am. no departure breakfast
        breakfastNumber = totalDays - 1;
        breakfast = breakfastFees - (BREAKFAST_COVERED * breakfastNumber);
    } else if (departTime < 7 && arrivalTime < 8) {// departure < 7am and arrival < 8am. no arrival breakfast
        breakfastNumber = totalDays - 1;
        breakfast = breakfastFees - (BREAKFAST_COVERED * breakfastNumber);
    } else if (departTime > 7 && arrivalTime < 8) {// 1st day and last day no breakfast. departure > 7am && arrival < 8am
        breakfastNumber = totalDays - 2;
        breakfast = breakfastFees - (BREAKFAST_COVERED * breakfastNumber);
    }
    if(breakfast < 0) {
        breakfast = 0;
    }
    
    return breakfast;
}

// Calculate Lunch
int calculateLunch(double arrivalTime, double departTime, int totalDays, double lunchFees) {// company LUNCH_COVERED = 12
    /* On the first day, lunch is allowed if time of departure is before 12pm. On last day, lunch is allowed if the time of arrival is after 1pm */
    printf("Total Days LuOne: %d\n", totalDays);
    double lunch; // company= $12, if(negative): var=0
    int lunchNumber = 0;
    printf("Depart Lunch: %d\n", departTime);
    printf("Arrival Lunch: %d\n", arrivalTime);
    if(departTime < 12 && arrivalTime > 13) {// on day 1 departure < 12pm and arrival on last day > 1pm. both allowed
        lunchNumber = totalDays;
        lunch = lunchFees - (LUNCH_COVERED * lunchNumber);
    } else if(departTime < 12 && arrivalTime < 13) {// departure < 12pm and arrival < 1pm. no arrival lunch
        lunchNumber = totalDays - 1;
        lunch = lunchFees - (LUNCH_COVERED * lunchNumber);
    } else if(departTime > 12 && arrivalTime > 13) {// departure > 12pm and arrival > 1pm. no departure lunch
        lunchNumber = totalDays - 1;
        lunch = lunchFees - (LUNCH_COVERED * lunchNumber);
    } else if(departTime > 12 && arrivalTime < 13) {// 1st day and last day no lunch. departure > 12pm && arrival < 1pm
        lunchNumber = totalDays - 2;
        lunch = lunchFees - (LUNCH_COVERED * lunchNumber);
    }
    if(lunch < 0) {
        lunch = 0;
    }
    printf("Total Days LuTwo: %d\n", totalDays);
    return lunch;
}

// Calculate Dinner
int calculateDinner(double arrivalTime, double departTime, int totalDays, double dinnerFees) {// company DINNER_COVERED = 16
    double dinner; // company= $16, if(negative): var=0
    int dinnerNumber = 0;
    if(departTime < 18 && arrivalTime > 19) {// on day 1 departure < 6pm and arrival on last day > 7pm. both allowed
        dinnerNumber = totalDays;
    } else if(departTime < 18 && arrivalTime < 19) {// departure < 6pm and arrival < 7pm. no arrival dinner
        dinnerNumber = totalDays - 1;
    } else if(departTime > 18 && arrivalTime > 19) {// depature > 6pm and arrival > 7pm. no departure dinner
        dinnerNumber = totalDays - 1;
    } else if(departTime > 18 && arrivalTime < 19) {// 1st day and last day no dinner. departure > 6pm && arrival < 7pm
        dinnerNumber = totalDays - 2;
    }
    dinner = (dinner - DINNER_COVERED) * dinnerNumber;
    if(dinner < 0) {
        dinner = 0;
    }
    return dinner;
}

// Calculate Meals
int calculateMealFees(double arrivalTime, double departTime, int totalDays, double breakfastFees, double lunchFees, double dinnerFees) {
    return calculateBreakfast(arrivalTime, departTime, totalDays, breakfastFees) + calculateLunch(arrivalTime, departTime, totalDays, lunchFees) + calculateDinner(arrivalTime, departTime, totalDays, dinnerFees);
}