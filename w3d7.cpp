#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
	char name[50];
	struct node *next;
};

node *makenode(char ten[]){
	node *newnode = (node*)malloc(sizeof(node));
	newnode->next = NULL;
	   strcpy(newnode->name, ten); 
	return newnode;
}

void pushback(node **head,char ten[]){
	node *newnode = makenode(ten);
	if(*head == NULL){
		*head = newnode;
		return;
	}
	node *tmp = *head;
	while(tmp->next != NULL){
		tmp = tmp->next;
	}
	tmp->next = newnode;
}
void inDanhSachMonHoc(node* head) {
    printf("Danh sách môn h?c:\n");
    while (head != NULL) {
        printf("- %s\n", head->name);
        head = head->next;
    }
}
void popname(node **head,char tencanxoa[]){
	node *tmp = *head;
	node *prev = NULL;
	
	if(tmp !=NULL && strcmp(tmp->name,tencanxoa) ==0){
		*head = tmp->next;
		free(tmp);
		return;
	}
	
	while(tmp != NULL && strcmp(tmp->name,tencanxoa) != 0){
		prev = tmp;
		tmp = tmp->next;
	}
	
	if(tmp == NULL){
		printf("khong tim thay!");
		return;
	}
	
	prev->next = tmp->next;
	free(tmp);
}
