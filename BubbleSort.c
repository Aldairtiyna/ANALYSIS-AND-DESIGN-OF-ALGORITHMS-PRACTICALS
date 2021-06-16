#include<stdio.h>
#include<time.h>

void BubbleSort(){
    int i,n=5,temp,j,arr[5]={10,40,30,50,20};

    for( i =0; i<n;i++){
        for(j = 0; j< n-i-1; j++){
            if(arr[j]>arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1]= temp;
            }
        }
    }
    printf("\n The array sorted in ascending order is: \n");
    for(i = 0; i<n;i++)
        printf("%d\t", arr[i]);
}
int main(){
    clock_t t;
    t = clock();
    BubbleSort();
    t= clock()- t;
    double time_taken = ((double)t) / CLOCKS_PER_SEC; //in sec
    printf("Bubble Sort took %f second to execute\n", time_taken);
    return 0;
}