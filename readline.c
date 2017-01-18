/*=======================================================================================================*/
/*=04/17/2016									Alexander Alava Chonchol=*/
/*=readline.c										       U35432961=*/
/*=													=*/
/*=    This program is a source file that holds the definition of a function that read input strings    =*/
/*=======================================================================================================*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "readline.h"

/* Defining the read_line function that will read in user's input as strings */
int read_line(char str[], int n)
{
	/* Declaring and initializing integer variables */
	int ch, i = 0;

	/* Establishing a while loop to skip all the white space before the string */
	while (isspace(ch = getchar()));

	/* Assigning a character to the first index of the array */
	str[i++] = ch;
	
	/* Establishing a while loop to run through the string until the input ends */
  	while ((ch = getchar()) != '\n') 
	{
		/* Checking if the current count is less than the maximum number of characters */
    		if (i < n)
		{
			/* Assigning a character to the next position of the string */
      			str[i++] = ch;
    		}
   	}
   
	/* Ending the string */
	str[i] = '\0';
   
	/* Returning the number of characters */
	return i;
}
