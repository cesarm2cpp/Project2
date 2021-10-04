#include "calculate.h"

// for car rental
float *calCarRental()
{ static float costs[2];
  int ans1, ans, miles;
  float amount = 0;
  printf("\nIs there any car rental occured in this trip(Y:1/N:0):");
  scanf("%d", &ans);
  while (ans != 0)
  {
  if (ans == 1)
       printf("\nIs it a private car or a public transport car?(Private:1/Public:2):");
            scanf("%d", &ans1);
            if (ans1 == 1)
            {
                printf("\nHow many miles traveled?:");
                scanf("%d", &miles);
                if (miles <= 0)
                {
                    printf("\nPlease enter a valid number (>0)!");
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
                printf("\nHow much expense done?:");
                scanf("%f", &amount);
                if (amount <= 0)
                {
                    printf("\nPlease enter a valid amount (>0)!");
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
            printf("\nPlease enter a valid choice Y or N!\n");
        }
    }
    return 0;
}