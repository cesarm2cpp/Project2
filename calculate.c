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

// // Calculate Hotel Fees
// int calculateHotelFees(double hotelFee) {// company HOTEL_COVERED_PER_NIGHT = 90
//     hotelFee = (hotelFee - HOTEL_COVERED_PER_NIGHT);
//     if(hotelFee < 0) {
//         hotelFee = 0;
//     }
//     return hotelFee;
// }

// // Calculate Breakfast
// int calculateBreakfast(double departTime, double arrivalTime, int totalDays) {// company BREAKFAST_COVERED = 9
//     /* On first day, breakfast is allowed if the time of departure is before 7am. On the last day, breakfast is allowed if arrival is after 8am. */
//     double breakfast; // company= $9, if(negative): var=0
//     int breakfastNumber = 0;
//     if(departureTime < 7 && arrivalTime > 8) {// on day 1 depature < 7am and arrival on last day > 8am. both
//         breakfastNumber = totalDays;
//     } else if (departureTime < 7 && arrivalTime < 8) {// departure < 7am and arrival < 8am. no arrival breakfast
//         breakfastNumber = totalDays - 1;
//     } else if (departureTime > 7 && arrivalTime > 8) {// departure > 7am and arrival > 8am. no departure breakfast
//         breakfastNumber = totalDays - 1;
//     } else if (departureTime > 7 && arrivalTime < 8) {// 1st day and last day no breakfast. departure > 7am && arrival < 8am
//         breakfastNumber = totalDays - 2;
//     }
//     breakfast = (breakfastFees - BREAKFAST_COVERED) * breakfastNumber;
//     if(breakfast < 0) {
//         breakfast = 0;
//     }
//     return breakfast;
// }

// // Calculate Lunch
// int calculateLunch(double departTime, double arrivalTime, int totalDays) {// company LUNCH_COVERED = 12
//     /* On the first day, lunch is allowed if time of departure is before 12pm. On last day, lunch is allowed if the time of arrival is after 1pm */
//     double lunch; // company= $12, if(negative): var=0
//     int lunchNumber = 0;
//     if(departureTime < 12 && arrivalTime > 1) {// on day 1 departure < 12pm and arrival on last day > 1pm. both allowed
//         lunchNumber = totalDays;
//     } else if(departureTime < 12 && arrivalTime < 1) {// departure < 12pm and arrival < 1pm. no arrival lunch
//         lunchNumber = totalDays - 1;
//     } else if(departureTime > 12 && arrivalTime > 1) {// departure > 12pm and arrival > 1pm. no departure lunch
//         lunchNumber = totalDays - 1;
//     } else if(departureTime > 12 && arrivalTime < 1) {// 1st day and last day no lunch. departure > 12pm && arrival < 1pm
//         lunchNumber = totalDays - 2;
//     }
//     lunch = (lunch - LUNCH_COVERED) * lunchNumber;
//     if(lunch < 0) {
//         lunch = 0;
//     }
//     return lunch;
// }

// // Calculate Dinner
// int calculateDinner(double departeTime, double arrivalTime, int totalDays) {// company DINNER_COVERED = 16
//     double dinner; // company= $16, if(negative): var=0
//     int dinnerNumber = 0;
//     if(departureTime < 6 && arrivalTime > 7) {// on day 1 departure < 6pm and arrival on last day > 7pm. both allowed
//         dinnerNumber = totalDays;
//     } else if(departureTime < 6 && arrivalTime < 7) {// departure < 6pm and arrival < 7pm. no arrival dinner
//         dinnerNumber = totalDays - 1;
//     } else if(departureTime > 6 && arrivalTime > 7) {// depature > 6pm and arrival > 7pm. no departure dinner
//         dinnerNumber = totalDays - 1;
//     } else if(departureTime > 6 && arrivalTime < 7) {// 1st day and last day no dinner. departure > 6pm && arrival < 7pm
//         dinnerNumber = totalDays - 2;
//     }
//     dinner = (dinner - DINNER_COVERED) * dinnerNumber;
//     if(dinner < 0) {
//         dinner = 0;
//     }
//     return dinner;
// }

// // Calculate Meals
// int calculateMealFees() {
//     return calculateBreakfast() + calculateLunch() + calculateDinner();
// }