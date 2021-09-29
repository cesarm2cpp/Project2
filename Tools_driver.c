#include "Tools.h"
#include <limits.h>


/* get integer input from user */
int getUserInt(char *prompt)
{
    int userInput;
    do
    {
        printf(prompt);
        scanf("%d",&userInput);
    } while (userInput < 0);
    return userInput;
}

/* get double input from user */
double getDouble(char *prompt)
{
    double userInput;
    do
    {
        printf(prompt);
        scanf("%d",&userInput);
    } while (userInput < 0);
    return userInput;
}

/* compare and return the user input in assigned range*/
double getBoundedNum(char *prompt, double lowBound, double highBound)
{
    double userInput;
    while(1) // any non-zero number used as condition is treated as TRUE
    {
        userInput = getDouble(prompt);
        if (lowBound <= userInput && userInput <= highBound)
            break;
        printf("\nPlease enter a value in the range [%d..%d] ",lowBound,highBound);
    }
    return userInput;
}

/* get the lowerbound b/w given lower bound and max*/
double getLowerBoundedNum(char *prompt, double lowBound)
{
    return getBoundedNum(prompt, lowBound, INT_MAX);        // INT_MAX is defined in <limit.h>
}

/* get positive double/float/integer */
double getPositiveNum(char *prompt)
{
    return getLowerBoundedNum(prompt,0);
}