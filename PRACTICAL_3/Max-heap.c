#include<stdio.h>

void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
//heapify
void heapify(int arr[] ,int n,int i){
    int max = i;
    int leftChild = 2*i+1;
    int rightChild = 2*i+2;

    //If leftchild is greter than root
    if(leftChild < n && arr[leftChild]>arr[max])
        max = leftChild;

    //If rightchild is greter than root
    if(rightChild < n && arr[rightChild]>arr[max])
        max = rightChild;

    //if max is root
    if(max != i){
        swap(&arr[i],&arr[max]);

        heapify(arr,n,max);
    }
}
//heapsort
void heapsort(int arr[],int n){
    //Build the heap
    for(int i = n/2 -1; i>=0; i--){
        heapify(arr,n,i);
    }

    //Extract
    for(int i = n-1; i>=0;i--){
        swap(&arr[0],&arr[i]);
        heapify(arr,i,0);
    }
}

//display
void display(int arr[] ,int n){
    for(int i = 0; i<n; ++i){
        printf("%d | ",arr[i]);
    }
    printf("\n");
}

//Driver code
int main(){
    int arr[]={40,30,50,20,60,10,70};
    int n = sizeof(arr)/sizeof(arr[0]);

    printf("Original Array: \n");
    display(arr,n);
    heapsort(arr,n);

    printf("Sorted Array: \n");
    display(arr,n);
}