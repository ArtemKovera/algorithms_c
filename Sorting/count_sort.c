#include<stdio.h>
#include<stdlib.h>

#define SIZE 20
#define MAX_NUMBER 128

void countSort(int * const array, const int size)
{
    int * tempArr = calloc(MAX_NUMBER, sizeof(int));

    int j;
    int shift = 0;

    for(int i = 0; i < size; i++)
    {
        j = array[i];
        tempArr[j] += 1;
    }

    for(int i = 0; i < MAX_NUMBER; i++)
    { 
        if(tempArr[i])
        {
            for( j = 0; j < tempArr[i]; j++)
            {
                array[shift + j] = i;
            }
            shift += j;
        }
    }

    free(tempArr);
    tempArr = NULL;
}

int main()
{
    unsigned int array[SIZE] = {4, 0, 2, 4, 2, 7, 3, 4, 1, 6, 2, 11, 34, 0, 0, 23, 101, 7, 100, 2};


    countSort(array, SIZE);
    
    
    for(int i = 0; i < SIZE; i++)
    {
        printf("%d \n", array[i]);
    }   
    

    return 0;
}