#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node;

node* makenode(int x) {
    node* newnode = (node*)malloc(sizeof(node));
    newnode->data = x;
    newnode->next = NULL;
    return newnode;
}

void pushfront(node **head,int x){
	node *newnode = makenode(x);
	if (*head == NULL){
		*head = newnode;
		newnode->next = *head;
		return;
	}
	node *tmp = *head;
	while(tmp->next != *head){
		tmp = tmp->next;
	}
	newnode->next = *head;
	tmp->next = newnode;
	*head = newnode;
	
}

void pushback(node **head,int x){
	node *newnode = makenode(x);
	if (*head == NULL){
		*head = newnode;
		newnode->next = *head;
		return;
	}
	
	node *tmp= *head;
	while(tmp->next != *head){
		tmp=tmp->next;
	}
	tmp->next = newnode;
	newnode->next = *head;
}
void popfront(node **head){
	if(*head == NULL) return;
	
	if((*head)->next == *head){
		free(*head);
		*head = NULL;
		return;
	}
	
	node *last = *head;
	node *tmp = *head;
	while(last->next != *head){
		last = last->next;
	}
	last->next = tmp->next;
	*head = tmp->next;
	free(tmp);
}
void popback(node **head){
	if(*head == NULL) return;
	
	if((*head)->next == *head){
		free(*head);
		*head = NULL;
		return;
	}
	
	node *prev = NULL;
	node *curr = *head;
	while(curr->next != *head){
		prev = curr;
		curr = curr->next;
	}
	prev->next = *head;
	free(curr);
}
void duyet(node *head) {
    if (head == NULL) return;
    node *tmp = head;
    do {
        printf("%d ", tmp->data);
        tmp = tmp->next;
    } while (tmp != head);
}
int main() {
    node *head = NULL;
    pushback(&head, 10);
    pushback(&head, 20);
    pushfront(&head, 5);
    pushback(&head, 30);

    printf("Danh sách sau khi thêm:\n");
    duyet(head); // 5 10 20 30

    popfront(&head);
    popback(&head);

    printf("\nSau khi xóa d?u và cu?i:\n");
    duyet(head); // 10 20
}
