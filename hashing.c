#include<stdio.h>
#include<stdlib.h>
#define SIZE 5
int main(){
    int hashtable[5];
    int i,key,index,keys[SIZE];
    printf("Enter values:");
    for(i=0;i<SIZE;i++){
        scanf("%D",&keys[i]);
    }int n=5;
    for(i=0;i<SIZE;i++){
        hashtable[i]=-999;
    }
    for(i=0;i<n;i++){
        key=keys[i];
        index=key%SIZE;
        while(hashtable[index]!=-999){
            index=(index+i)%SIZE;
        }
        hashtable[index]=key;
    }
    printf("\nPrinting the hash table:\n");
    for(i=0;i<SIZE;i++)
        printf("%d  ",hashtable[i]);

    return 0;
}