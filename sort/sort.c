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

void insert_sort(int *array, int n)
{
    int i, j, next;
    for(i = 1; i < n; i++)
    {
        next = array[i];
        for(j = i-1; j >= 0 && array[j] > next; j--)
        {
            array[j+1] = array[j];
        }
        array[j+1] = next;
    }
}

void select_sort(int *array, int n)
{
    int i, j;
    int min;
    int tmp;
    
    for(i = 0; i < n; i++)
    {
        min = i;
        for(j = i+1; j < n; j++)
        {
            if(array[j] < array[min])
            {
                min = j;
            }
        }
        if(i != min)
        {
            tmp = array[i];
            array[i] = array[min];
            array[min] = tmp;
        }
    }
}

int main()
{
    int array[10] = {34,53,46,36,72,30,10,3,45345,545};
    int newarray[10];
    
    memcpy(newarray, array, sizeof(array));
    insert_sort(newarray, 10);
    printarray(newarray, 10);
    
    memcpy(newarray, array, sizeof(array));
    select_sort(newarray, 10);
    printarray(newarray, 10);
}