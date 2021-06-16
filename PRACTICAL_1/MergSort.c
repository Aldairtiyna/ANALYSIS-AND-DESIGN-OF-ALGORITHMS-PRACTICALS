#include <stdio.h>
#include <conio.h>
#include<time.h>
#define size 100
void merge(int a[], int, int, int);
void merge_sort(int a[], int, int);
void main()
{
     clock_t t;
    t = clock();
    int arr[5]={10,40,50,20,30}, i, n=5;
    
    merge_sort(arr, 0, n - 1);
    printf("\n Merge sorted array is: \n");
    for (i = 0; i < n; i++)
        printf(" %d\t", arr[i]);
    t= clock()-t;
    double time_taken = ((double)t) / CLOCKS_PER_SEC;

    printf("Function took %f seconds to run\n" ,time_taken);
}
void merge(int arr[], int beg, int mid, int end)
{
    int i = beg, j = mid + 1, index = beg, temp[size], k;
    while ((i <= mid) && (j <= end))
    {
        if (arr[i] < arr[j])
        {
            temp[index] = arr[i];
            i++;
        }
        else
        {
            temp[index] = arr[j];
            j++;
        }
        index++;
    }
    if (i > mid)
    {
        while (j <= end)
        {
            temp[index] = arr[j];
            j++;
            index++;
        }
    }
    else
    {
        while (i <= mid)
        {
            temp[index] = arr[i];
            i++;
            index++;
        }
    }
    for (k = beg; k < index; k++)
        arr[k] = temp[k];
}
void merge_sort(int arr[], int beg, int end)
{
    int mid;
    if (beg < end)
    {
        mid = (beg + end) / 2;
        merge_sort(arr, beg, mid);
        merge_sort(arr, mid + 1, end);
        merge(arr, beg, mid, end);
    }
}