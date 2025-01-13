#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

// 定义链栈节点结构
typedef struct Node {
    int data;           // 存储数据
    struct Node* next;  // 指向下一个节点
} Node;

// 定义链栈结构
typedef struct {
    Node* top;  // 栈顶指针
} LinkStack;

// 初始化链栈
void initStack(LinkStack* stack) {
    stack->top = NULL;  // 栈顶指针初始化为 NULL，表示空栈
}

// 判断链栈是否为空
int isEmpty(LinkStack* stack) {
    return stack->top == NULL;
}

// 入栈操作
int push(LinkStack* stack, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("内存分配失败\n");
        return 0;
    }
    newNode->data = value;
    newNode->next = stack->top;
    stack->top = newNode;
    return 1;
}

// 出栈操作
int pop(LinkStack* stack, int* value) {
    if (isEmpty(stack)) {
        printf("栈为空，无法出栈\n");
        return 0;
    }
    Node* temp = stack->top;
    *value = temp->data;
    stack->top = temp->next;
    free(temp);
    return 1;
}

// 查询栈顶元素
int top(LinkStack* stack, int* value) {
    if (isEmpty(stack)) {
        printf("栈为空，无法查询栈顶元素\n");
        return 0;
    }
    *value = stack->top->data;
    return 1;
}

// 修改栈顶元素
int updateTop(LinkStack* stack, int value) {
    if (isEmpty(stack)) {
        printf("栈为空，无法修改栈顶元素\n");
        return 0;
    }
    stack->top->data = value;
    return 1;
}

// 打印链栈中的所有元素
void printStack(LinkStack* stack) {
    if (isEmpty(stack)) {
        printf("栈为空\n");
        return;
    }
    Node* current = stack->top;
    printf("链栈中的元素从栈顶到栈底依次为：\n");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    LinkStack stack;
    initStack(&stack);

    // 测试入栈操作
    push(&stack, 1);
    push(&stack, 2);
    push(&stack, 3);

    // 打印链栈
    printStack(&stack);

    // 查询栈顶元素
    int topValue;
    if (top(&stack, &topValue)) {
        printf("栈顶元素为: %d\n", topValue);
    }

    // 修改栈顶元素
    updateTop(&stack, 4);
    printStack(&stack);

    // 出栈操作
    int poppedValue;
    if (pop(&stack, &poppedValue)) {
        printf("出栈元素为: %d\n", poppedValue);
    }

    // 再次打印链栈
    printStack(&stack);

    // 清理链栈
    while (!isEmpty(&stack)) {
        int temp;
        pop(&stack, &temp);
    }

    return 0;
}