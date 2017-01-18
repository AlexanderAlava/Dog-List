/*================================================================================================================================*/
/*=04/17/2016												 Alexander Alava Chonchol=*/
/*=records.c														U35432961=*/
/*=																 =*/
/*=   This program is a source file that holds the main function of a group of dependant programs that simulate a dog hospital   =*/
/*================================================================================================================================*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "dogs.h"
#include "readline.h"

int main(void)
{
	/* Declaring a character variable and a structure dog pointer */
  	char code;
  	struct dog *dog_list = NULL;  
  
	/* Printing a header message with the instructions of the program */
	printf("Operation Code: a for appending to the list, s for finding a dog, p for printing the list; q for quit.\n");
  
	/* Establishing an infinite for loop to be only broken by the user */
	for (;;) 
	{
		/* Prompting for and reading in user's option as the input */
    		printf("Enter operation code: ");
    		scanf(" %c", &code);
    
		/* Establishing a while loop that skips to the end of the line */
		while (getchar() != '\n');
    
		/* Establishing a switch case with user's input */
		switch (code) 
		{
			/* Case 'a' for append */
      			case 'a': 
				dog_list = append(dog_list);
                		break;
			/* Case 's' for search */
      			case 's': 
				search(dog_list);
                		break;
			/* Case 'p' for print */
      			case 'p': 
				print(dog_list);
                		break;
			/* Case 'q' for quit */
      			case 'q': 
				clear(dog_list);
				return 0;
			/* Default case */
      			default:  
				printf("Illegal code\n");
    		}
    		
		/* Printing a new line character in order to have space from the next thing to be printed */
		printf("\n");
  	}
}
