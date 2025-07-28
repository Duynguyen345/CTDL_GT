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
		pushfront(head,x); return;
	}
	node *tmp = *head;
	for(int i=1;i<=k-2;i++){
		tmp = tmp->next;
	}
	node *newnode = makenode(x);
	newnode->next = tmp->next;
	tmp->next = newnode;
	
}

void popfront(node **head){
	if(*head == NULL) return;
	node *tmp = *head;
	*head = (*head)->next;
	free(tmp);
}

void popback(node **head){
	if(*head == NULL) return;
	node *tmp = *head;
	if(tmp->next == NULL){
		*head = NULL; free(tmp);
		return;
	}
	while(tmp->next->next != NULL){
		tmp = tmp->next;
		
	}
	node *last = tmp->next;
	tmp->next = NULL;
	free(last);
	
}

void popmid(node **head,int k){
	int n = size(*head);
	if(k<1 || k>n) return;
		node *tmp = *head;
	if(k == 1){
	 popfront(head);
}
	else{
		
		for(int i=1;i<=k-2;i++){
			tmp = tmp->next;
		}
		node *kth = tmp->next;
	tmp->next = kth->next;
	free(kth);
}	
	}
void search(node *head,int y){
	int found = 0;
	int pos = 1;
	while(head != NULL){
		if(head->data == y){
			found = 1;
			printf("da tim thay %d, o vi tri %d.\n",y,pos);
			
		}
		head = head->next;
		pos++;
		
	}
	if(found == 0) printf("khong tim thay!");
	
}

void reverse(node **head){
	node *prev = NULL;
	node *curr = *head;
	node *next = NULL;
	while(curr!=NULL){
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	*head = prev;
}

int tong(node *head){
	int sum=0;
	if(head == NULL) return 0;
	while(head != NULL){
		head =head->next;
		sum += head->data;
	}
	return sum;
}
	
int main(){
	node *head = NULL;
	int chon,x,y,k;
	
	do{
		printf("\n---------MENU----------\n");
		printf(" 1. them vao dau:\n");
		printf(" 2. them vao giua:\n");
		printf(" 3. them vao cuoi:\n");
		printf(" 4. xoa dau:\n");
		printf(" 5. xoa cuoi:\n");
		printf(" 6. xoa giua:\n");
		printf(" 7. tim kiem:\n");
		printf(" 8. dao nguoc:\n");
		printf(" 9. tinh tong:\n");
		printf(" 10.duyet:\n");
		printf(" 0. thoat:\n");
		printf("\n-------------------------\n");
		printf(" nhap lua chon:\n");
		scanf("%d",&chon);
		
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
				popfront(&head);
				break;
			case 5:
				popback(&head);
				break;
			case 6:
				printf("vui long nhap vi  tri:\n");
			
				scanf("%d",&k);
				popmid(&head,k);
				break;
			case 7:
				printf("nhap so can tim:");
				scanf("%d",&y);
				search(head,y);
				break;
			case 8:
				reverse(&head);
				break;
			case 9:
				printf("tong la:%d",tong(head));
				break;
			case 10:
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
