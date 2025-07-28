#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
	int data;
	struct node *next;
	struct node *prev;
}node;
typedef struct node node;
node *makenode(int x){
	node *newnode = (node*)malloc(sizeof(node));
	newnode->data = x;
	newnode->next = NULL;
	newnode->prev = NULL;
	return newnode;
}

void pushfront(node **head,int x){
	node *newnode = makenode(x);
	if(*head != NULL){
		newnode->next = *head;
		(*head)->prev = newnode;
		
	} *head = newnode;
	
}

void popfront(node **head){
	if(*head == NULL) return;
	
	node *tmp = *head;
	if(*head != NULL){
		*head = (*head)->next;
		(*head)->prev = NULL;
	}
	free(tmp);
}
void duyet1(node *head){
    while(head != NULL){
        printf("%d ", head->data);
        head = head->next; // cho head chuyen sang node ke tiep
    }
}
void popback(node **head){
	if(*head ==NULL) return;
	if((*head)->next == NULL ){
		free(*head);
		*head = NULL;
	}
	else{
		node *tmp = *head;
		while(tmp->next->next != NULL){
			tmp = tmp->next;
		}
		node *last = tmp->next;;
		tmp->next = NULL;
		free(last); 
	}
}

int len(node *head){
	int cnt = 0;
	while(head != NULL){
		cnt++;
		head = head->next;
		
	}
	return cnt;
}

void popmid(node **head,int k){
	int leng = len(*head);
	if(k<1 || k>leng){
		popfront(head);
	
	}
	else{
		node *tmp = *head;
		for(int i=1;i<=k-1;i++){
			tmp = tmp->next;
		}
		node *del = tmp;
		tmp->prev->next = tmp->next;
		if(tmp->next != NULL){
			tmp->next->prev = tmp->prev;
		}
		free(del);
	}
	
}
void duyet2(node* head) {
    node* temp = head;
    if (temp == NULL) return;

    while (temp->next != NULL)
        temp = temp->next;

    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
}
int main(){
    node *head = NULL;
    for(int i = 1; i <= 10; i++){
        pushfront(&head, i);
    }
    
    duyet1(head);
    printf("\n");
    duyet2(head);
    popfront(&head);
    popback(&head);
    popmid(&head, 3);
    printf("\n");
    duyet1(head);
    printf("\n");
    duyet2(head);
}
