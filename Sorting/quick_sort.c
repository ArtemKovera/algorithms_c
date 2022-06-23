#include <stdio.h>

#define SIZE 20

void swap(int * p1, int * p2)
{
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}


int partition(int * array, int low, int high)
{
    int pivot_value = array[high];
  
    int index = low; 
  
    for (int j = low; j < high; j++)
    {
        if (array[j] <= pivot_value)
        {
            swap(&array[index], &array[j]);
            index++;
        }
    }
  
    swap(&array[index], &array[high]);
  
    return index;
}


void recursion(int * array, int low, int high)
{
    if (low < high)
    {
        int pivot_index = partition(array, low, high);

        recursion(array, low, pivot_index - 1);

        recursion(array, pivot_index + 1, high);
    }
}

void quickSort(int * array, int size)
{
    recursion(array, 0, size - 1);
}


int main()
{
  
    int array[SIZE] = {4, 0, 2, 4, 2, 7, 3, 4, 1, 6, -2, 11, 34, 0, 0, 23, 101, -7, 100, 2};

  
    quickSort(array, SIZE);
  
    for(int i = 0; i < SIZE; i++)
    {
        printf("%d \n", array[i]);
    }    

    return 0;
}