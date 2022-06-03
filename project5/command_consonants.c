//
// COP 3514 – Fall Semester, 2020
//
// Project 5 - command_consonants
//
// Dong Jun Kim
//


#include <stdio.h>
#include <string.h>


//checks if the input contains consonants or not then only prints the consonant parts
void compute (char str[], int len) {
    int i;
    for (i = 0; i < len; i++) {
        //only prints the user input if the input is consonants
        //the numbers here are the decimals for the ascii letters that are not consonants
        if(!((str[i] == 97) || (str[i] == 105) || (str[i] == 117) || (str[i] == 101) || (str[i] == 111) || (str[i] == 65) || (str[i] == 73) || (str[i] == 85) || (str[i] == 69) || (str[i] == 79) || (str[i] < 65) || (str[i] > 90 && str[i] <97) || (str[i] > 122)))
            printf("%c", str[i]);
    }
}

//main function
int main (int argc, char *argv[]) {

    //first check if there is user input and if not, print instructions
    if (argc == 1)
        printf("Usage: ./a.out input\n");
    else {
        //loops for every argv[] bc there are spaces in the input
        int i;
        for (i = 1; i < argc; i++) {
            compute(argv[i], strlen(argv[i]));
        }
        printf("\n");
    }

    return 0;

}
