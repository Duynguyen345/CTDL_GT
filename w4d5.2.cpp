#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char stack[1000];
int top = -1;


void push(char c){
	stack[++top] = c;
	
}
char pop(){
	return stack[top--];
	
}
char  peek(){
	return stack[top];
}

int isempty(){
	return top==-1;
}

int ismatching(char open,char close){
	return (open=='(' && close ==')') || (open=='[' && close ==']') || (open=='{' && close=='}') ;
	
}

int check(char s[]){
	for(int i=0;i<strlen(s);i++){
		char c = s[i];
		if(c =='(' || c=='[' || c=='{'){
			push(c);
			
		}
		else if(c==')' || c==']' || c=='}'){
			if(isempty() || !ismatching(peek(),c)){
				return 0;
			}
			pop();
			
		}
	}
	return isempty();
}

int main(){
	char s[100];
	printf("nhap chuoi:");
	gets(s);
	if(check(s)){
		printf("chuoi hop le!");
		
	}
	else{
		printf("khong hop le");
	}
}


