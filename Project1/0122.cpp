#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<assert.h>
//
//void* my_memcpy(void* dest,const  void* source, size_t n) {
//	assert(dest && source);
//	void* start = (char*)dest;
//	while (n--) {
//		*(char*)dest = *(char*)source;
//		dest = (char*)dest + 1;
//		source = (char*)source + 1;
//	}
//	return start;
//}
//
//void* my_memmove(void* dest, const void* source, size_t n) {
//	assert(dest && source);
//	void* start = dest;
//	if (dest < source) {
//		while (n--) {
//			*(char*)dest = *(char*)source;
//			dest = (char*)dest + 1;
//			source = (char*)source + 1;
//		}
//	}
//	else {
//		while (n--) {
//			*((char*)dest + n) = *((char*)source + n);
//		}
//	}
//	return start;
//}
