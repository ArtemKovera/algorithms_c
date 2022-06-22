#include<stdio.h>
#include <math.h>


#define SIZE 16

void merge(int * temparr, int * p1, int * p2, int * p3, int * p4)
{
    int i = 0;
    int flag;
    int total_count = (p4 - p1) + 1;


    while( (p1 != p2 + 1) && (p3 != p4 + 1) )
    {
        if(*p1 > *p3)
        {
            temparr[i] = *p3;
            i++;
            p3++;
            flag = 1;
        }
        else
        {
            temparr[i] = *p1;
            i++;
            p1++;
            flag = 0;
        }
        
    }

    if(i < total_count)
    {
        if(flag)
        {
            while(i < total_count)
            {
                temparr[i] = *p1;
                p1++;
                i++;
            }
        }
        else
        {
            while(i < total_count)
            {
                temparr[i] = *p3;
                p3++;
                i++;
            }            
        }
        
    }
}


void mergeSortIterative(int * array, int size)
{
    int temp_array[size];
    int i = 0;
    int shift = 2;

    while(i < size)
    {
        if(array[i] > array[i+1])
        {
            temp_array[i] = array[i+1];
            temp_array[i + 1] = array[i];            
        }
        else
        {
            temp_array[i] = array[i];
            temp_array[i + 1] = array[i + 1];                
        }

        i += shift;
    }

    for(int i = 0; i < size; i++)
        array[i] = temp_array[i];
    
    
    shift = 0;
    i = 1;
    int j = 4;
    int count = 0;
    int levels = log2(size) - 1;

    int a = 1;
    int b = 2;
    int c = 3;
    
    
    while(count < levels)
    {  
        shift = 0;
        while(shift < size)
        {
            merge(temp_array + shift, array + shift, array + a + shift, array + b + shift, array + c + shift);    
            shift += j * i;
        }
       
        for(int e = 0; e < size; e++)
            array[e] = temp_array[e];

        i *= 2; 
        a = (a * 2) + 1;
        b *= 2;
        c = (c * 2) + 1;
        
        count++;
    }
    
}

int main()
{
    int array[SIZE] = {-8, 0, 2, 4, 3, 5, 6, -1, -3, 6, -2, 11, 34, 0, 0, -16};
    
    
    mergeSortIterative(array, SIZE);
    

    for(int i = 0; i < SIZE; i++)
    {
        printf("%d \n", array[i]);
    }
    

    return 0;
}