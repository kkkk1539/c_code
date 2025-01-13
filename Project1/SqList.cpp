#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 10
#define ElementType char
#define InitSize 10//默认长度
//静态创建顺序表
//typedef struct {
//	ElementType data[MAX_SIZE];
//	int length;
//}SqList;
//
//void InitList(SqList &L) {
//	L.length = 0;
//}

//动态创建顺序表
typedef struct {
	ElementType* data;//指示动态分配数组的指针
	int MaxSize;//最大长度
	int length;
}SqList;

void InitList(SqList &L) {
	L.MaxSize = InitSize;
	L.data = (ElementType*)malloc(sizeof(ElementType) * L.MaxSize);
	L.length = 0;
	
}

void IncreaseSize(SqList& L,int len) {
	ElementType* p = L.data;//记录原数据的首地址
	L.MaxSize =L.MaxSize + len;//增加顺序表的长度
	L.data = (ElementType*)malloc(sizeof(ElementType) * L.MaxSize);//新增长度数组的首地址
	if (L.data) {//如果内存分配成功
		for (int i = 0;i < L.length;i++) {
			L.data[i] = p[i];//将原数据复制
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

ElementType GetElem(SqList& L, int i) {//按位序查找
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