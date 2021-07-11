#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    //  Decalare variables and Functions

    int array[100],search_key,i,j,n,low,high,location,choice;

    void linear_search(int search_key, int array[100],int n);
    void binary_search(int search_key, int array[100],int n);

    // read the element of array

    printf("ENTER THE SIZE OF THE ARRAY: ");
    scanf("%d",&n);
    printf("ENTER THE ELEMENT OF THE ARRAY: \n");
    for(i=1;i<=n;i++){
        scanf("%d",&array[i]);
    }

    // Get search key
    printf("ENTER THE SEARCH KEY: \n");
    scanf("%d",&search_key);

    // Choice of search algo
    printf("-------------------------\n");
    printf("1.LINER SEARCH\n");
    printf("2.BINARY SEARCH \n");
    printf("-------------------------\n");
    printf("Enter your choice : ");
    scanf("%d",&choice);

    clock_t t;
    t = clock();

    switch (choice)
    {
    case 1:
        linear_search(search_key,array,n);
        break;
    case 2:
        binary_search(search_key,array,n);
        break;
    
    default:
        exit(0);
    }

    t = clock() - t;
    double time_taken = ((double)t) / CLOCKS_PER_SEC; //SEC
    printf("Searching took %f second to execut \n",time_taken);


}

void linear_search(int search_key,int array[100],int n){
    int i,location;
    for(i=1;i<=n;i++){
        if(search_key == array[i]){
            location = i;
        }
    }
    printf("------------------------------------------\n");
    printf("YOUR CHOICE IS LINER SEARCHING \n");
    printf("THE LOCATION OF SEARCH KEY = %d IS %d \n",search_key,location);
    printf("------------------------------------------\n");
}

void binary_search(int search_key,int array[100],int n){
    int mid,i,low,high;
    low=1;
    high=n;
    mid=(low+high)/2;

    while(search_key != array[mid]){
        if(search_key <= array[mid]){
            low=1;
            high=mid+1;
            mid=(low+high)/2;
        }else{
            low=mid+1;
            high=n;
            mid=(low+high)/2;
        }
    }
    printf("----------------------------\n");
    printf("YOUR CHOICE IS BINARY SEARCHING \n");
    printf("LOCATION : %d \t",mid);
    printf("SEARCH KEY : %d found!!!\n",search_key);
    printf("----------------------------\n");
}
