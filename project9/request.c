//
// COP 3514 – Fall Semester, 2020
//
// Project 9 - request
//
// Dong Jun Kim
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "request.h"

/**********************************************************
 * load: read file "waiting_list.txt" and store the data  *
 *       in a linked list and returns the linked list     *
 **********************************************************/

struct request *load(){
	struct request * list= NULL;
	struct request *prev, *new_node;
	char f_name[NAME_LEN+1];
	char l_name[NAME_LEN+1];
	char e_address[EMAIL_LEN+1];
	char class_name[CLASS_LEN+1];

	FILE *pFile;

        pFile = fopen("waiting_list.txt", "r");
	
	if(pFile == NULL)
	{
		printf("Error opening the file\n");
		return NULL;
	}

        while(!feof(pFile)&&!ferror(pFile))
	{
	       if(fscanf(pFile, "%s%s%s%s", e_address, class_name, f_name, l_name)== 4)
		{

 			 new_node = malloc(sizeof(struct request));
 			 if (new_node == NULL) {
    				printf("Database is full; loding error.\n");
    				return NULL;
 			 }

			strcpy(new_node->email, e_address);	
			strcpy(new_node->class, class_name);
			strcpy(new_node->first, f_name);
			strcpy(new_node->last, l_name);
			new_node->next = NULL;

			if(list == NULL)	
				list = new_node;
			else
				prev->next = new_node;
			prev = new_node;				
				
        	}
	}
	return list;
}

/**********************************************************
 * save: write to file "waiting_list.txt" with the data   *
 *       in the linked list passed in as parameter        *
 **********************************************************/


void save(struct request *list)
{

	struct request * p;

	FILE *pFile;

        pFile = fopen("waiting_list.txt", "w");
	
	if(pFile == NULL)
	{
		printf("Error opening the file\n");
		return;
	}
	for (p =list; p != NULL; p = p->next)
    		fprintf(pFile, "%-s %s %s %s\n", p->email, p->class, p->first,p->last);

	fclose(pFile);


}

/**********************************************************
 * delete: scans data from user and checks if the input   *
 *         is already in the text file. If the input      *
 *         already exists, the function deletes it        *
 **********************************************************/


struct request *delete(struct request *list){

	//add your code

	struct request *p, *temp;

	char f_name[NAME_LEN+1];
	char l_name[NAME_LEN+1];
	char e_address[EMAIL_LEN+1];
	char c_name[CLASS_LEN+1];

	printf("\nEnter email: ");
	scanf("%s", e_address);
	printf("\nEnter class: ");
	scanf("%s", c_name);
	printf("\nEnter first name: ");
	scanf("%s", f_name);
	printf("\nEnter last name: ");
	scanf("%s", l_name);

	for (p = list, temp = NULL; p != NULL; temp = p, p = p -> next) {
		if (strcmp(p -> first, f_name) == 0 && strcmp(p -> last, l_name) == 0 && strcmp(p -> email, e_address) == 0 && strcmp(p -> class, c_name) == 0) {
			break;
		}
	}

	if (p == NULL) {
		printf("This entry could not be found");
		return list;
	}
	if (temp == NULL) {
		list = list -> next;
	} else {
		temp -> next = p -> next;
	}

	free(p);

	return list;

}

/**********************************************************
 * append: scans data from user and checks if the input   *
 *         is already in the text file. If the input      *
 *         doesn't exists, the function adds it           *
 **********************************************************/


struct request *append(struct request *list){

	//add your code

	char f_name[NAME_LEN+1];
	char l_name[NAME_LEN+1];
	char e_address[EMAIL_LEN+1];
	char c_name[CLASS_LEN+1];

	//get input
	printf("\nEnter email: ");
	scanf("%s", e_address);
	printf("\nEnter class: ");
	scanf("%s", c_name);
	printf("\nEnter child first name: ");
	scanf("%s", f_name);
	printf("\nEnter child last name: ");
	scanf("%s", l_name);

	//allocate memory for the structure
	struct request* p = (struct request*) malloc(sizeof(struct request)); 
    struct request *temp = list;

	//search and find if the request already exists
	while(temp->next != NULL) {
    	if(!strcmp(temp->first, f_name) && !strcmp(temp->last, l_name) && !strcmp(temp->email, e_address) && !strcmp(temp->class, c_name)){
    	    printf("Output: request already exists");
    	    return list;
    	}
    	temp = temp->next;
	}

	// reset p and temp
	p = (struct request*) malloc(sizeof(struct request)); 
	temp = list;

	//store the data
	strcpy(p->first, f_name);
	strcpy(p->last, l_name);
	strcpy(p->email, e_address);
	strcpy(p->class, c_name);
	p->next = NULL; 

	//if list is empty return pointer to the newly created linked list
    if (list == NULL) {
       return p; 
    }

	//traverse to the end of the list and append the new list to the original list
    while (temp->next != NULL) {
		temp = temp->next;
	}
	temp->next = p;


 	return list;

}


/**********************************************************
 * printList: print the data  in the linked list passed   *
 * in as parameter                                        *
 **********************************************************/


void printList(struct request *list){

	//i addeed the newline to match the format in try_rec
	printf("\n");

  struct request *p;

  for (p =list; p != NULL; p = p->next)
    printf("%-50s%-15s%-15s%15s\n", p->email, p->first,p->last,
           p->class);

}

/**********************************************************
 * clearLIst: free the memory used                        *
 **********************************************************/


void clearList(struct request *list)
{

 //add your code

	struct request *p;
	while (list != NULL) {
		p = list;
		list = list->next;
		if (p != NULL)
			free(p);
	}

}
