//
// COP 3514 – Fall Semester, 2020
//
// Project 7 - animals
//
// Dong Jun Kim
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//structure of animal
struct animal {
    char name [100];
    char species [100];
    char gender [100];
    int age;
    double weight;
};

//gets animal structure and length of the input file as parameter then sorts the whole input file by age regardless of its species
void sort_animals(struct animal animals[], int n);

int main() {

    //created two structures - one is an array of structure and the other is a structure to read inputs
    struct animal animals[200];
    struct animal a;

    //get input file name
    char input [100];
    printf("Enter the file name: ");
    scanf("%s", input);

    printf("Output file name: \n");
    printf("sorted_dogs.txt\n");
    printf("sorted_cats.txt\n");

    //open files
    FILE *pInput;
    FILE *pOutput1;
    FILE *pOutput2;

    pInput = fopen(input, "r");
    pOutput1 = fopen("sorted_dogs.txt", "w");
    pOutput2 = fopen("sorted_cats.txt", "w");

    //reads from structure a then puts it into animals array
    int length = 0;
    while (fscanf(pInput, "%s %s %s %d %lf", a.name, a.species, a.gender, &a.age, &a.weight)!=EOF) {
        animals[length] = a;
        length++;
    }

    //sorts animals array
    sort_animals(animals, length);

    //even after animals is sorted all the species are still mixed
    int j;
    fprintf(pOutput1, "\n");
    fprintf(pOutput2, "\n");
    for(j = 0; j < length; j++) {

        //only stores dog species to pOutput1
        if(strcmp(animals[j].species, "dog") == 0) {
            fprintf(pOutput1, "%-10s\t%10s\t%4d\t%6.2f\n", animals[j].name, animals[j].gender, animals[j].age, animals[j].weight);
        } 
        
        //only stores cat species to pOutput2
        else if(strcmp(animals[j].species, "cat") == 0) {
            fprintf(pOutput2, "%-10s\t%10s\t%4d\t%6.2f\n", animals[j].name, animals[j].gender, animals[j].age, animals[j].weight);
        }

    }

    //close files
    fclose(pInput);
    fclose(pOutput1);
    fclose(pOutput2);

    return 0;
    
}

void sort_animals(struct animal animals[], int length) {

    int i;
    int j;
    int position;

    //runs through all the elements
    for(i = 0; i < length-1; i++) {
        position = i;

        //runs through all the elements after the current element
        for(j = i+1; j < length; j++) {

            //compares if there are elements smaller than the current element then changes position to the position of minimum value
            if(animals[j].age < animals[position].age) {
                position = j;
            }
        }

        //swap current element with the element of minumum value found
        struct animal temp;
        temp= animals[position];
        animals[position] = animals[i];
        animals[i] = temp;        

    }

}
