//
// COP 3514 – Fall Semester, 2020
//
// Project 9 - request.h
//
// Dong Jun Kim
//

#ifndef request_h
#define request_h

#define CLASS_LEN 100
#define NAME_LEN 30
#define EMAIL_LEN 50

// declaration of structure request
struct request{
	char class[CLASS_LEN+1];
	char first[NAME_LEN+1];
	char last[NAME_LEN+1];
	char email[EMAIL_LEN+1];;

	struct request *next;
};

// declaration of function prototypes
struct request *load();
void save(struct request *list);
struct request *append(struct request *list);
struct request *delete(struct request *list);
void printList(struct request *list);
void clearList(struct request *list);

#endif