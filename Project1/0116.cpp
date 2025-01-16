#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<string.h>
#include<assert.h>
//
//int main() {
//	int a = 0, b = 0, c = 0, d = 0, e = 0;
//	for (int a = 1;a <= 5;a++) {
//		for (int b = 1;b <= 5;b++) {
//			for (int c = 1;c <= 5;c++) {
//				for (int d = 1;d <= 5;d++) {
//					for (int e = 1;e <= 5;e++) {
//						if ((b == 2) + (a == 3)==1 &&
//							(b == 2) + (e == 4)==1 &&
//							(c == 1) + (d == 2)==1 &&
//							(c == 5) + (d == 3)==1 &&
//							(e == 4) + (a == 1)==1)
//							{
//							if(a*b*c*d*e==120)
//								printf("a=%d b=%d c=%d e=%d e=%d\n", a, b, c, d, e);
//						}
//					}
//				}
//			}
//		}
//	}
//	return 0;
//}

//int main() {
//	char killer =97;
//	for (killer = 97;killer <= 100;killer++) {
//		if ((killer != 97) + (killer == 99) + (killer == 100) + (killer != 100) == 3) {
//			printf("killer is %c", killer);
//		}
//	}
//	return 0;
//}
//#define row 10
//#define col 10
//int main() {
//	int arr[row][col];
//	for (int i = 0;i < row;i++) {
//		for (int j = 0;j <= i;j++) {
//			if (j == 0) {
//				arr[i][j] = 1;
//			}
//			else if (i == j) {
//				arr[i][j] = 1;
//			}
//			else {
//				arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
//			}
//		}
//	}
//
//	for (int i = 0;i < row;i++) {
//		for (int j = 0;j <= i;j++) {
//			printf("%d ", arr[i][j]);
//		}
//		printf("\n");
//	}
//	return 0;
//}
//

//
//int binary_search(int* arr, size_t sz, int n) {
//	int* left = arr;
//	int* right = arr + sz;
//	while (left < right) {
//		int* mid = left + (right - left) / 2;
//		if (n > *mid) {
//			left = mid + 1;
//		}
//		else if (n < *mid) {
//			right = mid - 1;
//		}
//		else {
//			return mid - arr;
//		}
//	}
//	return -1;
//}

//
//#define M 3
//#define N 4
//
//int main() {
//	int arr[M][N] = { {1,2,3,4 },{2,3,4,5},{3,4,5,6} };
//	printf("%d\n", binary_search(arr[0], N, 5));
//	printf("%d\n", binary_search(arr[1], N, 5));
//	printf("%d\n", binary_search(arr[2], N, 5));
//}

//int find_k(int arr[3][3], int* px, int* py, int k) {
//	int x = 0;
//	int y = *py - 1;
//	while (x <= *px - 1 && y >= 0) {
//		if (arr[x][y] > k) {
//			y--;
//		}
//		else if (arr[x][y] < k) {
//			x++;
//		}
//		else {
//			*px = x;
//			*py = y;
//			return 1;
//		}
//	}
//	return 0;
//}
//
//int main() {
//	int arr[3][3] = { 1,2,3,4,5,6,7,8,9 };
//	int k = 7;
//	int x = 3;
//	int y = 3;
//	if (find_k(arr, &x, &y, k)) {
//		printf("该坐标为:%d %d\n", x, y);
//	}
//	else {
//		printf("找不到该坐标.\n");
//	}
//	return 0;
//}

//void reverse(char* left, char* right) {
//	assert(left && right);
//	while (left < right) {
//		char tmp = *left;
//		*left = *right;
//		*right = tmp;
//		left++;
//		right--;
//	}
//}
//void left_move(char* str, int k) {
//	size_t len = strlen(str);
//	k = k % len;
//	reverse(str, str + k - 1);
//	reverse(str + k, str + len - 1);
//	reverse(str, str + len - 1);
//}
//
//char* Rotate_Left(char* str, int k) {
//	int len = strlen(str);
//	k = k % len;  // 确保 k 不超过字符串长度  
//	if (k == 0) return str;  // 如果 k 为 0，直接返回  
//
//	char temp[20];  // 存储结果的临时 buffer  
//	strcpy(temp, str + k);  // 复制从第 k 个字符到结束的部分  
//	strncat(temp, str, k);  // 将前 k 个字符追加到 temp 后面  
//	strcpy(str, temp);  // 将结果复制回原始字符串  
//	return str;  // 返回旋转后的字符串  
//}
//
//int main() {
//	char str[20] = "hello world";
//	int k = 2;
//	//left_move(str, k);
//	Rotate_Left(str, k);
//	printf("%s", str);
//}
//
