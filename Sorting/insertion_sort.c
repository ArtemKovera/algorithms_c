#include<stdio.h>

#define SIZE 20

void insertionSort(int * array, int size)
{
    int temp, k;
    int flag = 1;
    int i = 0;
    int j = 1;
    while(i < size + 1)
    {
        
        if(array[i] > array[i+1])
        {
            temp = array[i+1];
            array[i+1] = array[i]; 
            array[i] = temp;
            k = i;
            while(flag && k)
            {
                if(array[k] > array[k-1])
                    break;
                
                temp = array[k];
                array[k] = array[k-1];
                array[k-1] = temp;
                k--;
            }
        }
        i++;

    }
}

int main()
{
    int array[SIZE] = {1, 0, 2, 4, 2, 7, 3, 4, 1, 6, -2, 11, 34, 0, 0, 23, 101, -7, 100, 2};
    
    insertionSort(array, SIZE);    
    
    for(int i = 0; i < SIZE; i++)
    {
        printf("%d \n", array[i]);
    }    

    return 0;
}