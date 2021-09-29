#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <string.h>
#include <limits.h>

// Definition in this file, declaration is in Tools_driver.c
extern const double GAS_PRICE_PER_MILE;

enum {PARKING_COVERED_PER_DAY = 6,TAXI_COVERED_PER_DAY = 10,HOTEL_COVERED_PER_NIGHT = 90};
// company allowance
// const int PARKING_COVERED_PER_DAY = 6;
// const int TAXI_COVERED_PER_DAY = 10;
// const int HOTEL_COVERED_PER_NIGHT = 90;

int getUserInt(char *prompt); 
double getUserDouble(char *prompt);
double getBoundedNum(char *prompt, double lowBound, double highBound);
double getLowerBoundedNum(char *prompt, double lowBound);
double getPositiveNum(char *prompt);

#endif 