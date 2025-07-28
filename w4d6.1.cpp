#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100 

char undostack[MAX][100];
char redostack[MAX][100];

int undotop = -1;
int redotop = -1;

void pushundo(char* action){
	strcpy(undostack[++undotop],action);
}

void pushredo(char* action){
	strcpy(redostack[++redotop],action);
}

char* popundo(){
	return	undostack[undotop--];
}
char* popredo(){
	return redostack[redotop--];
}

int empundo(){
	return undotop == -1;
}
int empredo(){
	return redotop == -1;
}

int main(){
	char action[100];
	int luachon;
	do{
		printf("\n-----------MENU---------------\n");
		printf("1. thuc hien hanh dong.\n");
		printf("2. undo\n");
		printf("3. redo\n");
		printf("0. thoat!!!\n");
		printf("nhap lua chon:");
		scanf("%d",&luachon);
		getchar();
		
		switch(luachon){
			case 1:
				fgets(action,sizeof(action),stdin);
				action[strcspn(action,"\n")] = '\0';
				pushundo(action);
				redotop = -1;
				printf("da thuc hien: %s\n",action);
				break;
			case 2:
				if(empundo()){
					printf("nothing to undo!!!\n");
				}
				else{
					char* last = popundo();
					pushredo(last);
					printf("undo was completed:%s",last);
				}
				break;
			case 3:
				if(empredo()){
					printf("nothing to redo!!!\n");
				}
				else{
					char* last = popredo();
					pushundo(last);
					printf("redo was completed:%s",last);
				}
				break;
			case 0:
				break;
			default:
				printf("invalid!!!");
				break;
				
		}
	
	}	while(luachon);
}
