// on my new account after a long time also this is my first code on BST , so yeah i'm excited lets go for it.

#include<stdio.h>
#include<stdlib.h>

static int idx=-1;
struct Node{
	int data;
	struct Node* left;
	struct Node* right;
};
struct Node* creatNode(int val){
	struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
	if(!newNode){
		printf("Node creating faild!");
		exit(1);
	}
	newNode->data=val;
	newNode->left=NULL;
	newNode->right=NULL;
	
	return newNode;
}
struct Node* buildTree(int arr[],int n){
	idx++;
	if(idx>=n || arr[idx]==-1) return NULL;
	struct Node* root=creatNode(arr[idx]);
	root->left=buildTree(arr,n);
	root->right=buildTree(arr,n);
	
	return root;
}
void preOrder(struct Node* root){
	if(root==NULL) return;
	printf("%d ",root->data);
	preOrder(root->left);
	preOrder(root->right);
}

void inOrder(struct Node* root){
	if(root==NULL){
		return;
	}
	inOrder(root->left);
	printf("%d ",root->data);
	inOrder(root->right);
}

void postOrder(struct Node* root){
	if(root==NULL) return;
	postOrder(root->left);
	postOrder(root->right);
	printf("%d ",root->data);
	
}

void levelOrder(struct Node* root) {
    if (root == NULL) return;

    struct Node* queue[100]; 
    int front = 0, rear = 0;

    queue[rear++] = root;

    while (front < rear) {
        int count = rear - front; 

        while (count > 0) {
            struct Node* curr = queue[front++]; 
            printf("%d ", curr->data);

            if (curr->left != NULL) queue[rear++] = curr->left;
            if (curr->right != NULL) queue[rear++] = curr->right;

            count--;
        }
        printf("\n"); 
    }
}

int main(){
	int n,i;
    printf("Enter number of elements in array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter elements (-1 for NULL nodes):\n");
    for (i = 0; i < n; i++) {
    	
        scanf("%d ", &arr[i]);
        
	}

    struct Node* root = buildTree(arr, n);

    printf("\nPreorder Traversal: ");
    preOrder(root);

    printf("\nInorder Traversal: ");
    inOrder(root);

    printf("\nPostorder Traversal: ");
    postOrder(root);
    
    printf("\nthe tree is:\n");
    levelOrder(root);

    return 0;
}


