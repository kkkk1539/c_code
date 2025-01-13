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
		printf("栈已满，无法入栈\n");
}

int pop(SqStack* S, int* e) {
	if (!isEmpty(S)) {
		return *e = S->data[S->top--];
	}
	else {
		printf("栈已空，无法出栈\n");
		return -1;
	}
		

}

void updateTop(SqStack* S, int e) {
	if (!isEmpty(S))
		S->data[S->top] = e;
	else
		printf("栈已空，无法更改栈顶元素\n");
}


int top(SqStack* S) {
	if (!isEmpty(S))
		return S->data[S->top];
	else
		printf("栈已空，无法查询栈顶元素\n");
}

void print(SqStack* S) {
	if (!isEmpty(S)) {
		printf("栈中的元素从栈底到栈顶依次为：\n");
		for (int i=0;i<=S->top;i++) {
			printf("%d ",S->data[i]);
		}
		printf("\n");
	}
	else
		printf("栈已空，无法打印栈中元素\n");
}

int main() {
	SqStack stack;
	initStack(&stack);

	// 测试入栈操作
	push(&stack, 1);
	push(&stack, 2);
	push(&stack, 3);

	print(&stack);

	printf("栈顶元素为: %d\n",top(&stack));
	

	// 修改栈顶元素
	updateTop(&stack, 4);
	print(&stack);

	// 出栈操作
	int poppedValue=0;
	
	printf("出栈元素为: %d\n", pop(&stack,&poppedValue));
	

	// 再次打印栈
	print(&stack);

	return 0;
}