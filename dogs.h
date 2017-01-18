/*============================================================================================*/
/*=04/17/2016							     Alexander Alava Chonchol=*/
/*=dogs.h									    U35432961=*/
/*=											     =*/
/*=   This program is a header file that declares a structure and four different functions   =*/
/*============================================================================================*/

#ifndef DOGS_H
#define DOGS_H
#define NAME_LEN 30

/* Declaring and defining a structure called dog */
struct dog
{
	/* Declaring an integer variable, character arrays and a structure dog pointer */
	int number;
	char dog_name[NAME_LEN+1];
	char owner_last_name[NAME_LEN+1];
	char breed[NAME_LEN+1];
	struct dog *next;
};

/* Declaring the function *append with parameter structure dog pointer */
struct dog *append(struct dog *list);
/* Declaring the function search with parameter structure dog pointer */
void search(struct dog *list);
/* Declaring the function print with parameter structure dog pointer */
void print(struct dog *list);
/* Declaring the function clear with parameter structure dog pointer */
void clear(struct dog *list);

#endif
