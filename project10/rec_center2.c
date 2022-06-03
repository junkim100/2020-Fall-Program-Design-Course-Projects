//
// COP 3514 – Fall Semester, 2020
//
// Project 10 - rec_center2
//
// Dong Jun Kim
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define CLASS_LEN 100
#define NAME_LEN 30
#define EMAIL_LEN 50

struct request{
	char class[CLASS_LEN+1];
	char first[NAME_LEN+1];
	char last[NAME_LEN+1];
	char email[EMAIL_LEN+1];;

	struct request *next;
};

struct request *add(struct request *list);
void printList(struct request *list);
void clearList(struct request *list);
int read_line(char str[], int n);

/**********************************************************
 * main: Prompts the user to enter an operation code,     *
 *       then calls a function to perform the requested   *
 *       action. Repeats until the user enters the        *
 *       command 'q'. Prints an error message if the user *
 *       enters an illegal code.                          *
 **********************************************************/
int main(void)
{
  char code;

  struct request *wait_list = NULL;  
  printf("Operation Code: a for adding to the ordered list,"
	  ", p for printing the list; q for quit.\n");
  for (;;) {
    printf("Enter operation code: ");
    scanf(" %c", &code);
    while (getchar() != '\n')   /* skips to end of line */
      ;
    switch (code) {
      case 'a': wait_list = add(wait_list);
		            break;
      case 'p': printList(wait_list);
                break;
      case 'q': clearList(wait_list);
		            return 0;
      default:  printf("Illegal code\n");
    }
    printf("\n");
  }
}

struct request *add(struct request *list){

  //add your code

  struct request input;
  struct request *i, *j;

  //get input
	printf("\nEnter email: ");
  read_line(input.email, EMAIL_LEN);
	printf("\nEnter class: ");
  read_line(input.class, CLASS_LEN);
	printf("\nEnter child first name: ");
  read_line(input.first, NAME_LEN);
	printf("\nEnter child last name: ");
  read_line(input.last, NAME_LEN);

  //allocate memory for the structure
	struct request *p = malloc(sizeof(struct request));

	//store the data
	strcpy(p->first, input.first);
	strcpy(p->last, input.last);
	strcpy(p->email, input.email);
	strcpy(p->class, input.class);
  p->next = NULL;

	//if list is empty return pointer to the newly created linked list
  if (list == NULL) {
    list = p;
    return list; 
  }

  //move i and j to the location of the class input position alphabetically
  for (i = list, j = NULL; (i != NULL) && (strcmp(p->class, i->class) >= 0); j = i, i = i->next) {
    //if class is same, compare last name
    if ((strcmp(p->class, i->class) == 0) && (strcmp(p->last, i->last) < 0)) {
      break;
    }
  }

  if (j == NULL) {
    p->next = i;
    list = p;
    return list;
  } else{
    j->next = p;
    p->next = i;
    return list;
  }

}


/**********************************************************
 * printList: print the data  in the linked list passed   *
 * in as parameter                                        *
 **********************************************************/


void printList(struct request *list){

  struct request *p;

  printf("\nEmail\t\t\t\t\t\tFirst Name\tLast Name\t\t"
         "class\n");
  for (p =list; p != NULL; p = p->next)
    printf("%-50s%-15s%-15s%15s\n", p->email, p->first,p->last,
           p->class);

}

/*************************************************************
 * clearList: release the memory in the linked list passed   *
 * in as parameter                                           *
 *************************************************************/


void clearList(struct request *list)
{

 
  struct request *p;

  while(list!=NULL)
  {
         p = list;
         list = list->next;
         if(p!=NULL)
            free(p);
  }


}

int read_line(char str[], int n)
{
  int ch, i = 0;

  while (isspace(ch = getchar()))
    ;
  str[i++] = ch;
  while ((ch = getchar()) != '\n') {
    if (i < n)
      str[i++] = ch;
    
   }
   str[i] = '\0';
   return i;
}
