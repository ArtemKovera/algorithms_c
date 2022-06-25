#include <stdio.h>
#include <stdlib.h>

#define SIZE 20

void radixSort(int * const array, int const size)
{

    int * tempArr = calloc(size * 10, sizeof(int));
    int k;
    int e0, e1, e2, e3, e4, e5, e6, e7, e8, e9;

    int m = 1;
    int max_round = 3; //this value depends on the input
    int j = 0;
    int a = 0;
    int b = 0;
    int t;
    int elemets_copied; 
 
    
    while(j < max_round)
    {
        e0 = e1 = e2 = e3 = e4 = e5 = e6 = e7 = e8 = e9 = 0;
        elemets_copied = 0;
        a = b = 0;

        printf("round %d\n", j);

        for(int i = 0; i < size; i++)
        {   
            t = array[i]/m;
            
            

            if(j < 2)
                k = t%10;
            else
                k = t;

            switch(k)
            {
                case 0 : tempArr[0 + e0] = array[i];
                e0++;
                break;
                case 1 : tempArr[19 + e1] = array[i];
                e1++;
                break;
                case 2 : tempArr[39 + e2] = array[i];
                e2++;
                break;
                case 3 : tempArr[59 + e3] = array[i];
                e3++;
                break;
                case 4 : tempArr[79 + e4] = array[i];
                e4++;
                break;
                case 5 : tempArr[99 + e5] = array[i];
                e5++;
                break;
                case 6 : tempArr[119 + e6] = array[i];
                e6++;
                break;
                case 7 : tempArr[139 + e7] = array[i];
                e7++;
                break;
                case 8 : tempArr[159 + e8] = array[i];
                e8++;
                break;
                case 9 : tempArr[179 + e9] = array[i];
                e9++;
                break;
                default:
                break;
            }
        }
        
        m *= 10;
        j++;

        while(1)
        {
            if(tempArr[a])
            {
                array[b] = tempArr[a];
                b++;
                tempArr[a] = 0;
                elemets_copied++;
            }
            a++;
            

            if(elemets_copied == size)
                break;
                
        }
        
    }

    
    free(tempArr);
    tempArr = NULL;

}


int main()
{
    unsigned int array[SIZE] = {451, 104, 221, 403, 104, 707, 345, 408, 144, 633, 205, 119, 347, 321, 172, 235, 101, 790, 100, 272};
    
    radixSort(array, SIZE);
    
    
    for(int i = 0; i < SIZE; i++)
    {
        printf("%d \n", array[i]);
    } 
    
    
    return 0;
}