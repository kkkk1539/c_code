#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 10
#define ElementType char
#define InitSize 10//Ĭ�ϳ���
//��̬����˳���
//typedef struct {
//	ElementType data[MAX_SIZE];
//	int length;
//}SqList;
//
//void InitList(SqList &L) {
//	L.length = 0;
//}

//��̬����˳���
typedef struct {
	ElementType* data;//ָʾ��̬���������ָ��
	int MaxSize;//��󳤶�
	int length;
}SqList;

void InitList(SqList &L) {
	L.MaxSize = InitSize;
	L.data = (ElementType*)malloc(sizeof(ElementType) * L.MaxSize);
	L.length = 0;
	
}

void IncreaseSize(SqList& L,int len) {
	ElementType* p = L.data;//��¼ԭ���ݵ��׵�ַ
	L.MaxSize =L.MaxSize + len;//����˳���ĳ���
	L.data = (ElementType*)malloc(sizeof(ElementType) * L.MaxSize);//��������������׵�ַ
	if (L.data) {//����ڴ����ɹ�
		for (int i = 0;i < L.length;i++) {
			L.data[i] = p[i];//��ԭ���ݸ���
		}
	}
	free(p);
}

bool ListInsert(SqList& L, int i, ElementType e) {
	if (i<1 || i>(L.length+1) || L.length == L.MaxSize) 
		return false;
	for (int j = L.length;j >= i;j--) {
		L.data[j] = L.data[j - 1];
	}
	L.data[i - 1] = e;
	L.length++;
	return true;
}

bool ListDelete(SqList& L, int i,ElementType& e) {
	if (i<1 || i>L.length) 
		return false;
	e = L.data[i - 1];
	for (int j = i;j <= L.length - 1;j++) {
		L.data[j - 1] = L.data[j];
	}
	L.length--;
	return true;
}

ElementType GetElem(SqList& L, int i) {//��λ�����
	if (i<1 || i>L.length) 
		return NULL;
	return L.data[i - 1];
}

int LocateElem(SqList& L, ElementType e) {
	for (int i = 0;i < L.length;i++) {
		if (e == L.data[i])
			return i + 1;
	}
	return -1;
}

int main() {
	SqList L1;
	InitList(L1);
	ElementType data1 = 'A';
	//ElementType data2 = 'B';
	ListInsert(L1, 1, data1);
	//ListInsert(L1, 2, data2);
	ElementType E =' ';
	if (ListDelete(L1,1, E))
		printf("%c\n", E);
	return 0;
}