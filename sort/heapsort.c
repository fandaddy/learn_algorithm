#include <stdio.h>
#include <string.h>

void printarray(int *array, int n)
{
    int i;
    for(i = 0; i < n; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
    
    return;
}

int adjust_heap(int *array, int i, int length)
{
    int temp = array[i];
    int k;
    
    for( k = i*2+1; k < length; k = k*2+1)
    {
        if(k + 1 < length && array[k] < array[k+1])
        {
            k++;
        }
        if(array[k] > temp)
        {
            array[i] = array[k];
            i = k;
        }
        else
        {
            break;
        }
    }
    
    array[i] = temp;
}

int heap_sort(int *array, int n)
{
    int i, j;
    int temp;
    
    for(i = n/2-1; i >= 0; i--)
    {
        adjust_heap(array, i, n);
    }
    
    for(j = n-1; j > 0; j--)
    {
        temp = array[0];
        array[0] = array[j];
        array[j] = temp;
        adjust_heap(array, 0, j);
    }
}

int main()
{
    int array[10] = {34,53,46,36,72,30,10,3,45345,545};
    int newarray[10];
    
    memcpy(newarray, array, sizeof(array));
    heap_sort(newarray, 10);
    printarray(newarray, 10);
    
    return 0;
}