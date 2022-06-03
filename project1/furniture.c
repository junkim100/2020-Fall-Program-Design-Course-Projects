//
// COP 3514 – Fall Semester, 2020
//
// Project 1
//
// Dong Jun Kim
//


#include <stdio.h>

//global variables
int first_month= 0;
int monthly_cost = 0;
int maximum = 0;


//scans user input of furniture selection and sets variable values baseed on the selection
//returns 1 meaning continue and 0 for error that is used as a parameter for calculate()
int selection() {
    
    int selection;

    //scans furniture selection
    printf("Please select from the following menu: 1. Sofa, 2. Loveseat, 3. 4 Post Bed, 4. Dresser 5. Kitchen Table\nEnter furniture selection: ");
    scanf("%d", &selection);

    //sets variable values based on the selection the user made
    switch (selection) {
    case 1:

        first_month = 20;
        monthly_cost = 12;
        maximum = 100;
        return 1;
    
    case 2:

        first_month = 15;
        monthly_cost = 10;
        maximum = 80;
        return 1;
    
    case 3:

        first_month = 25;
        monthly_cost = 8;
        maximum = 105;
        return 1;
    
    case 4:

        first_month = 10;
        monthly_cost = 5;
        maximum = 50;
        return 1;
    
    case 5:

        first_month = 25;
        monthly_cost = 10;
        maximum = 120;
        return 1;
    
    //prints error message if input is invalid
    default:
        printf("\nInvalid input. The input should be in the range of 1 to 5.\n");
        return 0;

    }

}


//gets user input of months to rent and calculates the amount user has to pay using the variable values set from selection() then prints total amount user has to pay
//gets selection() as a parameter and continues if selection() is 1 and stops if selection() is 0
void calculate (int i) {

    int total_amount, month_rented, year_rented, month_remainder;

    //no errors on selection(), run code
    if (i == 1) {

        //scans number of months to rent
        printf("\nEnter months rented: ");
        scanf("%d", &month_rented);

        //converts total months to years and months
        year_rented = month_rented / 12;
        month_remainder = month_rented % 12;

        //prints error message if input is invalid
        if (month_rented < 1) {
            printf("\nInvalid input. Enter a positive number for months rented.\n");
        } 
        
        //case1: less than a year
        else if (year_rented == 0) {

            //first calculate total amount ignoring maximum per year
            total_amount = first_month + monthly_cost * (month_rented - 1);

            //then change total amount to maximum per year if total amount exceeds maximum per year
            if (total_amount > maximum) {
            total_amount = maximum;
            }

            printf("\nAmount due ($): %d\n", total_amount);

        } 
    
        //case2: more than a year
        else {

            //first calculate total amount ignoring maximum per year
            total_amount = maximum * year_rented + monthly_cost * month_remainder;

            //then change total amount to maximum per year if total amount exceeds maximum per year
            if (total_amount > maximum * (year_rented + 1)) {
                total_amount = maximum * (year_rented + 1);
            }

            printf("\nAmount due ($): %d\n", total_amount);

        }

    }

}


//main function to run all the functions
int main() {

    calculate(selection());
    return 0;
    
}