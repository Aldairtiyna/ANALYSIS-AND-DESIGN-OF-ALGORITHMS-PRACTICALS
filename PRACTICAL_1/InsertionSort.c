#include<stdio.h>
#include<time.h>

void InsertionSort(){
    int i,n=5,temp,j,arr[5]={10,40,30,50,20};

    for(i = 0;i<n;i++){
        temp = arr[i];
        j = i-1;
        while ((temp< arr[j] )&& (j>=0))
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1]= temp;
    }
    printf("\n Insertion Sorted array: ");
    for( i =0;i<n;i++)
        printf("%d\t",arr[i]);
}

int main(){

    clock_t t;
    t = clock();
    InsertionSort();
    t= clock()-t;
    double time_taken = ((double)t) / CLOCKS_PER_SEC; //in sec

    printf(" Sort took %f second to execute\n", time_taken);
    return 0;
}