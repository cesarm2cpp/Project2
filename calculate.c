#include <stdio.h>
#include "calculate.h"

/* TODO: 1.add meal vars breakfast, lunch, and dinner to main
2.change departer to departure
<<<<<<< HEAD
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
    if(parkingFees < 0.0) {
        parkingFees = 0.00;


//-----
// cllculate  car rental
float *calCarRental()
{
    static float costs[2];
    int ans1, ans, miles;
    float amount = 0;
    printf("\nIs there any car rental occured in this trip(Y:1 / N:0):");
    scanf("%d", &ans);
    while (ans != 0)
    {
        if (ans == 1)
        {
  printf("\nIs it a private car or a public transport car?(Private:1/Public:2):");
    scanf("%d", &ans1);
  if (ans1 == 1)
  {
  printf("\nMiles traveled?:");
 scanf("%d", &miles);
    if (miles <= 0)
  {
   printf("\nEnter valid number (>0)!");
 continue;
 }
  else
  {
  amount = miles * 0.27;
  costs[0] = amount;
  costs[1] = amount;
    return costs;
     }
    }
   if (ans1 == 2)
    {
 printf("\nHow much expense ?:");
 scanf("%f", &amount);
 if (amount <= 0)
 {
printf("\nEnter valid amount (>0)!");
 continue;
 }
 else if (amount <= 10)
  {
return 0;
 }
  else
  {
  costs[0] = amount;
amount = amount - 10;
 costs[1] = amount;
  return costs;
  }
 }
 }
    else
    {
  printf("\nPlease enter valid choice Y or N!\n");
  }
    }
    return 0;
}
//----

// Calculate Taxi Fees
int calculateTaxiFees(char taxiUse, double taxiFee) {// company TAXI_COVERED_PER_DAY = 10
    if(taxiUse == 'y') {
        taxiFee = (taxiFee - TAXI_COVERED_PER_DAY);
        if(taxiFee < 0) {
            taxiFee = 0;
        }
    } else {
        taxiFee = 0;
    }
    
    return taxiFee;
}

// Calculate Hotel Fees
int calculateHotelFees(double hotelFee) {// company HOTEL_COVERED_PER_NIGHT = 90
    hotelFee = (hotelFee - HOTEL_COVERED_PER_NIGHT);
    if(hotelFee < 0) {
        hotelFee = 0;
    }
    return hotelFee;
}
// ------
//calculate breakfast
float *calBreakfast(float amount)
{
    static float costs[2];
    costs[0] = amount;
    if (amount <= 9)
    {
        costs[1] = 0;
    }
    else
    {
        amount = amount - 9;
        costs[1] = amount;
    }
    return costs;
}
// -------
// Calculate Breakfast
int calculateBreakfast(double departTime, double arrivalTime, int totalDays) {// company BREAKFAST_COVERED = 9
    /* On first day, breakfast is allowed if the time of departure is before 7am. On the last day, breakfast is allowed if arrival is after 8am. */
    double breakfast; // company= $9, if(negative): var=0
    int breakfastNumber = 0;
    if(departTime < 7 && arrivalTime > 8) {// on day 1 depature < 7am and arrival on last day > 8am. both
        breakfastNumber = totalDays;
    } else if (departTime < 7 && arrivalTime < 8) {// departure < 7am and arrival < 8am. no arrival breakfast
        breakfastNumber = totalDays - 1;
    } else if (departTime > 7 && arrivalTime > 8) {// departure > 7am and arrival > 8am. no departure breakfast
        breakfastNumber = totalDays - 1;
    } else if (departTime > 7 && arrivalTime < 8) {// 1st day and last day no breakfast. departure > 7am && arrival < 8am
        breakfastNumber = totalDays - 2;
    }
    breakfast = (breakfastFees - BREAKFAST_COVERED) * breakfastNumber;
    if(breakfast < 0) {
        breakfast = 0;
    }
    return breakfast;
}

// Calculate Lunch
int calculateLunch(double departTime, double arrivalTime, int totalDays) {// company LUNCH_COVERED = 12
    /* On the first day, lunch is allowed if time of departure is before 12pm. On last day, lunch is allowed if the time of arrival is after 1pm */
    double lunch; // company= $12, if(negative): var=0
    int lunchNumber = 0;
    if(departTime < 12 && arrivalTime > 1) {// on day 1 departure < 12pm and arrival on last day > 1pm. both allowed
        lunchNumber = totalDays;
    } else if(departTime < 12 && arrivalTime < 1) {// departure < 12pm and arrival < 1pm. no arrival lunch
        lunchNumber = totalDays - 1;
    } else if(departTime > 12 && arrivalTime > 1) {// departure > 12pm and arrival > 1pm. no departure lunch
        lunchNumber = totalDays - 1;
    } else if(departTime > 12 && arrivalTime < 1) {// 1st day and last day no lunch. departure > 12pm && arrival < 1pm
        lunchNumber = totalDays - 2;
    }
    lunch = (lunch - LUNCH_COVERED) * lunchNumber;
    if(lunch < 0) {
        lunch = 0;
    }
    return lunch;
}

