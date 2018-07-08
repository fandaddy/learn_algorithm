#include <stdio.h>
#include <stdlib.h>

int seqsearch(int *array, int searchnum, int n)
{
    int i;
    if(NULL == array)
    {
        return -1;
    }
    
    
    for( i = 0; searchnum != array[i] && i < n; i++);
    return (i < n) ? i : -1;
}

static int COMPARE(int a, int b)
{
    if(a > b)
    {
        return 1;
    }
    else if(a == b)
    {
        return 0;
    }
    else
    {
        return -1;
    }
}
int binsearch(int *array, int searchnum, int n)
{
    int left = 0, right = n-1, middle;
    while(left <= right)
    {
        middle = (left + right) / 2;
        switch(COMPARE(array[middle], searchnum))
        {
            case -1:
                left = middle + 1;
                break;
            case 0:
                return middle;
                break;
            case 1:
                right = middle - 1;
                break;
        }
    }
    
    return -1;
}

int main(int ac, char *av[])
{
    int array[10] = {1,3,5,7,9,11,13,15,17,19};
    
    if( 2!= ac)
    {
        printf("input number error");
        return 0;
    }
    printf("seqsearch:%d\n", seqsearch(array, atoi(av[1]), 10));
    printf("seqsearch:%d\n", binsearch(array, atoi(av[1]), 10));
}