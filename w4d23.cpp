#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *next;
};


typedef struct node node;

node *makenode(int x){
	node *newnode = (node*)malloc(sizeof(node));
	newnode->data = x;
	newnode->next = NULL;
	return newnode;
}

void push(node **top,int x){
	node *newnode = makenode(x);
	if(*top == NULL){
		*top = newnode;
		 return;
	}
	newnode->next = *top;
	*top  = newnode;
}

void pop(node **top){
	if(*top != NULL){
		node *tmp = *top;
		(*top) = tmp->next;
		free(tmp);
		
	}
}

int Top1(node *top){
	if(top != NULL)
		return top->data;
	
}

int size(node *top){
	int ans = 0;
	while(top!=NULL){
		++ans;
		top = top->next;
	}
	return ans;
}
int main(){
	int lc;
	node *st = NULL;
	do{
		printf("\n------------------------------\n");
		printf("1. push\n");
		printf("2. pop\n");
		printf("3. top\n");
		printf("4. size\n");
		printf("0. thoat\n");
		printf("\n--------------------------------\n");
		
		scanf("%d",&lc);
		getchar();
		switch(lc){
			case 1:{
			
			
				int x;
				printf("nhap x:\n");
				scanf("%d",&x);
				push(&st,x);
				break;
			}	
			case 2:
				pop(&st);
				break;
			case 3:
				if(st==NULL) printf("EMPTY\n");
				printf("%d",Top1(st));
				break;
			case 4:
				printf("size:%d\n",size(st));
				break;
			case 0:
				printf("da thoat!!!\n");
				break;
			default:
				printf("INVALID!!!\n");
		}
		
		
	}
	while(lc!=0);
	
}
