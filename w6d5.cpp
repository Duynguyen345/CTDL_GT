#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int val;
	struct node *left,*right;
}node;


node* createNode(int x){
	node* newnode = (node*)malloc(sizeof(node));
	newnode->val = x;
	newnode->left = newnode->right = NULL;
	return newnode;
}

#define MAX 100

node* queue[MAX];
int front = 0,rear = -1;

void enqueue(node* x){
	queue[++rear] = x; 
}

node* dequeue(){
	return queue[front++];
}

int isEmpty(){
	return front > rear;
}

void BFS(node* root){
	if(root==NULL) return;
	enqueue(root);
	
	while(!isEmpty()){
		node* cur = dequeue();
		printf("%d ",cur->val);
		if(cur->left != NULL){
			enqueue(cur->left);
					}

		if(cur->right != NULL){
			enqueue(cur->right);
		}
	}
}

int main() {
    node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    printf("Duyet BFS: ");
    BFS(root);  // Output: 1 2 3 4 5 6 7

    return 0;
}
