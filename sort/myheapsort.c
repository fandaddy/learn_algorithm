#include <stdio.h>
#include <string.h>

void heap_adjust(int *array, int s, int m)
{
    int i;
    int temp;
    
    temp = array[s];
    for(i = 2*s+1; i < m; i = i*2+1)
    {
        if(i+1 < m && array[i] < array[i+1])
        {
            i++;
        }
        if(temp >= array[i])
        {
            break;
        }
        array[s] = array[i];
        s = i;
    }
    array[s] = temp;
}

void heap_sort(int *array, int n)
{
    int i;
    int tmp;
    
    for(i = n/2-1; i >= 0; i--)
    {
        heap_adjust(array, i, n);
    }
    
    for(i = n-1; i > 0; i--)
    {
        tmp = array[0];
        array[0] = array[i];
        array[i] = tmp;
        heap_adjust(array, 0, i);
    }
}

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

int main()
{
    int array[10] = {34,53,46,36,72,30,10,3,45345,545};
    int newarray[10];
    
    memcpy(newarray, array, sizeof(array));
    heap_sort(newarray, 10);
    printarray(newarray, 10);
    
    return 0;
}