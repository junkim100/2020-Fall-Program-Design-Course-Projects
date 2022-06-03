//
// COP 3514 – Fall Semester, 2020
//
// Project 3 - arrays1
//
// Dong Jun Kim
//


#include <stdio.h>


//gets input from user and assigns it to the array from parameter as an element
void assign(int *a, int n) {

    printf("Enter the elements of the array: \n");

    int i;
    for (i = 0; i < n; i++) {
        scanf("%d", &*(a + i));
    }

}


//gets array and its length as parameter then gets the index of the first 0 in the array and returns it
int compute(int *a, int n) {

    int split = -1;

    //goes through each element in array and checks if the element is 0
    int i;
    for (i = 0; i < n; i++) {
        if(*(a + i) == 0) {
            split = i;

            //breaks so that split is the index of the first 0 of the array
            break;
        }
    }

    return split;

}


//main function
int main() {

    //get length of array as input
    int length;
    printf("Enter the length of the array: ");
    scanf("%d", &length);
    printf("\n");

    //initialize array and assign value using assign()
    int array [length];
    assign(&array[0], length);

    //find out the index where 0 appears in array
    int split = compute(&array[0], length);

    //initialize the two new arrays
    int length1 = split;
    int length2 = length-split-1;
    int array1 [length1];
    int array2 [length2];

    //assign values to array1
    int i;
    for (i = 0; i < length1; i++) {
        array1[i] = array[i];
    }

    //assign values to array2
    int j;
    for (j = 0; j < length2; j++) {
        array2[j] = array[split + 1 + j];
    }

    //print the results
    printf("Array 1: ");
    int k;
    for (k = 0; k < length1; k++) {
        printf("%d ", array1[k]);
    }

    printf("\nArray 2: ");
    int l;
    for (l = 0; l < length2; l++) {
        printf("%d ", array2[l]);
    }

    printf("\n");

    return 0;

}