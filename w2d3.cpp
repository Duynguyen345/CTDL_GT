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

void pushfront(node **head,int x){
	node *newnode = makenode(x);
	newnode->next = *head;
	*head = newnode;
}

void pushback(node **head,int x){
	node *newnode = makenode(x);
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

void duyet(node *head){
	while(head != NULL){
		printf("%d ",head->data);
		head = head->next; 
	}
}

int size(node *head){
	int count = 0;
	while(head != NULL){
		count++;
		head = head->next;
	}
	return count;
}

void insert(node **head,int x,int k){
	int n = size(*head);
	if(k<1 || k>n+1) return;
	if(k==1){
		pushfront(head,x);
	}
	node *tmp = *head;
	for(int i=1;i<=k-2;i++){
		tmp = tmp->next;
	}
	node *newnode = makenode(x);
	newnode->next = tmp->next;
	tmp->next = newnode;
	
}
int main(){
	node *head = NULL;
	int chon,x,k;
	
	do{
		printf("\n---------MENU----------\n");
		printf("1. them vao dau:\n");
		printf("2. them vao giua:\n");
		printf("3. them vao cuoi:\n");
		printf("4. duyet:\n");
		printf("0. thoat:\n");
		printf("\n-------------------------\n");
		printf(" nhap lua chon:\n");
		scanf("%d",&chon);
		getchar();
		switch(chon){
			case 1:
				
				printf("nhap x:\n");
				scanf("%d",&x);
				pushfront(&head,x);
				break;
			case 2:
				
				printf("nhap x va k:\n");
				scanf("%d %d",&x,&k);
				insert(&head,x,k);
				break;
				
			case 3:
				
			printf("nhap x:\n");
				scanf("%d",&x);
				pushback(&head,x);
				break;
			case 4:
				duyet(head);
				break;
			case 0:
				break;
			default:
				printf("vui long nhap lai!");
		}
	}
		while(chon!=0);
	
}
