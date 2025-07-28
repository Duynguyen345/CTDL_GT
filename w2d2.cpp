#include <stdio.h>
#include <stdlib.h>



struct node{
	int data;
	struct node *next;
	
};


node *makenode(int x){
	node *newnode = (node*)malloc(sizeof(node));
	newnode->data = x;
	newnode->next = NULL;
	return newnode;
	
}
void duyet(node *head){
    while(head != NULL){
        printf("%d ", head->data);
        head = head->next; // cho head chuyen sang node ke tiep
    }
}


int count(node *head){
	int count = 0;
	while(head!=NULL){
		count++;
		head = head->next;		
	}
}

void pushfront(node **head,int x){
	node *newnode = makenode(x);
	newnode->next = *head;
	*head = newnode;
}

int main(){
	node *head = NULL;
	for(int i=1;i<5;i++){
		pushfront(&head,i);
	}
	duyet(head);
	return 0;
}
