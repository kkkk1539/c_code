#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

#define MAX_SIZE 100


typedef struct {
	int data[MAX_SIZE];
	int top;
}SqStack;


void initStack(SqStack* S) {
	S->top = -1;
}

int isEmpty(SqStack* S) {
	return S->top == -1;
}

int isFull(SqStack* S) {
	return S->top == MAX_SIZE - 1;
}

void push(SqStack* S, int e) {
	if (!isFull(S)) {
		S->data[++S->top] = e;
	}
	else
		printf("ջ�������޷���ջ\n");
}

int pop(SqStack* S, int* e) {
	if (!isEmpty(S)) {
		return *e = S->data[S->top--];
	}
	else {
		printf("ջ�ѿգ��޷���ջ\n");
		return -1;
	}
		

}

void updateTop(SqStack* S, int e) {
	if (!isEmpty(S))
		S->data[S->top] = e;
	else
		printf("ջ�ѿգ��޷�����ջ��Ԫ��\n");
}


int top(SqStack* S) {
	if (!isEmpty(S))
		return S->data[S->top];
	else
		printf("ջ�ѿգ��޷���ѯջ��Ԫ��\n");
}

void print(SqStack* S) {
	if (!isEmpty(S)) {
		printf("ջ�е�Ԫ�ش�ջ�׵�ջ������Ϊ��\n");
		for (int i=0;i<=S->top;i++) {
			printf("%d ",S->data[i]);
		}
		printf("\n");
	}
	else
		printf("ջ�ѿգ��޷���ӡջ��Ԫ��\n");
}

int main() {
	SqStack stack;
	initStack(&stack);

	// ������ջ����
	push(&stack, 1);
	push(&stack, 2);
	push(&stack, 3);

	print(&stack);

	printf("ջ��Ԫ��Ϊ: %d\n",top(&stack));
	

	// �޸�ջ��Ԫ��
	updateTop(&stack, 4);
	print(&stack);

	// ��ջ����
	int poppedValue=0;
	
	printf("��ջԪ��Ϊ: %d\n", pop(&stack,&poppedValue));
	

	// �ٴδ�ӡջ
	print(&stack);

	return 0;
}