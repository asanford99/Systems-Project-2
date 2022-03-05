#include <stdio.h>
#include <math.h>

// Function to return sum of elements
// The arrays of value: breakfast costs, lunch costs, dinner costs, hotel costs, taxi costs, and parking costs.
float sumOf(float arr[], int size)
{
    float sum = 0.0;

    // Iterate through all elements and add them to sum.
    for(int i = 0; i < size; i++)
    {
        //Checking if the value of array is positive, if not then do not add it to the sum.
        if(arr[i] >= 0)
        {
            sum += arr[i];
        }
    }
    return sum;
}

int main()
{
    return 0;
}