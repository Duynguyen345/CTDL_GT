#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX 100

char stack[MAX];

int top = -1;


void push(int x){
	stack[++top] = x;
}

int pop(){
	return stack[top--];
}

int isnumber(char *s){
for(int i=0;s[i];i++){
	if(!isdigit(s[i])) return 0;
}
return 1;
}
 
int main(){
	char chuoi[1000];
	printf("vui long nhap chuoi hau to:");
	fgets(chuoi,sizeof(chuoi),stdin);
	chuoi[strcspn(chuoi,"\n")]  = '\0';
	
	char* token = strtok(chuoi," ");
	
	while(token !=NULL){
		if(isnumber(token)){
			push((atoi(token)));
			
		}
		else{
			int b = pop();
			int a = pop();
			int result ;
			if(strcmp(token,"+") ==0) result = a+b;
			if(strcmp(token,"-") ==0) result = a-b;
			if(strcmp(token,"*") ==0) result = a*b;
			if(strcmp(token,"/") ==0) result = a/b;
			push(result);
		}
		token = strtok(NULL," ");
	}
	printf("ket qua:%d",pop());
	
}

