//
// COP 3514 – Fall Semester, 2020
//
// Project 5 - stars
//
// Dong Jun Kim
//


#include <stdio.h>


//gets input from user and assigns it to the array from parameter as an element then return number of characters stored
int read_line(char *str, int n) {

    printf("Enter input: \n");

    int ch, i = 0; 
    while ((ch = getchar()) != '\n') {
        if (i < n) {
            *str++= ch;
            i++;
        }
    }

    *str = '\0';   /* terminates string */
    return i;        /* number of characters stored */
}


//searches for the first 2 * from s1 and then puts the characters between them to s2
//returns 0 if no two * and 1 if there are two *
int search (char *s1, char *s2) {

    int position1 = -1;
    int position2 = -1;
    int length = 0;

    //goes through each element in array starting from beginning and checks if the element is *
    int i;
    for (i = 0; i < 1000; i++) {
        if(*(s1 + i) == '*') {
            position1 = i;
            //breaks so that split is the index of the first * of the array
            break;
        }
    }

    //doesn't proceed unless there's at least one *
    if (position1 != -1) {

        //goes through all the elements in s1 and finds the second *
        int j;
        for (j = position1+1; j < 1000; j++) {
            if(*(s1 + j) == '*') {
                position2 = j;
                length = position2 - position1 - 1;

                //assigns values from s1 to s2
                int k;
                for (k = 0; k < length; k++) {
                    *(s2+k) = *(s1+position1+1+k);
                }

                //there are cases where there is only one * so I need to filter that as well
                if (position2 != -1) {
                    //if code reaches here there are at least two * in s1
                    return 1;
                }
            }
        }
    }

    return 0;

}


//main function
int main() {

    //initialize array and assign value using assign()
    char array1 [1000];
    char array2 [1000];
    read_line(&array1[0], 1000);

    //check should be 0 if two * is not found and 1 otherwise
    int check = search(&array1[0], &array2[0]);

    //print final string
    printf("Output :");
    if (check == 0) {
        printf("Two * characters not found\n");
    } else {
        printf("%s", array2);
        printf("\n");
    }

    return 0;

}