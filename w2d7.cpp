#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct SinhVien{
	char mssv[50];
	char ten[50];
	float diem;
}SinhVien;

typedef struct node{
	 SinhVien data;
	 struct node *next;
	
};

node *makenode(SinhVien sv){
	node *newnode = (node*)malloc(sizeof(node));
	
	newnode->data = sv;
	newnode->next = NULL;
	return newnode;
}

void pushfront(node **head,SinhVien sv){
	node *newnode = makenode(sv);
	newnode->next = *head;
	*head = newnode;
	
}
void pushback(node **head,SinhVien sv){
	node *newnode = makenode(sv);
	if(*head == NULL){
		*head = newnode;
		return;	
	}
	node *tmp = *head;
	while(tmp->next != NULL){
		tmp = tmp->next;
}
	tmp->next=newnode;

}
int size(node *head){
	int cnt = 0;
	while(head!=NULL){
		cnt++;
		head = head->next;
	}
	return cnt;
}

void pushmid(node **head,SinhVien sv,int k){
	int n = size(*head);
	if(k<1 || k>n+1) return;
	if(k==1){
		pushfront(head,sv); return;
	}
	node *tmp = *head;
	for(int i=1;i<=k-2;i++){
		tmp = tmp->next;
	}
	node *newnode = makenode(sv);
	newnode->next = tmp->next;
	tmp->next = newnode;
}

void popfront(node **head){
	if(*head == NULL) return;
	node *tmp = *head;
	(*head) = (*head)->next;
	free(tmp);
}

void popback(node **head){
	if(*head == NULL ) return ;
	node *tmp = *head;
	
	if(tmp->next == NULL){
		*head = NULL;
		free(tmp);
		return;
	}
	while(tmp->next->next != NULL) tmp = tmp->next;
	free(tmp->next);
	tmp->next = NULL;
}

void popmid(node **head,int k){
	int n = size(*head);
	if(k<1 || k>n) return;
	if(k==1){
		popfront(head);
		return;
	}
	else{
		node *tmp = *head;
		for(int i=0;i<=k-2;i++){
			tmp = tmp->next;
			
		}
		node *last = tmp->next;
		tmp->next = last->next;
		free(last);
	}
}

void duyet(node *head){
	int stt=1;
	while(head != NULL ){
		printf("thong tin sinh vien thu%d:\n",stt);
		printf("mssv:%s\n",head->data.mssv);
		printf("ten:%s\n",head->data.ten);
		printf("diem:%.2f\n",head->data.diem);
		printf("\n---------------------------\n");
		head = head->next;
	}
}

void search(node *head,char mssv[]){
	int found = 0;
	int pos = 1;
	while(head != NULL){
		if(strcmp(head->data.mssv,mssv) == 0){
			found = 1;
			printf("tim thay:%s-%s-%.2f o vi tri %d\n",head->data.ten,head->data.mssv,head->data.diem,pos);
		}
		pos++;
		head = head->next;
	}
	if(found == 0) printf("khong tim thay!\n");
}

void tong(node *head){
	float tong =0;
	int dem = 0;
	while(head != 0){
		tong += head->data.diem;
		dem++;
		head = head->next;
	}
	printf("tong cua %d nguoi la %.2f.\n",dem,tong);
}

void reverse(node **head){
	node *prev = NULL;
	node *curr = *head;
	node *next = NULL;
	while(curr != NULL){
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
		
	}
	*head = prev;
}

SinhVien nhapSV() {
    SinhVien sv;
    printf("Nhap ten: "); fflush(stdin); gets(sv.ten);
    printf("Nhap MSSV: "); gets(sv.mssv);
    printf("Nhap diem: "); scanf("%f", &sv.diem);
    return sv;
}

// Main
int main() {
    node *head = NULL;
    int chon, k;
    char mssv[15];

    do {
        printf("\n----- MENU -----\n");
        printf("1. Them dau\n");
        printf("2. Them cuoi\n");
        printf("3. them vao giua\n");
        printf("4. Xoa dau\n");
        printf("5. Xoa cuoi\n");
        printf("6. Xoa vi tri k\n");
        printf("7. Tim sinh vien theo MSSV\n");
        printf("8. Hien thi danh sach\n");
        printf("9. Thong ke tong diem & so SV\n");
        printf("10. Dao nguoc danh sach\n");
        printf("0. Thoat\n");
        printf("Chon: "); scanf("%d", &chon);
        getchar();

        switch (chon) {
            case 1:
                pushfront(&head, nhapSV());
                break;
            case 2:
                pushback(&head, nhapSV());
                break;
            case 3:
                printf("Nhap vi tri k: "); scanf("%d", &k);
                pushmid(&head, nhapSV(), k);
                break;
            case 4:
                popfront(&head);
                break;
            case 5:
                popback(&head);
                break;
            case 6:
                printf("Nhap vi tri k: "); scanf("%d", &k);
                popmid(&head, k);
                break;
            case 7:
                printf("Nhap MSSV can tim: "); fflush(stdin); gets(mssv);
                search(head, mssv);
                break;
            case 8:
                duyet(head);
                break;
            case 9:
                tong(head);
                break;
            case 10:
                reverse(&head);
                break;
            case 0:
                printf("Tam biet!\n");
                break;
            default:
                printf("Lua chon khong hop le!\n");
        }
    } while (chon != 0);

    return 0;
}
