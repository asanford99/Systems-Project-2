
#include <stdio.h>
#include <math.h>
#include <stdlib.h>


 float* returnArray(float *array, int size, int value)
 {
     
     float* Array = malloc(sizeof(int) * size);
     for(int i = 0; i < size; i++)
     {
          Array[i] = value - array[i];
         
     }
     return Array;
 }
int main()
{
    return 0;
}
