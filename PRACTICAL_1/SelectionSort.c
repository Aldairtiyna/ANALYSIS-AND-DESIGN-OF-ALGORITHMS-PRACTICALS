#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include<time.h>

int smallest(int arr[], int k, int n);
void selection_sort(int arr[], int n);

void main()
{
    clock_t t;
    t = clock();
    int arr[5]={10,40,30,50,20}, i, n=5;
    selection_sort(arr, n);
    printf("\n The sorted array is: \n");
    for (i = 0; i < n; i++)
        printf(" %d\t", arr[i]);

    t= clock()-t;
    double time_taken = ((double)t) / CLOCKS_PER_SEC;
    printf("Function took %f seconds to run\n" ,time_taken);
}
int smallest(int arr[], int k, int n)
{
    int pos = k, small = arr[k], i;
    for (i = k + 1; i < n; i++)
    {
        if (arr[i] < small)
        {
            small = arr[i];
            pos = i;
        }
    }
    return pos;
}
void selection_sort(int arr[], int n)
{
    int k, pos, temp;
    for (k = 0; k < n; k++)
    {
        pos = smallest(arr, k, n);
        temp = arr[k];
        arr[k] = arr[pos];
        arr[pos] = temp;
    }
}