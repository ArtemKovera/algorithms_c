#include<stdio.h>

#define SIZE 20

void bubbleSort(int * array, int size)
{
    int flag = 1;
    while(flag)
    {
        int i = 0;
        int j = 1;
        int temp;
        int count = size - 1;
        flag = 0;
        
        while(count)
        {
            if (array[i] > array[j])
            {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
                flag = 1;
            }
            i++;
            j++;
            count--;
        }

    }
}

int main()
{

    int array[SIZE] = {1, 0, 2, 4, 2, 7, 3, 4, 1, 6, -2, 11, 34, 0, 0, 23, 101, -7, 100, 2};
    
    bubbleSort(array, SIZE);    
    
    for(int i = 0; i < SIZE; i++)
    {
        printf("%d \n", array[i]);
    }

    return 0;
}