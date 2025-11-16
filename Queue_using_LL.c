#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;
};struct Node* front = NULL;
struct Node* rear = NULL;
void enque(int value){
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    if(newNode==NULL){
        printf("\nMemory allocation faild.");
    }
    newNode->data=value;
    newNode->next=NULL;
    if(rear==NULL){
        front=rear=newNode;
    }
    else{
        rear->next=newNode;
        rear=newNode;
    }printf("\n%d Enqued to the queue.",value);
}
void delque(){
    if(front==NULL){
        printf("QUEUE underflow.");
    }
    struct Node* temp=front;
    printf("Dequed element:%d",front->data);
    front=front->next;
    if(front==NULL) rear=NULL;
    free(temp);
}
void display(){
    if(front==NULL){
        printf("\nQueue is empty!");
    }
    else{
        struct Node* temp=front;
        printf("\nQueue elements:");
        while(temp!=NULL){
            printf("%d  ",temp->data);
            temp=temp->next;
       }
       printf("\n");
    }
}
int main(){
    int choice,value;
    while(1){
        printf("\nPress 1 for insert.\nPress 2 for delete.\nPress 3 for display\nPress 4 for exit.\nEnter your choice:::");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter value:");
                scanf("%d",&value);
                enque(value);
                break;
            case 2:
                delque();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting the program.");
                exit(0);
        }
    }
    return 0;

}