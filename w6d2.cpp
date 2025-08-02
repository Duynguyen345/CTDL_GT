#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

typedef struct node{
	char data;
	struct node *left;
	struct node *right;
	
}node;

#define MAX 100
node *stack[MAX];
int top = -1;

void push(node* x){
	stack[++top] = x;
}

node *pop(){
	return stack[top--];
}

node *makenode(char val){
	node* newnode = (node*)malloc(sizeof(node));
	newnode->data = val;
	newnode->left = newnode->right = NULL;
	return newnode;
}

node *buildtree(char postfix[]){

	for(int i = 0;postfix[i];i++){
			char cha = postfix[i];
		if(isdigit(cha)){
			push(makenode(cha));
		}
		else{
			node* node = makenode(postfix[i]);
				node->right = pop();
			node->left = pop();
		
			push(node);
			
		}
		
	} return pop();
}

void postOrder(node* root){
	if(root){
		postOrder(root->left);
		postOrder(root->right);
		printf("%c ",root->data);
	}
}
int main() {
    char postfix[] = "53+82-*";  // (5 + 3) * (8 - 2)

    node* root = buildtree(postfix);

    printf("Duyet hau to cua cay: ");
    postOrder(root);  // K?t qu?: 5 3 + 8 2 - *
    return 0;
}
