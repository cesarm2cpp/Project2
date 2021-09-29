#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <string.h>
// gas price
const double GAS_PRICE_PER_MILE = 0.27;

// company allowance
const int PARKING_COVERED_PER_DAY = 6;
const int TAXI_COVERED_PER_DAY = 10;
const int HOTEL_COVERED_PER_NIGHT = 90;

int getUserInt(char *prompt);  /* An example function declaration */
double getUserDouble(char *prompt);
double getBoundedNum(char *prompt, double lowBound, double highBound);
double getLowerBoundedNum(char *prompt, double lowBound);
double getPositiveNum(char *prompt);

#endif 