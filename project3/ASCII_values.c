//
// COP 3514 – Fall Semester, 2020
//
// Project 3 - ASCII_values
//
// Dong Jun Kim
//


#include <stdio.h>
#include <stdlib.h>
#include <time.h>


//generates random integer between 33 and 126 that will later go inside the array then be converted to char
int generate_values () {
    return (rand() % 94 + 33);
}


//gets an array and the length of the array as a parameter then assigns the value from generate_values() inside the array given
void random_values (int a[], int l) {
    int i;
    for (i = 0; i < l; i++) {
        a[i] = generate_values();
    }
}


//main function
int main () {

    //to prevent rand() from producing the same value every time
    srand(time(NULL));

    //generates random integer between 8 and 15 which is used as the length of the array[]
    int length = (rand() % 8 + 8);

    int array[length];
    

    //for assigning random values to the array []
    random_values(array, length);

    int i;

    //prints the array elements as a character type
    for (i = 0; i < length; i++) {
        printf("%c", array[i]);
    }

    return 0;

}