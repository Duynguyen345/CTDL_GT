#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char tenHS[50];
    char tenMon[50];
    struct node* next;
} node;

node *makenode(char tenHS[],char tenMon[]){
	node *newnode = (node*)malloc(sizeof(node));
	strcpy(newnode->tenHS,tenHS);
	strcpy(newnode->tenMon,tenMon);
	newnode->next = NULL;
	return newnode;
}

void pushback(node **head,char tenHS[],char tenMon[]){
	node *newnode = makenode(tenHS,tenMon);
	if(*head == NULL){
		*head = newnode ;
		newnode->next = *head;
		return;
	}
	node *tmp = *head;
	while(tmp->next != *head){
		tmp = tmp->next;
	}
	tmp->next = newnode;
	newnode->next = *head;
}

void pop(node **head,char tencanxoa[]){
	if(*head == NULL) return;
	node *curr = *head;
	node *prev = NULL;
	if(strcmp(curr->tenHS,tencanxoa) == 0){
		if(curr->next == *head){
			free(curr);
			(*head)->next = NULL;
			return;
		}
		node *last = *head;
		while(last->next != *head){
			last = last->next;
			
		}
		last->next = curr->next;
		*head = curr->next;
		free(curr);
		return;
	}
	prev = curr;
	curr= curr->next;
	while(curr != *head && strcmp(curr->tenHS,tencanxoa) != 0){
		prev = curr;
		curr= curr->next;
		
	}
	if(curr == *head){
		printf("khong tim thay hoc sinh:%s\n",tencanxoa);
		return;
		}
	prev->next = curr->next;
	free(curr);
	}
void inDanhSach(node* head) {
    if (head == NULL) {
        printf("Danh sách rong.\n");
        return;
    }

    node* tmp = head;
    printf("Danh sach hoc sinh hoc lai:\n");
    do {
        printf("- %s hoc lai mon %s\n", tmp->tenHS, tmp->tenMon);
        tmp = tmp->next;
    } while (tmp != head);
}
int main() {
    node* head = NULL;
    int choice;
    char tenHS[50], tenMon[50];

    do {
        printf("\n==== MENU HOC LAI ====\n");
        printf("1. Them hoc sinh hoc lai\n");
        printf("2. Xoa hoc sinh theo ten\n");
        printf("3. In danh sach hoc sinh hoc lai\n");
        printf("0. Thoat\n");
        printf("Chon: ");
        scanf("%d", &choice);
        getchar();  

        switch (choice) {
            case 1:
                printf("Ten hoc sinh: ");
                fgets(tenHS, sizeof(tenHS), stdin);
                tenHS[strcspn(tenHS, "\n")] = '\0';
                printf("Ten mon hoc: ");
                fgets(tenMon, sizeof(tenMon), stdin);
                tenMon[strcspn(tenMon, "\n")] = '\0';
                pushback(&head, tenHS, tenMon);
                break;
            case 2:
                printf("Nhap ten hoc sinh can xoa: ");
                fgets(tenHS, sizeof(tenHS), stdin);
                tenHS[strcspn(tenHS, "\n")] = '\0';
                pop(&head, tenHS);
                break;
            case 3:
                inDanhSach(head);
                break;
            case 0:
                printf("==> Thoát.\n");
                break;
            default:
                printf("Lua chon khong hop l!\n");
        }
    } while (choice != 0);

    if (head != NULL) {
        node *curr = head->next;
        while (curr != head) {
            node* tmp = curr;
            curr = curr->next;
            free(tmp);
        }
        free(head);
    }

    return 0;
}
