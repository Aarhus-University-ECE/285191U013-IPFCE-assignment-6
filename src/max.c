#include <stdio.h>
#include <assert.h>

int max(int* numbers, int size)
{
    int max = numbers[0];

    for(int i = 0; i < size; i++)
    {
        int next = numbers[i];
        if(next > max)
        {
            max = next;
        }
    }

    return max;
}
