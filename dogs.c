/*============================================================================================================*/
/*=04/17/2016									     Alexander Alava Chonchol=*/
/*=dogs.c											    U35432961=*/
/*=													     =*/
/*=  This program is a source file that holds the definition of four different functions that can be called  =*/
/*============================================================================================================*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "dogs.h"
#include "readline.h"

/* Defining the *append function that lets the user add a new dog to the list */
struct dog *append(struct dog *list)
{
	/* Declaring structure dog pointers */
  	struct dog *cur, *new_node;

	/* Allocating memory for the new dog */
  	new_node = malloc(sizeof(struct dog));

	/* Checking if the memory allocation was succesfull */
	if (new_node == NULL)
	{
		/* Printing error message */
    		printf("Database is full; can't add more dogs.\n");

		/* Ending the function and returning the original list */
		return list;
  	}

	/* Prompting for and reading in user's input for the patient number */
  	printf("Enter dog's patient number: ");
  	scanf("%d", &new_node->number);

	/* Establishing a for loop to go through all the dogs in the list */
  	for (cur = list;cur != NULL;cur = cur->next)
  	{
		/* Checking if the patient number already exists */
		if (cur != NULL && new_node->number == cur->number)
		{
			/* Printing a message informing that the patient already exists */
    			printf("Patient already exists.\n");

			/* Deallocating the memory that was previously allocated */
    			free(new_node);

			/* Returning the list as instructed */
    			return list;
  		}
	}

	/* Prompting for and reading in user's input for the dog's name */
  	printf("Enter dog's  name: ");
  	read_line(new_node->dog_name, NAME_LEN);

	/* Prompting for and reading in user's input for the dog's breed */
 	printf("Enter dog's breed: ");
  	read_line(new_node->breed, NAME_LEN);

	/* Prompting for and reading in user's input for the owner's last name */
  	printf("Enter owner's last name: ");
  	read_line(new_node->owner_last_name, NAME_LEN);

	/* Checking if it is the first dog of the list */
  	if(list == NULL)
  	{
		/* Making the list point to the first dog */
        	list = new_node;

		/* Returning the list as instructed */
        	return list;
  	}

	/* Establishing an else statement in case it is not the first dog */
	else
	{
		/* Establishing a for loop to skip to the end of the list */
   		for(cur = list; cur->next!= NULL; cur = cur->next);

		/* Adding the new dog to the end of the list */
		cur->next = new_node;

		/* Initializing the next pointer to NULL */
     		new_node->next = NULL;

		/* Returning the list as instructed */
		return list;
 	}

}

/* Defining the search function that lets the user search for a dog */
void search (struct dog *list)
{
	/* Declaring a character array a structure dog pointer and an integer variable */
	char search_name[NAME_LEN+1];
	struct dog *p;
	int found = 0;

	/* Prompting for and reading in the name of the dog that has to be searched for */
	printf("Enter dog's name: ");
	read_line(search_name, NAME_LEN);

	/* Establishing a for loop to go through all the dogs in the list */
	for(p=list; p != NULL; p = p->next)
	{
		/* Comparing the input name with the names stored in the program */
		if(strcmp(search_name, p->dog_name) == 0)
		{
			/* Setting the integer flag to true */
			found = 1;

			/* Printing all the information requested about the dog in question */
			printf("%d\t", p->number);
			printf("%s\t", p->dog_name);
			printf("%s\t", p->breed);
			printf("%s\n", p->owner_last_name);
		}
	}

	/* Checking the flag */
	if(!found)
	{
		/* Printing an informational message */
		printf("Dog not found.\n");
	}
}

/* Defining the print function that prints the information of all the dogs in the system */
void print(struct dog *list)
{
	/* Declaring a structure dog pointer */
	struct dog *p;

	/* Printing header */
	printf("Dog Number\tDog Name\tDog Breed\tOwner Last Name\n");

	/* Establishing a for loop to run through all the dogs in the list */
	for (p = list; p != NULL; p = p->next)
	{
		/* Printing all the information about each dog */
		printf("%d\t\t%s\t\t%s\t\t%s\n", p->number, p->dog_name,p->breed, p->owner_last_name);
	}
}

/* Defining the clear function that frees the memory allocated for the list */
void clear(struct dog *list)
{
	/* Declaring a structure dog pointer */
	struct dog *p;

	/* Establishing a while loop to run until the end of the list */
	while(list!=NULL)
	{
		/* Pointing the do pointed in the list with the pointer declared above */
		p = list;

		/* Setting the list pointer to the next dog in the list */
		list = list->next;

		/* Checking if the pointer is pointing something */
		if(p!=NULL)
		{
			/* Deallocating the memory allocated for this pointer */
			free(p);

		}
	}
}
