#include<stdio.h>
#include<stdlib.h>
#define size 10
int arr[size];
int linear_search(int n,int i){
    int key,j=0;
    for(i=0;i<n;i++){
        printf("\nItretion:%d",++j);
        if(arr[i]==key){
            printf("\nAt %d position %d found.",i,key);
            return i;
        }
    }return -1;
}

int binary_search(int n,int j,int key){
    int low=0;
    int high=n-1;
    j=0;
    int mid;
    while(low<=high){
        printf("\nItretion:%d",++j);
        mid=low+(high-low)/2;
        if(arr[mid]==key){
            printf("\nAt %d position %d found.",mid,key);
            return mid;
        }
        else if(arr[mid]>high)
            high=mid-1;
        else    
            low=mid+1;
    }
    return -1;
}

int interpoletion_search(int n,int j,int key){
    int low=0;
    int high=n-1;
    j=0;
    int mid;
    while(low<=high){
        printf("\nItreation:%d",++j);
        mid=low+(high-low)*((key-arr[low]/arr[high]-arr[low]));
        if(arr[mid]==key){
            printf("\nAt %d position %d found.",mid,key);
            return mid;
        }
        else if(arr[mid]>high)
            high=mid-1;
        else    
            low=mid+1;
    }
    return -1;
}

int main(){
    int n,i,key;
    printf("\nEnter the size of the array:");
    scanf("%d",&n);
    printf("\nEnter %d elements in the array:",n);
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("\nArray is:");
    for(i=0;i<n;i++){
        printf("%d",arr[i]);
    }
    int choice;
    printf("\nEnter the value you want to search:");
    scanf("%d",&key);
    printf("\nPress 1 for linear search.\nPress 2 for binary search.\nPress 3 for interpolation search.\npress 4 for exit.\nEnter your choice:(1/2/3/4):");
    scanf("%d",&choice);
    while(choice<=4){
        switch(choice){
            case 1:
                if(linear_search(arr,n,key)==-1)
                    printf("Element do not found.");
                break;
            case 2:
                if(binary_search(arr,n,key)==-1)
                    printf("Element do not found.");
                break;
            case 3:
                if(interpoletion_search(arr,n,key)==-1)
                    printf("Element do not found.");
                break;
            case 4:
                printf("Exiting the program!!!");
                exit(0);
                break;  
           }
    }
    return 0;
    
    
}
