#include <stdio.h>

int s[10000];
int top = -1;

void push(int x){
	s[++top] = x;
	
}
int pop(){
	return s[top--];
}
int empty(){
	return top == -1;
}
void converttobinary(int n){
	while(n!=0){
		push(n%2);
		n/=2;
	}
	while(!empty()){
		printf("%d ",pop());
	}
	printf("\n");
}
int main(){
	int n;
	printf("nhap n:\n");
	scanf("%d",&n);
	converttobinary(n);
	return 0;
}
