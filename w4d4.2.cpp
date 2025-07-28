#include <stdio.h>
#include <stdlib.h>


int a[100000] , nmax = 100000;
int n=0;
int size(){
	return n;
}

bool empty(){
	return n==0;
	
}

void push(int x){
	if(n==nmax) return;
	a[n] = x; 
	n++;
}

void pop(){
	if(n==0){
		return;
	}
	for(int i=0;i<n-1;i++){
		a[i] = a[i+1];
	}
	n--;
}

int front(){
	return a[0];
}
int main(){
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
				push(x);
				break;
			case 2:
				pop();
				break;
			case 3:
				front();
				break;
			case 4:
				printf("size:%d\n",size());
				break;
			case 5:
				if(empty()){
					printf("empty!!\n");
				}
				break;
			case 6:
				for(int i=0;i<n;i++){
					printf("%d ",a[i]);
				}
				break;
			case 0:
				break;
			default:
				printf("invalid!!!\n");
		}
	}
	while(lc!=0);
}
