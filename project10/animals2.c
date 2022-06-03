//
// COP 3514 – Fall Semester, 2020
//
// Project 10 - animals2
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

//compares the age of two animal structures
int compare(const void *p, const void *q);

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

    //sorts animals array using qsort and compare function
    qsort(animals, length, sizeof(struct animal), compare);

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

int compare(const void *p, const void *q) {

    const struct animal *p1 = (struct animal *)p;
    const struct animal *q1 = (struct animal *)q;

    if(p1->age < q1->age)
        return -1;
    else if(p1->age == q1->age)
        return 0;
    else
        return 1;

}
