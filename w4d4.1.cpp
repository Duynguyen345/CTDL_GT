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

void push(node **queue,int x){
	node *newnode = makenode(x);
	if(*queue == NULL){
		*queue = newnode;
		return;
	}
	node *tmp = *queue;
	while(tmp->next!= NULL){
		tmp=tmp->next;
	}
	tmp->next = newnode;
	
}
void pop(node **queue){
	if(*queue == NULL) return;
	node *tmp = *queue;
	*queue = (*queue)->next;
	free(tmp);
}
int size(node *queue){
	int ans=0;
	while(queue!=NULL){
	ans ++;
	queue = queue->next;
}
return ans;

}

int front(node *queue){
	return queue->data;
}
void duyet(node *queue){
	while(queue!=NULL){
	printf("%d ",queue->data);
	queue = queue->next;
}
}
bool empty(node *queue){
	return queue == NULL;
}
int main(){
	node *queue = NULL;
	int lc;
	do{
		printf("\n----------MENU---------\n");
		printf("1. push\n");
		printf("2. pop\n");
		printf("3. front\n");
		printf("4. size\n");
		printf("5. empty\n");
		printf("6. duyet\n");
		printf("0. thoat!\n");
		
		printf("nhap lua chon:");
		scanf("%d",&lc);
		switch(lc){
			case 1:
				int x;
				scanf("%d",&x);
				push(&queue,x);
				break;
			case 2:
				pop(&queue);
				break;
			case 3:
				printf("%d\n",front(queue));
				break;
			case 4:
				printf("size:%d\n",size(queue));
				break;
			case 5:
				if(empty(queue)){
					printf("empty!!\n");
				}
				
				break;
			case 6:
				duyet(queue);
				break;
			case 0:
				break;
			default:
				printf("invalid!!!\n");
		}
	}
	while(lc!=0);
}
