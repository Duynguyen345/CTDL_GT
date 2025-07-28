#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node *next;
	struct node *prev;
}node;

node *makenode(int x){
	node *newnode = (node*)malloc(sizeof(node));
	newnode->next = NULL;
	newnode->data = x;
	newnode->prev = NULL;
	return newnode;
}

void pushfront(node **head,int x){
	node *newnode = makenode(x);
	if(*head != NULL){
	
	newnode->next = *head;
	(*head)->prev = newnode;
	
}   *head = newnode;
}
void pushback(node **head,int x){
	node *newnode = makenode(x);
	if(*head == NULL){
		*head = newnode;
		return;
	}
	node *tmp = *head;
	while(tmp->next != NULL){
		tmp=tmp->next;
		
	}
	tmp->next = newnode;
	newnode->prev =tmp;
	
}

void duyet(node *head){
	while(head != NULL){
		printf("%d ",head->data);
		head = head->next;
	}
}

int main(){
	node *head = NULL;
	for(int i=1;i<5;i++){
		pushfront(&head,i);
	}
	for(int i=5;i<10;i++){
		pushback(&head,i);
	}
	duyet(head);
	
}
