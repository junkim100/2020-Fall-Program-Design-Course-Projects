//
// COP 3514 – Fall Semester, 2020
//
// Project 2 - consonants
//
// Dong Jun Kim
//


#include <stdio.h>

//main function
int main () {

    //variable for user input
    char c;

    //get user input using getchar()
    printf("Input: ");
	c = getchar();

    printf("\nOutput: ");

    //while loop for getting user input untill \n (enter key) is entered
	while(c != '\n') {

        //only prints the user input if the input is consonants
        //the numbers here are the decimals for the ascii letters that are not consonants
        if(!((c == 97) || (c == 105) || (c == 117) || (c == 101) || (c == 111) || (c == 65) || (c == 73) || (c == 85) || (c == 69) || (c == 79) || (c < 65) || (c > 90 && c <97) || (c > 122)))
            printf("%c", c);
        
        //getchar() only gets one letter at a time
        //this line is inside the while loop so the program keep asks user for another input until the while loop ends (until \n is entered)
		c = getchar();

	}
	

    printf("\n");

    return 0;

}
