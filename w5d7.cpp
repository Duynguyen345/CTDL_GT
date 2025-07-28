#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct node {
	int masach;
	char tensach[100];
	struct node *left, *right;
} node;

node *makenode(int id,char name[]){
	node *newnode = (node*)malloc(sizeof(node));
	newnode->left = NULL;
	newnode->right = NULL;
	newnode->masach = id;
	strcpy(newnode->tensach,name);
	return newnode;
}

node *insert(node* root,int id,char name[]){
	if(root == NULL){
		return makenode(id,name);
	}
	else if(id<root->masach){
		root->left = insert(root->left,id,name);
	}
	else if(id>root->masach){
		root->right = insert(root->right,id,name);
	}
	return root;
}
void inorder(node* root){
	if(root != NULL){
		inorder(root->left);
		printf("%d ",root->masach);
		printf("%s ",root->tensach);
		inorder(root->right);
	}
}
node *search(node* root,int id){
	if(root==NULL || root->masach==id){
	
	return root;
	}
	else if(id<root->masach){
		return search(root->left,id);
		
	}
	else if(id>root->masach){
		return search(root->right,id);
	}
}

node *deletesach(node *root,int id){
	if(root == NULL) return NULL;
	else if(id < root->masach){
		root->left = deletesach(root->left,id);
			}
	else if(id > root->masach){
		root->right = deletesach(root->right,id);
			}
	else{
		
		if(root->right == NULL && root->left == NULL){
			free(root);
			return NULL;
		}
		else if(root->right == NULL){
			node *tmp = root->left;
			free(root);
			return tmp;
		}
		else if(root->left == NULL){
			node *tmp = root->right;
			free(root);
			return tmp;
		}
		else{
			node *tmp = root->right ;
			while(tmp->left != NULL)
			tmp = tmp->left;
			
			root->masach = tmp->masach;
			strcpy(root->tensach, tmp->tensach);
			 deletesach(root->right,root->masach);
		}
	}
	return root;
}
int findmax(node* root){
	if(root == NULL) return -1;
	while(root->right != NULL)
	root = root->right;
	return root->masach;
	
}
int findmin(node* root){
	if(root == NULL) return -1;
	while(root->left != NULL)
	root = root->left;
	return root->masach;
	
}

int main() {
	node* root = NULL;
	int lc, id;
	char name[100];

	do {
		printf("\n----------- MENU----- -----\n");
		printf("1. Them sach\n");
		printf("2. In danh sach  (LNR)\n");
		printf("3. Tim kiem sach theo ma\n");
		printf("4. xoa sach theo ma\n");
		printf("5. tim sach co ma lon nhat, nho nhat\n");
		printf("0. thoat\n");
		printf("nhap lua chon cua ban: ");
		scanf("%d", &lc);
		getchar(); // tránh trôi dòng sau scanf

		switch (lc) {
			case 1:
				printf("nhap ma sach: ");
				scanf("%d", &id);
				getchar(); // b? ký t? Enter

				printf("nhap ten sach: ");
				fgets(name, sizeof(name), stdin);
				name[strcspn(name, "\n")] = '\0'; // xoá d?u newline

				root = insert(root, id, name);
				break;

			case 2:
				if (root == NULL) printf("empty!\n");
				else {
					printf("list books (LNR):\n");
					inorder(root);
				}
				break;

			case 3:{
			
				printf("nhap ma sach can tim ");
				scanf("%d", &id);
				node* found = search(root, id);
				if (found == NULL) printf("khong tim thay sach!\n");
				else printf("Tim thay: %d - %s\n", found->masach, found->tensach);
				break;
}
			case 4:{
				
				printf("nhap ma sach can xoa");
				scanf("%d", &id);
				root = deletesach(root, id);
				printf("da xoa(neu ton tai)!\n");
				break;
}
			case 5:
				if (root == NULL) {
					printf("empty!\n");
				} else {
					printf("ma sach nho nhat:%d\n", findmin(root));
					printf("ma sach lon nhat:%d\n", findmax(root));
				} 
				break;

			case 0:
				printf("tam biet!\n");
				break;

			default:
				printf("lua chon khong hop le!\n");
		}
	} while (lc != 0);

	return 0;
}

