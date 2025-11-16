#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;
};struct Node* top=NULL;
void push(int val){
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    if(newNode==NULL){
        printf("\nstack overflow!!!");
        return;
    }
    else{
        newNode->data=val;
        newNode->next=top;
        top=newNode;
        printf("\n%d pushed to stack.\n",val);
    }
}
void pop(){
    if(top==NULL){
        printf("\nStack underflow!!!");
    }
    else{
        struct Node* temp=top;
        printf("\nPoped element:%d",top->data);
        top=top->next;
        free(temp);
    }
}
void display(){
    if(top==NULL){
        printf("\nStack is empty!");
    }
    else{
        struct Node*temp=top;
        printf("\nStack elements are:");
        while(temp!=NULL){
            printf("%d  ",temp->data);
            temp=temp->next;
        }
    }
}
int main(){
    int choice,value;
    while(1){
        printf("\nEnter your choice:\nPress 1 for push an element.\nPress 2 for pop an element.\nPress 3 for display.\nPress 4 for exit the program.\n::::");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("\nEnter the value to push:");
                scanf("%d",&value);
                push(value);
                break;
            case 2:
                pop(value);
                break;
            case 3:
                display();
                break;
            case 4:
                printf("\nExiting the program.");
                exit(0);
                break;
        }

    }
}