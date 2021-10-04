# **Project 2 - Travel Expense (C programming_cs2600)**

## Team members 🤘
| Name        | Task |
| ------      | ----------- |
| Van Huynh   | Implement functions in Main.c and 2 tool files
|             | Help teammates debugs all files, optimize code, set up built structure
| Cesar Martinez| Implement Main.c 
|               | Help teammates debug calculate.c and calculate.h, optimize code
| Abigail Pinkus| Implement calculate.c and calculate.h files
|               | Debug calculation files and optimize user inputs functions
| Keon Joong Kim| Attemped implementing function for rental-car-price calculation


## Build Structure

###  Must-have files  ✔️
- Main.c 
- Tools.h           (tool functions that we can utilize)
- Tools_driver.c    (tool functions that we can utilize)
- Calculate.h       (main functions for the project)
- Calculate.c       (main functions for the project)


### *Possible get-input and validate-input functions (either in Main.c or in Calculation.c)
- get total days
- get first day departure time 🧭
- get last day arrival time 🧭

- get round-trip airfare price$ ✈️
- get car rental price$ 🚙
- get miles driven (when eval, assume $0.27 per mile)
- get parking fees ($6 waived per day) 🅿️
- get taxi fees ($10 waived per day) 🚖
- get conference/registration fees
- hotel expenses ($90 waived per night) 🏨
- amount of each meal eaten (this is its own bag of worms)


### Possible Calculation functions for the project
- calculate total expenses incurred by the businessperson
- calculate meal expense
- calculate total company allowable expenses
- calculate employees' excess expense that need reimbursment
- calculate employees' saved amount when the expenses were under the total allowed
- display all results

### Some challenges in the process
> Abigail, "I did the created a branch and created the calculate.c file and calculate.h file where I calculated the mile fees, parking fees, taxi fees, hotel fees, and meal fees with breakfast lunch and dinner. the meal fees was not working however because the depart and arrival times where == 0 in the in the calc file. I also did debugging on my branch to make sure everything worked on my end on its own."