#include<stdio.h>
#include<stdlib.h>
#include<math.h>
typedef struct poly{
    int cof;
    int expo;

}poly;
int main(){
    poly p1[20];
    poly p2[20];
    poly p3[20];
    int i,j,k,l1,l2,l3;

    printf("\nEnter the no of elements in first polynomial:");
    scanf("%d",&l1);
    printf("\nEnter %d elements:",l1);
    for(i=0;i<=l1-1;i++){
        scanf("%d%d",p1[i].cof,p1[i].expo);
    }
    for(i=0;i<l1-1;i++){
        printf("%dX^%d+",p1[i].cof,p1[i].expo);
    }printf("%dX^%d",p1[i].cof,p1[i].expo);

    printf("\nEnter the no of elements in second polynomial:");
    scanf("%d",&l2);
    printf("\nEnter %d elements:",l2);
    for(i=0;i<=l2-1;i++){
        scanf("%d%d",p2[i].cof,p2[i].expo);
    }
    for(i=0;i<l2-1;i++){
        printf("%dX^%d+",p2[i].cof,p2[i].expo);
    }printf("%dX^%d",p2[i].cof,p2[i].expo);

    while(i<l1 && j<l2){
        if(p1[i].expo==p2[j].expo){
            p3[k].cof=p1[i].cof+p2[j].cof;
            p3[k].expo=p1[i].expo;
            i++,j++;
        }
        else if(p1[i].expo>p2[j].expo){
            p3[k].cof=p1[i].cof;
            p3[k].expo=p1[i].expo;
            i++;
        }
        else{
            p3[k].cof=p2[j].cof;
            p3[k].expo=p2[j].expo;
            j++;

        }k++;
    }
    while(i<l1){
        p3[k].cof=p1[i].cof;
        p3[k].expo=p1[i].expo;
        i++,k++;
    }
    while(i<l2){
        p3[k].cof=p2[j].cof;
        p3[k].expo=p2[j].expo;
        j++,k++;

    }
    printf("\nAfter addition the final polynimial is: ");
    for(i=0;i<k;i++){
        if(p1[i].expo==0)
            printf("%d",p3[i].cof);
        else if(p1[i].expo==1)
            printf("%dX+",p3[i].cof);
        else
            printf("%dX^%d+",p3[i].cof,p3[i].expo);
    }

    return 0;
}