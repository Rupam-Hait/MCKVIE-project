#include<stdio.h>
#include<stdlib.h>
#define SIZE 10
int arr[SIZE];
void bubbleSort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}
void selectionSort(int arr[],int n){
    int i,j,min,temp;
    for(i=0;i<n-1;i++){
        min=i;
        for(j=i+1;j<n;j++){
            if(arr[j]<arr[min]){
                min=j;
            }
        }
        temp=arr[i];
        arr[i]=arr[min];
        arr[min]=temp;
    }
}
void insertionSort(int arr[],int n){
    int i,j,key;
    for(i=1;i<n;i++){
        key=arr[i];
        j=i-1;
        while(j>=0 && arr[i]>key){
            arr[j+1]=arr[j];
            j--;
        }arr[j+1]=key;
    }
}
void display(int arr[],int n){
    printf("Sorted array: ");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}
int main(){
    int n,choice,i;
    printf("Enter size of the array:");
    scanf("%d",&n);
    printf("Enter %d elements in the Array:-",n);
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    
    while(1){
        printf("\nEnter your choice:\nPress 1 for Bubble sort.\nPress 2 for selection sort.\nPress 3 for insertion sort.\nPress 4 for exit.\n:::");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("\nAfter bubble sort:");
                bubbleSort(arr,n);
                display(arr,n);
                break;
            case 2:
                printf("\nAfter selection sort:");
                selectionSort(arr,n);
                display(arr,n);
                break;
            case 3:
                printf("\nAfter insertion sort:");
                insertionSort(arr,n);
                display(arr,n);
                break;
            case 4:
                printf("\nExiting the program.");
                exit(0);
                break;
        }
    }
    return 0;
}