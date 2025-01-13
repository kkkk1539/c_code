//#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//#include<string.h>
//#include<assert.h>
//
//char* my_strcat(char* dest, const char* source) {
//	assert(dest != NULL);
//	assert(source != NULL);
//	while (*dest) {
//		dest++;
//	}
//	while ((*dest++ = *source++)) {
//		;
//	}
//	return dest;
//}
//
//char* my_strcpy(char* dest, const char* source) {
//	assert(dest != NULL);
//	assert(source != NULL);
//	while ((*dest++ = *source++)) {
//		;
//	}
//	return dest;
//}
//
//int my_strlen(const char* str) {
//	/*int count = 0;*/
//	assert(str != NULL);
//	/*while (*str) {
//		count++;
//		str++;
//	}*/
//
//	const char* p = str;
//	while (*p) {
//		p++;
//	}
//	return p-str;
//}
//
//int my_strcmp(const char* str1, const char* str2) {
//	assert(str1);
//	assert(str2);
//	while (*str1 == *str2) {
//		if (!(*str1)) {
//			return 0;
//		}
//		str1++;
//		str2++;
//	}
//	return (*str1 - *str2);
//}
//int main() {
//	char arr1[20] = "Hello ";
//	char arr2[] = "World";
//	my_strcat(arr1, arr2);
//	printf("%s\n", arr1);
//	int ret=my_strlen("hello world");
//	printf("%d\n", ret);
//	int ret1 = my_strcmp("hello", "hello\0world");
//	int ret2 = strcmp("hello", "hello\0world");
//	printf("%d\n", ret1);
//	printf("%d\n", ret2);
//	return 0;
//}