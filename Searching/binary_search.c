#include<stdio.h>
#include<unistd.h>


#define SIZE 20

//returns element's index in the array
//returns -1 if the element is not found
int binarySearch(int * const array, const int element, const int size)
{   
    int s = size/2;
    int * middle = array + size/2; 
    int index = s;

    while(1)
    {
        if(element == *middle)
        {
            return index;
        }
        else if (element > *middle)
        {
            s /= 2;
            middle += s;
            index += s;
            if(s == 0)
            {
                if(array[size - 1] == element)
                    return size - 1;   
                else
                    return -1;        
            }
                
        }
        else
        {
            s /= 2;
            middle -= s;
            index -= s;
            if(s == 0)
            {
                if(array[0] == element)
                    return 0;
                
                return -1;
            }
        }     
    }

}

int main(void)
{

    int array [SIZE] = {-3, -1, 0, 2, 3, 4, 6, 7, 8, 10, 11, 12, 13, 14, 15, 18, 20, 21, 98, 99}; 

    int element;
    
    puts("Enter a number: ");
    scanf("%d", &element);

    int index = binarySearch(array, element, SIZE);

    if(index == -1)
    {
        puts("The number is not found");
    }
    else
    {
       printf("The number is found at index %d \n", index);  
    }
    
    return 0;
}