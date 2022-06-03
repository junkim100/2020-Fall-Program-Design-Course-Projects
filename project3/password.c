//
// COP 3514 – Fall Semester, 2020
//
// Project 3 - password
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


//global variable
int length;

//sets a random integer between 8 and 15 into global variable length which is used as the length of the password[]
void set_length () {
    //generates random integer between 8 and 15 which is used as the length of the array[]
    length = (rand() % 8 + 8);
}


//main function from ASCII_values but instead of printing its elements here, passes the array to this program's main function
//you can't return arrays in c so this function sends the array to the allocated memory i made in the main function
void ascii (int *i) {

//for assigning random values to password[] in main function
    random_values(i, length);

}



//copied code from ASCII_values.c with minor changes
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//code for password.c starts here



//gets an array and the length of the array as a parameter then goes through each element of the array to check if the array is a strong password
int check_types (int a[], int n) {

    //each time the program sees a new type(lowercase, uppercase, digit, special), it will add 1 to types
    //so if type is 4, it means there are all types and is a strong password

    int types = 0;
    int i;

    //lowercase
    for (i = 0; i < n; i++) {
        if ((96 < a[i]) && (a[i] < 123)) {
            types += 1;
            //for checking code
            //printf("lower %d %c\n",types, a[i]);
            break;
        }
    }

    //uppercase
    for (i = 0; i < n; i++) {
        if ((64 < a[i]) && (a[i]< 91)) {
            types += 1;
            //for checking code
            //printf("upper %d %c\n",types, a[i]);
            break;
        }
    }

    //digits
    for (i = 0; i < n; i++) {
        if ((47 < a[i]) && (a[i]< 58)){
            types += 1;
            //for checking code
            //printf("digit %d %c\n",types, a[i]);
            break;
        }
    }

    //special characters
    for (i = 0; i < n; i++) {
        //not(all printable characters)
        if (!( ((96 < a[i]) && (a[i] < 123)) || ((64 < a[i]) && (a[i] < 91)) || ((47 < a[i]) && (a[i] < 58)) || (a[i] < 33) || (a[i] == 127) || (a[i] == 60) || (a[i] == 62) )) {
            types += 1;
            //for checking code
            //printf("special %d %c\n",types, a[i]);
            break;
        }
    }

    return types;

}


//gets an array and the length of the array as a parameter, sends it to the check_types() and use its return values to determine whether a[] is a strong password
int is_strong_password (int a[], int n) {

   int types = check_types(a, n);

    //for checking code
    //printf("type: %d", types);

    if (types == 4)
        return 1;
    else if ((types > 0) && (types < 4))
        return 0;
    //just in case
    else {
        printf("THIS SHOULDN'T HAPPEN!!! types: %d", types);
        return 0;
   }

}


//main function
int main () {

    //to prevent rand() from producing the same value every time
    srand(time(NULL));

    set_length();

    //allocated memory for ascii() to use later
    int *password = malloc(sizeof (int) * length);

    //passing the address to ascii() in the parameter then ascii() sends it to random_values
    ascii(password);


    //for checking code--------------------------------------YOU CAN USE THIS TO CHECK IF THE CODE IS WORKING PROPERLY
    for (int i = 0; i < length; i++) {
        printf("%c", password[i]);
    }
    printf("\n");

    //for checking code
    //printf("\nlength is %d", length);
    //printf("\n%d", is_strong_password(password, length));

    
    if (is_strong_password(password, length) == 1)
        printf("A strong password\n");
    else if (is_strong_password(password, length) == 0)
        printf("Not a strong password\n");
    //just in case
    else
        printf("THIS SHOULDN'T HAPPEN!!!");
    
    return 0;

}