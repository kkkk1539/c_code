//#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//#include<stdlib.h>
//
//void bubble_sort(int arr[], int sz) {
//	for (int i = 0;i < sz;i++) {
//		int flag = 1;
//		for (int j = 0;j < 10 - i - 1;j++) {
//			if (arr[j] > arr[j + 1]) {
//				flag = 0;
//				int temp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = temp;
//			}
//		}
//		if (flag == 1) {
//			break;
//		}
//	}
//}
//
//
//int int_cmp(const void* p1, const void* p2) {
//	return (*(int*)p1 - *(int*)p2);
//}
//
//
//
//
//
//
//
//
//
//
//
//
//int main() {
//	int arr[] = { 1,3,5,7,9,2,4,6,8 };
//	qsort(arr, sizeof(arr) / sizeof(arr[0]), sizeof(int), int_cmp);
//
//	for (int i = 0;i < sizeof(arr) / sizeof(arr[0]);i++) {
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//	return 0;
//}
