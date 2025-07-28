#include <stdio.h>
#include <string.h>

char queue[100][100];
int front = 0,rear = 0;

void enqueue(char *name){
	strcpy(queue[rear++],name);
}

void dequeue(){
	if(rear == front) {
		printf("hang trong!!!\n");
		return;
	}
	else{
		printf("nguoi tiep theo:%s\n",queue[front++]);
	}
}
void showqueue(){
	printf("danh sach cho:\n");
	for(int i=front;i<rear;i++){
		printf("%s ",queue[i]);
	}
	printf("\n");
}

int main(){
	char action[100];
	int luachon;
	do{
		printf("\n-----------MENU---------------\n");
		printf("1. them nguoi.\n");
		printf("2. nguoi tiep theo\n");
		printf("3. hien thi hang doi\n");
		printf("0. thoat!!!\n");
		printf("nhap lua chon:");
		scanf("%d",&luachon);
		getchar();
		
		switch(luachon){
			case 1:
				fgets(action,sizeof(action),stdin);
				action[strcspn(action,"\n")] = '\0';
				enqueue(action);
				printf("da them: %s\n",action);
				break;
			case 2:
				dequeue();
				break;
			case 3:
				showqueue();
				break;
			case 0:
				break;
			default:
				printf("invalid!!!");
				break;
				
		}
	
	}	while(luachon);
}
