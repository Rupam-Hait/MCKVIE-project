#include<stdio.h>
#include<stdlib.h>
#define SIZE 10
int arr[SIZE];
int partition(int l,int h){
	int p=l;
	int i=l+1;
	int j=h;
	int temp;
	while(i<=j){
		while(i <= h && arr[i]<=arr[p])	i++;
		while(j >= l+1 && arr[j]>arr[p])	j--;
		if(i<j){
			temp=arr[i];
			arr[i]=arr[j];
			arr[j]=temp;
		}
	}
	temp=arr[j];
	arr[j]=arr[p];
	arr[p]=temp;
	
	return j;
}
void quick_sort(int i,int j){
	int m;
	if(i<j){
		m=partition(i,j);
		quick_sort(i,m-1);
		quick_sort(m+1,j);
		
	}
}
int main(){
	int n,i;
	printf("Enter size of the array:");
	scanf("%d",&n);
	printf("\nEnter elements in the array:");
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	printf("The array is:");
	for(i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
	quick_sort(0,n-1);
	printf("\nArray after quick sort is:");
	for(i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
	return 0;
}
