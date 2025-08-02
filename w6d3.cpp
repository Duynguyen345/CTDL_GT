#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	char data;
	struct node* firstchild;
	struct node* nextsibling;
	
}node;


node *createnode(char val){
	node* newnode = (node*)malloc(sizeof(node));
	newnode->data = val;
	newnode->firstchild = NULL;
	newnode->nextsibling = NULL;
	return newnode;
}

void addChild(node* parent,node* child){
	if(parent->firstchild == NULL){
		parent->firstchild = child;
	}
	else{
		node *tmp = parent->firstchild;
		while(tmp->nextsibling != NULL){
			tmp = tmp->nextsibling;
		}
		tmp->nextsibling = child;
	}
	
}
void preOrder(node *root){
	if(root){
		printf("%c ",root->data);
		preOrder(root->firstchild);
		preOrder(root->nextsibling);
	}
}

void postOrder(node *root){
	if(root){
		postOrder(root->firstchild);
		postOrder(root->nextsibling);
		printf("%c ",root->data);
		
	}
}
int countnode(node* root){
	if(!root) return 0;
	return 1 + countnode(root->firstchild) + countnode(root->nextsibling);
}
int countLeaves(node* root){
		if(!root) return 0;
		if(root->firstchild == NULL) return 1;
	return  countLeaves(root->firstchild) + countLeaves(root->nextsibling);
}
int height(node* root){
	if(!root) return 0;
	
	int hchild = height(root->firstchild);
	int hsibling = height(root->nextsibling);
	return (hchild+1 > hsibling)? hchild + 1 : hsibling;
}

int main() {
    // Cây m?u: A có 3 con B, C, D. D có 1 con E
    node* A = createnode('A');
    node* B = createnode('B');
    node* C = createnode('C');
    node* D = createnode('D');
    node* E = createnode('E');

    addChild(A, B);
    addChild(A, C);
    addChild(A, D);
    addChild(D, E); // D có 1 con E

    printf("Duyet tien to: ");
    preOrder(A);   // A B C D E
    printf("\n");

    printf("Duyet hau to: ");
    postOrder(A);  // B C E D A
    printf("\n");

    printf("So nut: %d\n", countnode(A));       // 5
    printf("So la: %d\n", countLeaves(A));        // 3 (B, C, E)
    printf("Chieu cao cay: %d\n", height(A));     // 3

    return 0;
}

