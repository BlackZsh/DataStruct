#include <stdio.h>
#define MAXSIZE 100
//����
typedef struct {
int elem[MAXSIZE];
int last;
}SeqList, *LinkList;



void main() {
void dispalyList(SeqList List); //��ӡelem[]
void innit (LinkList p ); //��ʼ��elem[]
int InsList(LinkList p, int i , int e );//����
int DelList (LinkList p,int i,int *e);//ɾ��
int Locate (SeqList L, int e);//��ѯ
SeqList seqList;
int i,e;
LinkList p = &seqList;
p->last = 4; //����5������

innit(p);
dispalyList(seqList);

//����
printf("������Ҫ���������:");
scanf("%d",&e);
printf("������Ҫ�����λ��:");
scanf("%d",&i);

if(InsList( p,i,e )) {
	printf("����ɹ�");
	dispalyList(seqList);
}else {

	printf("����ʧ��");
}

//ɾ��
printf("������Ҫɾ����λ�ã�");
scanf("%d",&i);
if (DelList ( p,i,&e)){
	printf("ɾ���ɹ� ɾ��Ԫ��Ϊ:%d\n",e);
	dispalyList(seqList);
}else {
	printf("ɾ��ʧ��");

}

//��ѯ
printf("������Ҫ��ѯ�����ݣ�");
scanf("%d",&e);
i = Locate ( seqList,e);
if(i!= -1) {
	printf("��ѯ�ɹ� %dλ��Ϊ%d\n",e,i);

}else {
	printf("û���ҵ�");
}


}







void innit (LinkList p )  {
int i;
printf("��ʼ������\n");
for (i = 0; i <= p->last ; i++) {
printf("�������%d��Ԫ��",i+1);
scanf("%d",&p->elem[i]);
}
}


//���elem[]
void dispalyList(SeqList List){
int i ;
printf("Ԫ��Ϊ��\n");

for (i = 0; i <= List.last; i++) {
	//���elem[]
	printf("%d ",List.elem[i]);

}
printf("\n");
}

//����
int InsList(LinkList p, int i , int e ) {
	int k;
	if(i < 1 || i > p->last + 2) {
	 printf("����λ�ò��Ϸ�");
		return 0;
	}
	if (p->last >= MAXSIZE - 1) {
	 printf("�����ˣ��޷�����");
	 return 0;
	}
	for (k = p->last; k >= i-1 ; k--) {
		p->elem[k+1] = p->elem[k];
	}
	p->elem[i-1] = e;
	p->last++;
	return 1;

}

//ɾ��
int DelList (LinkList p,int i,int *e) {
int k; 
if(i<1 || (i > p->last)) {
	printf("ɾ��λ�ò��Ϸ�");
	return 0;
}
*e = p->elem[i -1];
for (k = i; k<= p->last ; k++) {
	p->elem[k-1] = p->elem[k];
	
} 
p->last--;
return 1;


}

int Locate (SeqList L, int e) {
int i=0 ;
while ((i<=L.last) && (L.elem[i]!=e)) 
i++;
if(i <= L.last){
	return (i+1);
}else {
	return (-1);

}

}