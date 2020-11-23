#include<stdio.h>
#include<stdlib.h>


#define NULL 0

typedef struct Node {

	int data;
	struct Node * next;

}Node,*LinkList;
//ȫ�ֱ���
LinkList h;
LinkList *p = &h;


void main () {
	//��������
void InitList (LinkList *L);//����ͷ�ڵ�
void CreateFromHead (LinkList L);//��ʼ������---ͷ���뷨
void VreateFromTail(LinkList L);//��ʼ������---β�����뷨
void Show(LinkList h); //��ӡ����
int ListLength (LinkList L); // ��ȡ������

LinkList Get (LinkList L , int i); //��λ����
LinkList Locate(LinkList L, int e);//��ֵ����
int  InsList (LinkList L,int i, int e); //����Ԫ��
int DelList (LinkList L ,int i,int *e );//ɾ��Ԫ��
void RemoveDuplicates(LinkList L); //ɾ������������ظ�Ԫ��

	/* 
	�˵�  
	 */
 
void Search(); //��ѯ
void Delect (); //ɾ��
void Insert(); //����
void innit (LinkList *L ) ;// ��ʼ��
int flag = 1,select;

while (flag !=0) {
printf ("���� 0�˳� 1��ʼ��  2���� 3ɾ�� 4��ѯ 5��ӡ���� 6��ȡ������ 7ɾ������������ظ�Ԫ��\n:");
scanf("%d",&select);
switch (select) {
case 0 : flag = 0; break;
case 1 : innit (p);break;
case 2 : Insert(); break;
case 3 : Delect(); break;
case 4 : Search(); break;
case 5 : Show(h);break;
case 6 :printf("����ǰ����Ϊ:%d \n", ListLength(h));break;
case 7 :RemoveDuplicates(h); break;
default : printf("�������� ����������"); 
}
}
}

//�˵�--��Ѱ

void Search() {
LinkList result;
int flag,e,select; 
flag =1;
while (flag) {
//��ѯ
printf("���� 1��λ���ң� 2 ��ֵ����:");
scanf("%d",&select);


if (select == 1){
printf("������Ҫ��ѯ��λ�ã�");
scanf("%d",&e);
result = Get (h,e);
}else {
printf("������Ҫ��ѯ�����ݣ�");
scanf("%d",&e);
result = Locate(h,e);
}



if(result != NULL) {
	printf("��ѯ�ɹ�: %d\n",result->data);

}else {
	printf("û���ҵ�");
}

printf("������ѯ������ 1  �˳�����0:");
scanf("%d",&flag);

}
}

//�˵�---ɾ��
void Delect () {
int flag = 1,i,e; 
while (flag) {

printf("������Ҫɾ����λ�ã�");
scanf("%d",&i);
if (DelList (h,i,&e)){
	printf("ɾ���ɹ� ");
	printf("ɾ����Ԫ�ص�ֵΪ%d\n",e);
	Show(h);
}else {
	printf("ɾ��ʧ��");

}
printf("����ɾ�������� 1  �˳�����0:");
scanf("%d",&flag);


}
}



//�˵�---����
void Insert() {
int flag=1,e,i;
while (flag) {
printf("������Ҫ���������:");
scanf("%d",&e);
printf("������Ҫ�����λ��:");
scanf("%d",&i);

if(InsList( h,i,e )) {
	printf("����ɹ�");
	Show(h);
}else {

	printf("����ʧ��");
}

printf("�������������� 1  �˳�����0:");
scanf("%d",&flag);


} 

}




//�˵� -- ��ʼ������
void innit (LinkList *L )  {
int select;
InitList(L) ; //��ʼ��ͷ���
printf("������0�˳� 1ͷ�巨 2β�巨:");
scanf("%d",&select);
switch (select) {
	case 1: CreateFromHead (h); break;
	case 2: VreateFromTail(h); break;
	default : printf("���벻�Ϸ� �˳���ʼ��");break;

}
Show(h);
}





