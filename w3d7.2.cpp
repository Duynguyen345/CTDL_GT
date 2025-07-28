#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char tenmon[50];
    char ngaythi[20];
    struct node* prev;
    struct node* next;
} ;
node* makenode(char ten[], char ngay[]) {
    node* newnode = (node*)malloc(sizeof(node));
    strcpy(newnode->tenmon, ten);
    strcpy(newnode->ngaythi, ngay);
    newnode->prev = NULL;
    newnode->next = NULL;
    return newnode;
}
void inDSLK_LichThi(node **head) {
    node* tmp = *head;
    printf("Danh sách l?ch thi:\n");
    while (tmp != NULL) {
        printf("- %s | Ngày thi: %s\n", tmp->tenmon, tmp->ngaythi);
        tmp = tmp->next;
    }
}

void pushfront(node **head,char tenmon[],char ngaythi[]){
	node *newnode =makenode(tenmon,ngaythi);
	newnode->next = *head;
	if((*head) != NULL)
	(*head)->prev = newnode;
	*head = newnode;
}

void pushback(node **head,char tenmon[],char ngaythi[]){
	node *newnode = makenode(tenmon,ngaythi);
	if(*head == NULL){
		*head = newnode;
		return;
	}
	node *tmp = *head;
	while(tmp != NULL){
		tmp = tmp->next;
	}
	tmp->next = newnode;
	newnode->prev = tmp;
	
}

void popnode(node **head,char tencantim[]){
	node *curr = *head;
	while(curr!= NULL && strcmp(curr->tenmon,tencantim)!=0){
		curr = curr->next;
		
	}
	if(curr == NULL){
		printf("khong tim thay %s\n",tencantim);
		return;
	}
	
	if(curr->prev == NULL){
		*head = curr->next;
		if(*head != NULL){
			(*head)->prev = NULL;
		}
	}
	else{
		curr->prev->next = curr->next;
		if(curr->next !=NULL){
			curr->next->prev = curr->prev;
		}
	}
	free(curr);
	printf("da xoa thanh cong:%s\n",tencantim);
}
void duyetXuoi(node* head) {
    printf("\n-- Lich thi (xuôi) --\n");
    node* tmp = head;
    while (tmp != NULL) {
        printf("%s - %s\n", tmp->tenmon, tmp->ngaythi);
        tmp = tmp->next;
    }
}

void duyetNguoc(node* head) {
    printf("\n-- Lich thi (nguoc) --\n");
    if (head == NULL) return;
    node* tmp = head;
    while (tmp->next != NULL)
        tmp = tmp->next; // Ði d?n node cu?i
    while (tmp != NULL) {
        printf("%s - %s\n", tmp->tenmon, tmp->ngaythi);
        tmp = tmp->prev;
    }
}
int main() {
    node* head = NULL;
    int choice;
    char ten[50], ngay[20];

    do {
        printf("\n==== MENU L?CH THI ====\n");
        printf("1. Thêm lich thi vào dau\n");
        printf("2. Thêm lich thi vào cuoi\n");
        printf("3. Xoá lich thi theo tên\n");
        printf("4. Duyet xuôi\n");
        printf("5. Duyet nguoc\n");
        printf("0. Thoát\n");
        printf("Chon: ");
        scanf("%d", &choice);
        getchar(); 

        switch (choice) {
            case 1:
                printf("Tên môn: ");
                fgets(ten, sizeof(ten), stdin);
                ten[strcspn(ten, "\n")] = '\0';
                printf("Ngày thi: ");
                fgets(ngay, sizeof(ngay), stdin);
                ngay[strcspn(ngay, "\n")] = '\0';
                pushfront(&head, ten, ngay);
                break;
            case 2:
                printf("Tên môn: ");
                fgets(ten, sizeof(ten), stdin);
                ten[strcspn(ten, "\n")] = '\0';
                printf("Ngày thi: ");
                fgets(ngay, sizeof(ngay), stdin);
                ngay[strcspn(ngay, "\n")] = '\0';
                pushback(&head, ten, ngay);
                break;
            case 3:
                printf("Nh?p tên môn c?n xoá: ");
                fgets(ten, sizeof(ten), stdin);
                ten[strcspn(ten, "\n")] = '\0';
                popnode(&head, ten);
                break;
            case 4:
                duyetXuoi(head);
                break;
            case 5:
                duyetNguoc(head);
                break;
            case 0:
                printf("==> Thoát.\n");
                break;
            default:
                printf("L?a ch?n không h?p l?!\n");
        }
    } while (choice != 0);

 
    node* tmp;
    while (head != NULL) {
        tmp = head;
        head = head->next;
        free(tmp);
    }

    return 0;
}
