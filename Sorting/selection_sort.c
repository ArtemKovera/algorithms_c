#include<stdio.h>

#define SIZE 20

void selectionSort(int * array, int size)
{
    int i = 0;
    int min = array[0];
    int index, temp;
    int flag = 0;
    while(i < size)
    {
        for(int j = i; j < size; j++)
        {   
            if(min > array[j])
            {
                min = array[j];
                index = j;
                flag = 1;
            }
                
        }
        
        if(flag)
        {
            temp = array[i];
            array[i] = min;
            array[index] = temp; 
        }

        min = array[i + 1];
        flag = 0;
        i++;
    }
}



int main()
{

    int array[SIZE] = {1, 0, 2, 4, 2, 7, 3, 4, 1, 6, -2, 11, 34, 0, 0, 23, 101, -7, 100, 2};
    
    selectionSort(array, SIZE);
    
    
    for(int i = 0; i < SIZE; i++)
    {
        printf("%d \n", array[i]);
    }
    

    return 0;
}