//ɾ��
int DelList (LinkList L ,int i,int *e ) {
LinkList pre,r;
int k = 0;
pre = L;

while ((pre->next !=NULL) && (k < i-1)) {
	pre = pre->next;
	k++;
}
if(pre->next == NULL) {
	printf("ɾ����λ�ò�����");
	return 0;
}

r = pre->next;
*e = r->data;//��¼ɾ����ֵ
pre->next = r->next;
free(r);
return 1;

}

//����
int  InsList (LinkList L,int i, int e) {
 LinkList pre ,s ;
 int k = 0 ;
 if(i <= 0) return 0;
 pre = L ;
 while ((pre!=NULL) && (k < i-1)) {
	pre = pre->next;
	k++;
 }
 if(pre == NULL) {
	printf("����λ�ò��Ϸ�");
	return 0;
 }
 s = (LinkList) malloc(sizeof(Node));
 s->data = e ;
 s->next = pre->next;
 pre->next = s;
 return 1 ;
}

//��ȡ������ 
int ListLength (LinkList L) {
	LinkList p;
	int i=0;
	p = L->next;
	
	while (p != NULL){
		p = p->next;
		i++;
	}
return i;

}

/*  
	��ѯ

*/
//��ֵ����
LinkList Locate(LinkList L, int e) {
LinkList p;
int i = 1;
p = L->next;

while (p != NULL && (p->data != e)) {
	p = p->next;
	i++;
} 
if(p != NULL){
	printf("Ѱ�ҵ�%d��λ��%d",e,i);
	return p;
}else{
	printf("δ�ҵ�");
	return NULL;
}
}

//��λ����
LinkList Get (LinkList L , int i) {
int j; 
LinkList p;
if(i <= 0 ){return NULL;}
p=L;
j=0;
while ((p->next!=NULL) && (j<i)) {
	p = p->next;
	j++;

}
if( i == j) {
	return p;
}else return NULL;

}

/*
	��ʼ��
*/
	//ͷ�巨

void CreateFromHead (LinkList L) {
Node *s;
int data;
int n,i=0;
printf("������Ҫ�������ݵĸ���");
scanf("%d",&n);
while (i<n) {
printf("�������%d������:",i+1);
scanf("%d",&data);
s = (Node *) malloc(sizeof(Node));//�����½ڵ�
s->data = data;
s->next = L->next;
L->next = s;
i++;
}
}
	//β�巨
void VreateFromTail(LinkList L) {
LinkList r,s;
int d;
int n,i=1;
printf("������Ҫ�������ݵĸ���");
scanf("%d",&n);
r = L;
while (i <= n) {
printf("�������%d������:",i);
scanf("%d",&d);
s = (LinkList) malloc(sizeof(Node));//�����½ڵ�
s->data = d;
r->next = s;
r = s ;
if(n == i) {
//����next��ΪNULL
	r->next = NULL;	
} 
i++;
}

}

//��ʼ��ͷ�ڵ�
void InitList (LinkList *L) {

	*L = (LinkList) malloc(sizeof(Node));//����ͷ�ڵ�
	(*L)->next = NULL;
	printf("ͷ�ڵ㽨���ɹ�\n");

}


//��ӡ����
void Show(LinkList h) {
	printf("\n");
	printf("����Ԫ��Ϊ:");
	while (h->next != NULL) {
		printf("%d ",h->next->data);
		h = h->next;
	}
	printf("\n");	

}

//ȥ��
void RemoveDuplicates(LinkList L) {
LinkList pre,p,temp;
pre = L->next;
p = pre->next;

while(p != NULL) {
	if(pre->data == p->data){
		temp = p;
		p = p->next;
		free(temp);
	}else{
		pre->next = p;
		pre = p;
		p = p->next;

	}
}

pre->next = NULL;//���Ԫ��nextֵΪNULL
}
