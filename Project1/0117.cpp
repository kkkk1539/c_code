#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//typedef struct Stu {
//	int id;
//	char name[20];
//	int age;
//}stu;
//
//int cmp_int(const void* n1, const void* n2) {
//	return *(int*)n1 - *(int*)n2;
//}
//
//int cmp_char(const void* c1, const void* c2) {
//	return strcmp((char*)c1, (char*)c2);
//}
//
//int cmp_stu_age(const void* s_a1, const void* s_a2) {
//	return (*(stu*)s_a1).age - (*(stu*)s_a2).age;
//}
//
//int cmp_stu_name(const void* s_n1, const void* s_n2) {
//	return strcmp((*(stu*)s_n1).name, (*(stu*)s_n2).name);
//}
//
//int main() {
//	int arr[] = { 1,4,5,6,7,2,3,9,8 };
//	char str[] = "adgfxljDFGRH";
//	stu s[] = { {1,"hanmeimei",18},{2,"limingming",20},{3,"hanmingming",19} };
//	size_t sz = sizeof(arr) / sizeof(arr[0]);
//	qsort(arr, sz, sizeof(arr[0]),cmp_int);
//	for (size_t i = 0;i < sz;i++) {
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//	size_t len = strlen(str);
//	qsort(str, len, sizeof(char), cmp_char);
//	printf("%s\n", str);
//	size_t num = sizeof(s) / sizeof(s[0]);
//	qsort(s, num, sizeof(s[0]), cmp_stu_age);
//	for (size_t i = 0;i < num;i++) {
//		printf("%d %s %d\n", s[i].id, s[i].name, s[i].age);
//	}
//	printf("\n");
//	qsort(s, num, sizeof(s[0]), cmp_stu_name);
//	for (size_t i = 0;i < num;i++) {
//		printf("%d %s %d\n", s[i].id, s[i].name, s[i].age);
//	}
//}
//
//void bubble_sort(void* address, size_t num, size_t width, int (*cmp)(const void* p1, const void* p2)) {
//	for (size_t i = 0;i < num - 1;i++) {
//		for (size_t j = 0;j < num - i - 1;j++) {
//			char* p1 = (char*)address + j * width;
//			char* p2 = (char*)address + (j + 1) * width;
//			if (cmp(p1,p2)>0) {
//				for (size_t k = 0;k < width;k++) {
//					char tmp = p1[k];
//					p1[k] = p2[k];
//					p2[k] = tmp;
//				}
//			}
//		}
//	}
//}

//int main() {
//	int arr[] = { 1,9,2,4,7,3,8,6,5 };
//	size_t sz = sizeof(arr) / sizeof(arr[0]);
//	bubble_sort(arr, sz, sizeof(int), cmp_int);
//	for (size_t i = 0;i < sz;i++) {
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}
