#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <string.h>
#include <limits.h>

/* Definition in this file, declaration is in Tools_driver.c */
extern const double GAS_PRICE_PER_MILE;

/* using enum instead of making definition and declaration across 2 files */
// this is the list of any service covered by the company
enum {PARKING_COVERED_PER_DAY = 6,TAXI_COVERED_PER_DAY = 10,HOTEL_COVERED_PER_NIGHT = 90,BREAKFAST_COVERED=9, LUNCH_COVERED=12,DINNER_COVERED=16};

/*This way of declaration works normaly in C++ but not in C
const int PARKING_COVERED_PER_DAY = 6;
const int TAXI_COVERED_PER_DAY = 10;
const int HOTEL_COVERED_PER_NIGHT = 90;*/
int getUserInt(char *prompt); 
double getUserDouble(char *prompt);
double getBoundedNum(char *prompt, double lowBound, double highBound);
double getLowerBoundedNum(char *prompt, double lowBound);
double getPositiveNum(char *prompt);

#endif 