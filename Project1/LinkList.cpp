#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

#define ElementType int

typedef struct LNode {
    ElementType data;
    struct LNode* next;
} LNode, * LinkList;

// 初始化链表
bool InitLinkList(LinkList& L) {
    L = (LNode*)malloc(sizeof(LNode));
    if (!L)
        return false;
    L->next = NULL;
    return true;
}

// 在第 i 个位置插入元素 e
bool ListInsert(LinkList& L, int i, ElementType e) {
    LNode* p = L;
    int j = 0;
    while (p && j < i - 1) {
        p = p->next;
        j++;
    }
    if (!p || j > i - 1)
        return false;
    LNode* s = (LNode*)malloc(sizeof(LNode));
    if (!s)
        return false;
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}

// 删除第 i 个元素，并通过指针 e 返回删除的元素值
bool ListDelete(LinkList& L, int i, ElementType* e) {
    LNode* p = L;
    int j = 0;
    while (p->next && j < i - 1) {
        p = p->next;
        j++;
    }
    if (!(p->next) || j > i - 1)
        return false;
    LNode* q = p->next;
    *e = q->data;
    p->next = q->next;
    free(q);
    return true;
}

// 更改第 i 个元素的值为 e
bool ListModify(LinkList L, int i, ElementType e) {
    LNode* p = L;
    int j = 0;
    while (p && j < i) {
        p = p->next;
        j++;
    }
    if (!p || j > i)
        return false;
    p->data = e;
    return true;
}

// 查询第 i 个元素的值
bool ListGet(LinkList L, int i, ElementType* e) {
    LNode* p = L;
    int j = 0;
    while (p && j < i) {
        p = p->next;
        j++;
    }
    if (!p || j > i)
        return false;
    *e = p->data;
    return true;
}

// 打印链表
void PrintLinkList(LinkList L) {
    LNode* p = L->next;
    while (p) {
        printf("%d -> ", p->data);
        p = p->next;
    }
    printf("NULL\n");
}

int main() {
    LinkList L;
    ElementType e;

    if (InitLinkList(L)) {
        printf("链表初始化成功\n");
    }
    else {
        printf("链表初始化失败\n");
        return -1;
    }

    // 插入元素
    ListInsert(L, 1, 10);
    ListInsert(L, 2, 20);
    ListInsert(L, 3, 30);
    ListInsert(L, 4, 40);

    printf("插入后的链表: ");
    PrintLinkList(L);

    // 更改元素
    if (ListModify(L, 2, 25)) {
        printf("更改第 2 个元素成功\n");
    }
    else {
        printf("更改第 2 个元素失败\n");
    }

    printf("更改后的链表: ");
    PrintLinkList(L);

    // 查询元素
    if (ListGet(L, 2, &e)) {
        printf("第 2 个元素的值为: %d\n", e);
    }
    else {
        printf("查询第 2 个元素失败\n");
    }

    // 删除元素
    if (ListDelete(L, 3, &e)) {
        printf("删除第 3 个元素成功，值为: %d\n", e);
    }
    else {
        printf("删除第 3 个元素失败\n");
    }

    printf("删除后的链表: ");
    PrintLinkList(L);

    return 0;
}