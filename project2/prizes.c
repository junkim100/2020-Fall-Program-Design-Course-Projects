//
// COP 3514 – Fall Semester, 2020
//
// Project 2 - prizes
//
// Dong Jun Kim
//


#include <stdio.h>
#include <stdlib.h>
#include <time.h>


//gets input from the user and returns it as an integer
int scan_input () {

    int input;

    printf("Would you like to play (press 1 to play or 0 to quit)? ");
    scanf("%d", &input);

    return input;
    
}


//prints the message for when the symbol is star
void star () {

    printf("Congratulations! You have won 4000 coins\n");

}


//generates random symbols and give out relults
int generate_num (int i) {

    //if the user input from scan_input is 0, do not proceed
    if (i == 0)
        return 0;


    //the code below here only runs if scan_input returns 1

    //creates an integer from 0 to 12 and stores it to num
    int num = rand() % 12;

    //array of symbols in the right order to use later for the results
    char* symbol[] = {"Pizza", "Shirt", "Sweater", "Raspberry", "Brown Sugar", "", "Butter", 
                      "Apple", "Blackberry Jelly", "Strawberry Cake", "Bacon"};


    //filters out special cases like 5 and 11
    switch (num) {

        //if num is 5 call star() then allow user to play again
        case 5:
            star();
            generate_num(scan_input());
            break;

        //allow user to play again
        case 11:
            generate_num(scan_input());
            break;

        //for nums that are not special cases, return the result from the symbol array
        default:
            printf("%s\n", symbol[num]);
            break;
    }

    return 0;

}


//main function
int main () {

    //to prevent rand() from producing the same value every time
    srand(time(NULL));

    //run code
    generate_num(scan_input());
    return 0;

}