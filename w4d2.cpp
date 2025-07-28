#include <stdio.h>
#include <stdlib.h>

int n=0, st[100001];

void push(int x){
	st[n] = x;
	++n;
} 

void pop(){
	if(n>=1) 
	--n;
}
int top(){
	return st[n-1];
}
int size(){
	return n;
}
int main(){
	int lc;
	do{
		printf("\n------------------------------\n");
		printf("1. push\n");
		printf("2. pop\n");
		printf("3. top\n");
		printf("4. size\n");
		printf("0. thoat\n");
		printf("\n--------------------------------\n");
		
		scanf("%d",&lc);
		getchar();
		switch(lc){
			case 1:
				int x;
				printf("nhap x:\n");
				scanf("%d",&x);
				push(x);
				break;
			case 2:
				pop();
				break;
			case 3:
				if(n==0) printf("EMPTY\n");
				printf("%d",top());
				break;
			case 4:
				printf("size:%d\n",size());
				break;
			case 0:
				printf("da thoat!!!\n");
				break;
			default:
				printf("INVALID!!!\n");
		}
		
		
	}
	while(lc!=0);
	
}
