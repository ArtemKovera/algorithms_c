#include<stdio.h>

#define SIZE 20


void merge(int * array, int left, int middle, int right)
{
    int i, j, k;
    int size1 = middle - left + 1;
    int size2 = right - middle;

    int leftArray[size1];
    int rightArray[size2];

    for (i = 0; i < size1; i++)
        leftArray[i] = array[left + i];

    for (j = 0; j < size2; j++)
        rightArray[j] = array[middle + 1+ j];

    i = 0;
    j = 0;
    k = left;
    while (i < size1 && j < size2)
    {
        if (leftArray[i] <= rightArray[j])
        {
            array[k] = leftArray[i];
            i++;
        }
        else
        {
            array[k] = rightArray[j];
            j++;
        }
        k++;
    }

    while (i < size1)
    {
        array[k] = leftArray[i];
        i++;
        k++;
    }

    while (j < size2)
    {
        array[k] = rightArray[j];
        j++;
        k++;
    }
}

void mergeSort(int * array, int left, int right)
{
    if (left < right)
    {
        int middle = left+(right-left)/2;

        mergeSort(array, left, middle);
        mergeSort(array, middle+1, right);
        
        merge(array, left, middle, right);
    }
}

int main()
{

    int array[SIZE] = {1, 0, 2, 4, 2, 7, 3, 4, 1, 6, -2, 11, 34, 0, 0, 23, 101, -7, 100, 2};
    
    mergeSort(array, 0, SIZE - 1);
    
    
    for(int i = 0; i < SIZE; i++)
    {
        printf("%d \n", array[i]);
    }

    return 0;
}