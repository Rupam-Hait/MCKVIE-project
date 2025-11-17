#include<stdio.h>
#include<stdlib.h>
typedef struct BST{
	int val;
	struct BST *left, *right;
}Node;
Node* create(int val){
	Node* root = (Node*)malloc(sizeof(Node));
	root->val = val;
	root->left = root->right = NULL;	
}
Node* insert(Node* root,int val){
	if(root==NULL) return create(val);
	if(val<root->val) root->left = insert(root->left,val);
	else if(val>root->val) root->right = insert(root->right,val);
	return root;
}
void Inorder(Node *root){
	if(root==NULL){
		return;
	}
	Inorder(root->left);
	printf("%d ",root->val);
	Inorder(root->right);
}
void Preorder(Node *root){
	if(root==NULL){
		return;
	}
	printf("%d ",root->val);
	Preorder(root->left);
	Preorder(root->right);
}
void Postorder(Node *root){
	if(root==NULL){
		return;
	}
	Postorder(root->left);
	Postorder(root->right);
	printf("%d ",root->val);
}
void main(){
	int choice,val,display;
	Node* root = NULL;
	while(choice!=3){
		printf("\n1. Insert\n2. Display\n3. Exit\nEnter your choice: ");
		scanf("%d",&choice);
		switch(choice){
		case 1:
			printf("Enter the value: ");
			scanf("%d",&val);
			root = insert(root,val);
			break;
					
		case 2:
			printf("1. Inorder\n2. Preorder\n3. Postorder\nEnter your choice: ");
			scanf("%d",&display);
			switch(display){
				case 1:
					printf("Inorder Traversal: ");
					Inorder(root);
					break;
				case 2:
					printf("Preorder Traversal: ");
					Preorder(root);
					break;
				case 3:
					printf("Postorder Traversal: ");
					Postorder(root);
					break;	
				default:
					break;	
				}
		default:
			break;	
			}
		
		}
		

	}