// Calculate Dinner
int calculateDinner(double departTime, double arrivalTime, int totalDays) {// company DINNER_COVERED = 16
    double dinner; // company= $16, if(negative): var=0
    int dinnerNumber = 0;
    if(departTime < 6 && arrivalTime > 7) {// on day 1 departure < 6pm and arrival on last day > 7pm. both allowed
        dinnerNumber = totalDays;
    } else if(departTime < 6 && arrivalTime < 7) {// departure < 6pm and arrival < 7pm. no arrival dinner
        dinnerNumber = totalDays - 1;
    } else if(departTime > 6 && arrivalTime > 7) {// depature > 6pm and arrival > 7pm. no departure dinner
        dinnerNumber = totalDays - 1;
    } else if(departTime > 6 && arrivalTime < 7) {// 1st day and last day no dinner. departure > 6pm && arrival < 7pm
        dinnerNumber = totalDays - 2;
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
// ------
//calculate meals
float *calMealCost(int numOfDays, float time[2])
{
    float breakfast, lunch, dinner;
    static float *breakfastCosts, *lunchCosts, *dinnerCosts, *totalCosts;
    int ans;
    int run = 1;
    printf("\nIs this is a first day,last day or middle day of trip?(1:first/3:last/2:middle):");
    scanf("%d", ans);
    switch (ans)
    {
    case 1:
        if (numOfDays == 1)
        {
        if (time[0] <= 7)
        {
      if (time[1] > 13 && time[1] < 19)
           {
   tun = 1;
       while (run == 1)
           {
        printf("\nEnter amount for breakfast:");
        scanf("%f", &breakfast);
       printf("\nEnter amount for lunch:");
        scanf("%f", &lunch);
         printf("\nEnter amount for Dinner:");
       scanf("%f", &dinner);
      if (breakfast < 0 || lunch < 0 || dinner < 0)
         {
        printf("Invalid cost input!Try Again.");
        continue;
          }
          else
           {
      dinnerCosts = calDinner(dinner);
       lunchCosts = calLunch(lunch);
       breakfastCosts = calBreakfast(breakfast);
    totalCosts[0] = breakfastCosts[0] + lunchCosts[0] + dinnerCosts[0];
     totalCosts[1] = breakfastCosts[1] + lunchCosts[1] + dinnerCosts[1];
                      run = 0;
                 }
                  }
                }
                if (time[1] > 19)
                {
                    run = 1;
                    while (run == 1)
                    {
         printf("\nEnter amount for breakfast:");
         scanf("%f", &breakfast);
            printf("\nEnter amount for lunch:");
       scanf("%f", &lunch);
         if (breakfast < 0 || lunch < 0)
            {
            printf("\nInvalid cost input!Try Again.");
             continue;
              }
                else
               {
      reakfastCosts = calBreakfast(breakfast);
        lunchCosts = calLunch(lunch);
             totalCosts[0] = breakfastCosts[0] + lunchCosts[0];
          totalCosts[1] = breakfastCosts[1] + lunchCosts[1];
                  run = 0;
                 }
              }
          }
        }
          if (time[0] > 7 && time[0] < 12)
         {
             if (time[1] > 13 && time[1] < 19)
              {
              run = 1;
                 while (run == 1)
              {
      rintf("\nEnter amount for lunch:");
      canf("%f", &lunch);
      if (lunch < 0)
           {
           printf("\nInvalid cost input!Try Again.");
            continue;
            }
           else
            {
            lunchCosts = calLunch(lunch);
         totalCosts[0] = lunchCosts[0];
            totalCosts[1] = lunchCosts[1];
           run = 0;
               }
            }
             }
               else
               {
                    run = 1;
                 while (run == 1)
           {
        printf("\nEnter amount for lunch:");
      scanf("%f", &lunch);
      printf("\nEnter amount for Dinner:");
       scanf("%f", &dinner);
                if (lunch < 0 || dinner < 0)
            {
                 printf("\nInvalid cost input!Try Again.");
               continue;
                   }
              else
                 {
      dinnerCosts = calDinner(dinner);
       lunchCosts = calLunch(lunch);
        totalCosts[0] = dinnerCosts[0] + lunchCosts[0];
         totalCosts[1] = dinnerCosts[1] + lunchCosts[1];
                           run = 0;
             }
         }
            }
         }
         if (time[0] > 12 && time[0] < 18)
         {
            run = 1;
          while (run == 1)
           {
          printf("\nEnter amount for Dinner:");
          scanf("%f", &dinner);
           if (dinner < 0)
             {
           printf("\nInvalid cost input!Try Again.");
             continue;
          }
          else
         {
      dinnerCosts = calDinner(dinner);
         totalCosts[0] = dinnerCosts[0];
        totalCosts[1] = dinnerCosts[1];
                       run = 0;
              }
            }
          }
        }
        else
        {
            if (time[0] <= 7)
         {
            run = 1;
            while (run == 1)
         {
      printf("\nEnter amount for breakfast:");
            scanf("%f", &breakfast);
        printf("\nEnter amount for lunch:");
        scanf("%f", &lunch);
          printf("\nEnter amount for Dinner:");
          scanf("%f", &dinner);
        if (breakfast < 0 || lunch < 0 || dinner < 0)
                {
                printf("\nInvalid cost input!Try Again.");
                continue;
                 }
             else
                    {
             dinnerCosts = calDinner(dinner);
               lunchCosts = calLunch(lunch);
            breakfastCosts = calBreakfast(breakfast);
           totalCosts[0] = breakfastCosts[0] + lunchCosts[0] + dinnerCosts[0];
             totalCosts[1] = breakfastCosts[1] + lunchCosts[1] + dinnerCosts[1];
            run = 0;
            }
           }
         }
          if (time[0] > 7 && time[0] <= 12)
           {
           run = 1;
        while (run == 1)
            {
      printf("\nEnter amount for lunch:");
        scanf("%f", &lunch);
         printf("\nEnter amount for Dinner:");
         scanf("%f", &dinner);
        if (lunch < 0 || dinner < 0)
       {
           printf("\nInvalid cost input!Try Again.");
          continue;
                    }
                    else
                    {
           dinnerCosts = calDinner(dinner);
           lunchCosts = calLunch(lunch);
           totalCosts[0] = dinnerCosts[0] + lunchCosts[0];
           totalCosts[1] = dinnerCosts[1] + lunchCosts[1];
                    run = 0;
              }
               }
           }
            if (time[0] > 12 && time[0] <= 18)
          {
                run = 1;
               while (run == 1)
            {
               printf("\nEnter amount for Dinner:");
     scanf("%f", &dinner);
             if (dinner < 0)
            {
         printf("\nInvalid cost input!Try Again.");
            continue;
           }
           else
              {
      dinnerCosts = calDinner(dinner);
           totalCosts[0] = dinnerCosts[0];
          totalCosts[1] = dinnerCosts[1];
                run = 0;
                    }
                }
            }
        }
        break;
    case 2:
        run = 1;
        while (run == 1)
        {
          printf("\nEnter amount for breakfast:");
       scanf("%f", &breakfast);
           printf("\nEnter amount for lunch:");
        scanf("%f", &lunch);
      printf("\nEnter amount for Dinner:");
           scanf("%f", &dinner);
           if (breakfast < 0 || lunch < 0 || dinner < 0)
           {
          printf("\nInvalid cost input!Try Again.");
         continue;
           }
          else
           {
          dinnerCosts = calDinner(dinner);
         lunchCosts = calLunch(lunch);
           breakfastCosts = calBreakfast(breakfast);
        totalCosts[0] = breakfastCosts[0] + lunchCosts[0] + dinnerCosts[0];
           totalCosts[1] = breakfastCosts[1] + lunchCosts[1] + dinnerCosts[1];
          run = 0;
            }
        }
        break;
    case 3:
        if (noOfDays > 1)
        {
        if (time[1] > 8 && time[1] <= 13)
          {
          run = 1;
          while (run == 1)
         {
           printf("\nEnter amount for breakfast:");
        scanf("%f", &breakfast);
         if (breakfast < 0)
          {
         printf("\nInvalid cost input!Try Again.");
            continue;
        }
                else
           {
           breakfastCosts = calBreakfast(breakfast);
        totalCosts[0] = breakfastCosts[0];
       totalCosts[1] = breakfastCosts[1];
       run = 0;
            }
           }
          }
            if (time[1] > 13 && time[1] <= 19)
            {
           run = 1;
           while (run == 1)
          {
           printf("\nEnter amount for breakfast:");
          scanf("%f", &breakfast);
          printf("\nEnter amount for lunch:");
         scanf("%f", &lunch);
          if (breakfast < 0 || lunch < 0)
           {
           printf("\nInvalid cost input!Try Again.");
            continue;
            }
          else
        {
         lunchCosts = calLunch(lunch);
           breakfastCosts = calBreakfast(breakfast);
            totalCosts[0] = breakfastCosts[0] + lunchCosts[0];
          totalCosts[1] = breakfastCosts[1] + lunchCosts[1];
            run = 0;
          }
         }
         }
        if (time[1] > 19)
        {
         run = 1;
          while (run == 1)
    {
      printf("\nEnter amount for breakfast:");
       scanf("%f", &breakfast);
    printf("\nEnter amount for lunch:");
        scanf("%f", &lunch);
      printf("\nEnter amount for Dinner:");
      scanf("%f", &dinner);
       if (breakfast < 0 || lunch < 0 || dinner < 0)
         {
       printf("\nInvalid cost input!Try Again.");
         continue;
         }
          else
         {
    dinnerCosts = calDinner(dinner)
   lunchCosts = calLunch(lunch);
    breakfastCosts = calBreakfast(breakfast);
     totalCosts[0] = breakfastCosts[0] + lunchCosts[0] + dinnerCosts[0];
     totalCosts[1] = breakfastCosts[1] + lunchCosts[1] + dinnerCosts[1];
                     run = 0;
           }
         }
         }
        }
        break;
    default:
        printf("\nInvalid choice!Try again!");
        break;
    }
 return totalCosts;
}
// --------
