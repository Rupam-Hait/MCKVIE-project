#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *next;

}Node;
struct Node* head=NULL;
struct  Node* create(int value){
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=value;
    newNode->next=NULL;
    return newNode;
}
void ins_beg(int value){
    struct Node* newNode=create(value);
    newNode->next=head;
    head=newNode;
    printf("\nInserted %d at begining.",value);
}
void ins_end(int value){
    struct Node* newNode=create(value);
    if(head==NULL){
        head=newNode;
    }
    else {
        struct Node *temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }

    printf("\nInserted %d at the end.",value);
}
void del_beg(int value){
    if(head==NULL){
        printf("List is empty.");
        return;
    }
    struct Node* temp=head;
    head=head->next;
    free(temp);
    printf("Element deleted from the begining.");
}
void del_end(int value){
    if(head==NULL){
        printf("List is empty.");
        return;
    }
    if(head->next==NULL){
        free(head);
        head=NULL;
    }
    else{
        struct Node* temp=head,*prev=NULL;
        while(temp->next!=NULL){
            prev=temp;
            temp=temp->next;
        }
        prev->next=NULL;
        free(temp);
    }
    printf("Element deleted from end.");
}
void display(){
     if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    struct Node *temp = head;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

}
int main(){
    int choice,value;
    
    while(1){
    	printf("\nPress 1 for insert at begining.\nPress 2 for insert at end.\nPress 3 for delete from begining.\nPress 4 for delete from end.\nPress 6 for exiting the program.\nPress 5 for display.\nEnter your choice(1,2,3,4,5,6):");
    	scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("\nEnter the element:");
                scanf("%d",&value);
                ins_beg(value);
                break;
            case 2:
                printf("\nEnter the element:");
                scanf("%d",&value);
                ins_end(value);
                break;
            case 3:
                
                del_beg(value);
                break;
            case 4:
                del_end(value);
                break;
            case 5:
                display();
                break;
            case 6:
                printf("Exiting the program.");
                exit(0);
                break;
        }
    }
    return 0;
}