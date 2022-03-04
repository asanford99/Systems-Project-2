// Function to return sum of elements
// The arrays of value: breakfast costs, lunch costs, dinner costs, hotel costs, taxi costs, and parking costs.

float sumOf(float arr[], int size)
{
    float sum = 0.0;

    // Iterate through all elements and add them to sum.
    for(int i = 0; i < size; i++)
    {
        sum += arr[i];
    }
    return sum;
}