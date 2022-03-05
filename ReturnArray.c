
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include<string.h>


 float* returnArray(float *array, int size, int value)
 {
     
     float* Array = malloc(sizeof(int) * size);
     for(int i = 0; i < size; i++)
     {
          Array[i] = value - array[i];
         
     }
     return Array;
 }

float validInput(char userInput[20])
{
    readInput:
    scanf("%s", userInput);
    
  	if (!strtof(userInput, NULL))
   {

		  if(strcmp(userInput, "0"))
    {

			     printf("Invalid input. Please enter again.\n");
			
		     	goto readInput;

		  }
	  }
    if(atof(userInput) == 0 || atof(userInput) < 0)
    {
       printf("Invalid input. Please enter again.\n");

      goto readInput;
    }

	
	return atof(userInput);
    
}

int main()
{
    return 0;
}
