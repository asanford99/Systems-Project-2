
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include<string.h>


float* returnArray(float *array, int size, int value)
 {
	 int i = 0;
     
     float* Array = {0};
	 Array = (float*)malloc(sizeof(float) * size);
	 

     for(i = 0; i < size; i++)
     {
          Array[i] = value - array[i];
         
     }
     return Array;
 }

float validInput(char userInput[20])
{
	goto functionStart;

    readInput:
    scanf("%s", userInput);
    
	functionStart:
  	if (!strtof(userInput, NULL))
   {

		  if(strcmp(userInput, "0"))
    {

			     printf("Invalid input. Please enter again: $");
			
		     	goto readInput;

		  }
	  }
    if(atof(userInput) < 0)
    {
       printf("Invalid input. Please enter again: $");

      goto readInput;
    }

	
	return atof(userInput);
    
}

int main()
{
    return 0;
}
