//
// COP 3514 – Fall Semester, 2020
//
// Project 3 - arrays2
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


//calculates if there are three consecutive elements in the first parameter, then adds it two the second parameter then returns the number of the added elements
int calculate(int *a1, int *a2, int n) {

    int count = 0;

    int i;
    for (i = 1; i < n; i++) {
        if ((a1[i] == a1[i-1]) && (a1[i] == a1[i-2]) && !(a1[i] == a1[i-3])){
            a2[count] = a1[i];
            count++;
        }
    }

    return count;

}


//gets search result from calculate and then prints the outcome
void search_three(int *a1, int *a2, int n, int *num_three) {

    if (*num_three == 0)
        printf("There are no three identical consecutive elements in the array.");
    else
        printf("There are %d of three identical consecutive elements in the array: ", *num_three);

    int i;
    for(i = 0; i < *num_three; i++){
        printf("%d ", a2[i]);
    }

    printf("\n");
}


//main function
int main() {

    //get length of array as input
    int length;
    printf("Enter the length of the array: ");
    scanf("%d", &length);
    printf("\n");

    //initialize array and assign value using assign()
    int input_array [length];
    int output_array [length];
    assign(&input_array[0], length);

    //calculate outcome and print it
    int num_three = calculate(&input_array[0], &output_array[0] ,length);
    search_three(&input_array[0], &output_array[0], length, &num_three);

    return 0;

}