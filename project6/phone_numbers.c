//
// COP 3514 – Fall Semester, 2020
//
// Project 6 - phone_numbers
//
// Dong Jun Kim
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_FILE 100
#define MAX_LINE 10000

//gets 2 char pointer types, input and phone as parameter
//input is the file name user enters and phone is a new file with only the phone numbers from input and has the name phone_ + input
void extract_phone (char *input, char *phone);

//main function
int main () {

    char input [MAX_FILE + 1];
    char phone [MAX_LINE + 1];

    printf("Enter file name: ");
    scanf("%s", input);

    char output [strlen(input) + 6];
    strcpy(output, "phone_");
    strcat(output, input);
    
    printf("\nOutput file name: %s\n", output);


    FILE *pInput;
    FILE *pOutput;

    pInput = fopen(input, "r");
    pOutput = fopen(output, "w");

    while (fgets(input, MAX_LINE, pInput)) {
        extract_phone(input, phone);
        fputs(phone, pOutput);
    }

    fclose(pInput);
    fclose(pOutput);

    return 0;

}

void extract_phone (char *input, char *phone) {

    int length = strlen(input);
    int i;
    int j = 0;
    int k;

    //runs thorugh the line starting at the end going backwards
    //the elements are copied to phone until the first _ found in the loop is reached
    for (i = length-1; *(input+i) != '_'; i--, j++) {
        *(phone+j) = *(input+i);
    }

    //the above loop stores the numbers in reverse order so we need to change the order of the elements every line
    length = strlen(phone);
    for (k = 0; k < length/2; k++) {
        char temp;
        temp = *(phone+k);
        *(phone+k) = *(phone + length-k-1);
        *(phone + length-k-1) = temp;
    }
    *(phone+j) = '\0';

}
