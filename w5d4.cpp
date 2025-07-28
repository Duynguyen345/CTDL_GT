#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node *right;
	struct node *left;
}node;

node* makenode(int x){
	node* newnode = (node*)malloc(sizeof(node));
	newnode->data = x;
	newnode->left = NULL;
	newnode->right = NULL;
	return newnode;
	
}

node* insert(node* root,int x){
	if(root == NULL){
		return makenode(x);
		
	}
	if(x<root->data){
		root->left = insert(root->left,x);
	}
	else if(x>root->data){
		root->right = insert(root->right,x);
	}
	
	return root;
}
void preorder(node* root){
	if(root != NULL){
		printf("%d ",root->data);
		preorder(root->left);
		preorder(root->right);
		
	}
}
void inorder(node* root){
	if(root != NULL){
		inorder(root->left);
		printf("%d ",root->data);
		
		inorder(root->right);
	}
}
void postorder(node* root){
	if(root != NULL){
		postorder(root->left);
		postorder(root->right);
		printf("%d ",root->data);
	}
}

node *search(node* root,int x){
	if(root == NULL || root->data==x){
		return root;
	}
	if(x<root->data){
		return search(root->left,x);
	}
	else{
		return search(root->right,x);
	}
}
int findmax(node* root){
	if(root == NULL) return -1;
	while(root->right != NULL)
	root = root->right;
	return root->data;
	
}
int findmin(node* root){
	if(root == NULL) return -1;
	while(root->left != NULL)
	root = root->left;
	return root->data;
	
}

int countnode(node* root){
	if(root == NULL) return 0;
	if(root->left==NULL && root->right == NULL){
		return 1;
	}
	return countnode(root->right) +countnode(root->left);
}

int main(){
	node* root = NULL;
	int lc;
		int x;
			int timkiem;
	do{		
		printf("\n-------------MEnu-----------\n");
	
		printf("1. them so vao tree\n");
		printf("2. in ra bang cach duyet truoc \n");
		printf("3. in ra bang cach duyet giua \n");
		printf("4. in ra bang cach duyet sau \n");
		printf("5. tim phan tu!\n");
		printf("6. tim phan tu lon nhat!\n");
		printf("7. tim phan tu be nhat!\n");
		printf("8. so node la!\n");
		printf("0. cut con me may ra ngoai!\n");
		printf("vui long nhap con me cai lua chon !!!:");
		scanf("%d",&lc);
		getchar();
		switch(lc){
			case 1:
				printf("nhap 1 so thoi!:");
			
				scanf("%d",&x);
				getchar();
				root =	insert(root,x);
				break;
			case 2:
				preorder(root);
				break;
			case 3:
				inorder(root);
				break;
			case 4:
				postorder(root);
				break;
			case 5:
			
				printf("nhap so can tim:");
				scanf("%d",&timkiem);
				
				if(search(root,timkiem)==NULL) printf("khong tim thay!\n");
				else printf("da tim thay!\n");
				break;
			case 6:{
			
			
				int maxt = findmax(root);
				if(maxt == -1){
					printf("cay rong!!!\n");
				}
				else{
					printf("phan tu max la:%d\n",maxt);
				}
				break;}
			case 7:{
				
			
				int mint= findmin(root);
				if(mint == -1){
					printf("cay rong!!!\n");
				}
				else{
					printf("phan tu min la:%d\n",mint);
				}
				break;}
			case 8:
				printf("so node la la:%d",countnode(root));
				break;
			case 0:
			break;
			default:
			printf("nhap sai r thang ngu!\n");		
		}
		
	}while(lc!=0);
}
