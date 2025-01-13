#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

// ������ջ�ڵ�ṹ
typedef struct Node {
    int data;           // �洢����
    struct Node* next;  // ָ����һ���ڵ�
} Node;

// ������ջ�ṹ
typedef struct {
    Node* top;  // ջ��ָ��
} LinkStack;

// ��ʼ����ջ
void initStack(LinkStack* stack) {
    stack->top = NULL;  // ջ��ָ���ʼ��Ϊ NULL����ʾ��ջ
}

// �ж���ջ�Ƿ�Ϊ��
int isEmpty(LinkStack* stack) {
    return stack->top == NULL;
}

// ��ջ����
int push(LinkStack* stack, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("�ڴ����ʧ��\n");
        return 0;
    }
    newNode->data = value;
    newNode->next = stack->top;
    stack->top = newNode;
    return 1;
}

// ��ջ����
int pop(LinkStack* stack, int* value) {
    if (isEmpty(stack)) {
        printf("ջΪ�գ��޷���ջ\n");
        return 0;
    }
    Node* temp = stack->top;
    *value = temp->data;
    stack->top = temp->next;
    free(temp);
    return 1;
}

// ��ѯջ��Ԫ��
int top(LinkStack* stack, int* value) {
    if (isEmpty(stack)) {
        printf("ջΪ�գ��޷���ѯջ��Ԫ��\n");
        return 0;
    }
    *value = stack->top->data;
    return 1;
}

// �޸�ջ��Ԫ��
int updateTop(LinkStack* stack, int value) {
    if (isEmpty(stack)) {
        printf("ջΪ�գ��޷��޸�ջ��Ԫ��\n");
        return 0;
    }
    stack->top->data = value;
    return 1;
}

// ��ӡ��ջ�е�����Ԫ��
void printStack(LinkStack* stack) {
    if (isEmpty(stack)) {
        printf("ջΪ��\n");
        return;
    }
    Node* current = stack->top;
    printf("��ջ�е�Ԫ�ش�ջ����ջ������Ϊ��\n");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    LinkStack stack;
    initStack(&stack);

    // ������ջ����
    push(&stack, 1);
    push(&stack, 2);
    push(&stack, 3);

    // ��ӡ��ջ
    printStack(&stack);

    // ��ѯջ��Ԫ��
    int topValue;
    if (top(&stack, &topValue)) {
        printf("ջ��Ԫ��Ϊ: %d\n", topValue);
    }

    // �޸�ջ��Ԫ��
    updateTop(&stack, 4);
    printStack(&stack);

    // ��ջ����
    int poppedValue;
    if (pop(&stack, &poppedValue)) {
        printf("��ջԪ��Ϊ: %d\n", poppedValue);
    }

    // �ٴδ�ӡ��ջ
    printStack(&stack);

    // ������ջ
    while (!isEmpty(&stack)) {
        int temp;
        pop(&stack, &temp);
    }

    return 0;
}