#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

#define ElementType int

typedef struct LNode {
    ElementType data;
    struct LNode* next;
} LNode, * LinkList;

// ��ʼ������
bool InitLinkList(LinkList& L) {
    L = (LNode*)malloc(sizeof(LNode));
    if (!L)
        return false;
    L->next = NULL;
    return true;
}

// �ڵ� i ��λ�ò���Ԫ�� e
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

// ɾ���� i ��Ԫ�أ���ͨ��ָ�� e ����ɾ����Ԫ��ֵ
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

// ���ĵ� i ��Ԫ�ص�ֵΪ e
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

// ��ѯ�� i ��Ԫ�ص�ֵ
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

// ��ӡ����
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
        printf("�����ʼ���ɹ�\n");
    }
    else {
        printf("�����ʼ��ʧ��\n");
        return -1;
    }

    // ����Ԫ��
    ListInsert(L, 1, 10);
    ListInsert(L, 2, 20);
    ListInsert(L, 3, 30);
    ListInsert(L, 4, 40);

    printf("����������: ");
    PrintLinkList(L);

    // ����Ԫ��
    if (ListModify(L, 2, 25)) {
        printf("���ĵ� 2 ��Ԫ�سɹ�\n");
    }
    else {
        printf("���ĵ� 2 ��Ԫ��ʧ��\n");
    }

    printf("���ĺ������: ");
    PrintLinkList(L);

    // ��ѯԪ��
    if (ListGet(L, 2, &e)) {
        printf("�� 2 ��Ԫ�ص�ֵΪ: %d\n", e);
    }
    else {
        printf("��ѯ�� 2 ��Ԫ��ʧ��\n");
    }

    // ɾ��Ԫ��
    if (ListDelete(L, 3, &e)) {
        printf("ɾ���� 3 ��Ԫ�سɹ���ֵΪ: %d\n", e);
    }
    else {
        printf("ɾ���� 3 ��Ԫ��ʧ��\n");
    }

    printf("ɾ���������: ");
    PrintLinkList(L);

    return 0;
}