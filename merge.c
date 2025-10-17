#include<stdio.h>
#include<stdlib.h>
#define size 10
int arr[size],temp[size],n;
void merge_sort(int arr[],int low,int high){
    int mid,i;
    if(low<high){
        mid=(high+low)/2;
        merge_sort(arr,low,mid);
        merge_sort(arr,mid+1,high);
        merge(arr,low,mid,high);
    }
       
}
void merge(int arr[],int low,int mid,int high){
	int l=low;
	int i=low;
	int j=mid+1;
	int k;
    while((l<=mid)&& (j<=high)){
    	if(arr[l]<=arr[j]){
    		temp[i]=arr[l];
    		l++;
		}
		else{
			temp[i]=arr[j];
			j++;
		}
		i++;
	}
	if(l>mid){
		for(k=j;k<=high;k++){
			temp[i]=arr[k];
			i++;
		}
	}
	else{
		for(k=l;k<=mid;k++){
			temp[i]=arr[k];
			i++;
		}
	}
	for(k = low; k <= high; k++){
    arr[k] = temp[k];
	}

	
}
int main(){
    int n,i;
    printf("Enter the size of the array:");
    scanf("%d",&n);
    printf("Enter array elements in the array:");
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("Array is:");
    for(i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    //my real name is royal
    merge_sort(arr,0,n-1);
    printf("\nAfter merge sort array is: ");
	for(i=0; i<n; i++){
    	printf("%d ", arr[i]);
	}
    return 0;
}
//binary search is more important than anything. so i can find the original state of programing.in every year there is a certain time of 
