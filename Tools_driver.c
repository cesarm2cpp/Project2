#include "Tools.h"

//  Declaration for the definition from Tools.h
const float GAS_PRICE_PER_MILE = 0.27;
typedef enum { F, T } boolean; // 1 way to use boolean w/o stdbool library

/* FUNCTION DEFINITIONS */
/* clean the input buffer */
void clean_stdin()
{    
  while ( getchar() != '\n' );
}

/* get YES or NO answer based on 1 and 0 */
int getBool(char *prompt)
{
    char userInput;
    while (1)
    {
        printf(prompt);
        scanf("%c", &userInput);
        switch (userInput)
        {
            case 'y': case 'Y':	return T;
            case 'n': case 'N':	return F;
            //default
        }
        printf("Please enter Y(yes) or N(no) only\n");
        clean_stdin();
    }
}

/* get integer input from user */
int getUserInt(char *prompt)
{
    int userInput;
    while(1)
    {
        printf("%s",prompt);
        scanf("%d",&userInput);
        if(userInput >= 0)  return userInput;
        printf("*Note: No negative number please...\n");
        clean_stdin();
    }
}

/* get double input from user */
double getUserDouble(char *prompt)
{
    double userInput;
    while(1)
    {
        printf(prompt);
        scanf("%lf",&userInput);
        if(userInput >= 0)  return userInput;
        printf("*Note: No negative number please...\n");
        clean_stdin();
    }
}

/* compare and return the user input in assigned range*/
double getBoundedNum(char *prompt, double lowBound, double highBound)
{
    double userInput;
    while(1) // any non-zero number used as condition is treated as TRUE
    {
        userInput = getUserDouble(prompt);
        if (lowBound <= userInput && userInput <= highBound)
            break;
        printf("\nPlease enter a value in the range [%lf..%lf] ",lowBound,highBound);
    }
    return userInput;
}

/* get the lowerbound b/w given lower bound and max*/
double getLowerBoundedNum(char *prompt, double lowBound)
{
    return getBoundedNum(prompt, lowBound, INT_MAX);   // INT_MAX is defined in <limit.h>
}

/* get positive double/float/integer */
double getPositiveNum(char *prompt)
{
    return getLowerBoundedNum(prompt,0);
}

/* get float input from user */
float getUserFloat(char *prompt)
{
    float userInput;
    while(1)
    {
        printf("%s",prompt);
        scanf("%f",&userInput);
        if(userInput >= 0)  return userInput;
        printf("*Note: No negative number please...\n");
        clean_stdin();
    }
}
float getBoundedFloat(char *prompt, float lowBound, float highBound)
{
    float userInput;
    while(1) // any non-zero number used as condition is treated as TRUE
    {
        userInput = getUserFloat(prompt);
        if (lowBound <= userInput && userInput <= highBound)
            break;
        printf("Please enter a value in the range [%.2f..%.2f]\n",lowBound,highBound);
    }
    return userInput;
}