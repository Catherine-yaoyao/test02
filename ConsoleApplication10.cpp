// ConsoleApplication10.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

char **getMem(int num) {
	char **p;
	int i;
	p = NULL;
	p = (char**)malloc(sizeof(char*)*num);//动态申请了num个(char *）字节大小的内存，把指针强制转换成char类型的指针，该指针
										  //指向的是下一级指针；
	if (p == NULL) {
		return NULL;
	}
	for (i = 0; i < num; i++) {
		p[i] = (char*)malloc(sizeof(char) * 100);//该指针指向的是内存块内容了，即字符串
		sprintf(p[i], "%d%d%d", i + 1, i + 1, i + 1);
	}
	return p;

}
void printArray(char **myArray, int num) {
	int i;
	for (i = 0; i < num; i++) {
		printf("%s\n", myArray[i]);
	}
}
void sortmyArray(char **myArray, int num) {
	int i, j;
	i = 0, j = 0;
	char *tmp;
	for (i = 0; i < num; i++) {
		for (j = i + 1; j < num; j++) {
			if (strcmp(myArray[i], myArray[j]) > 0) {
				tmp = myArray[i];
				myArray[i] = myArray[j];
				myArray[j] = tmp;
			}
		}
	}
}

void getMem_free(char **myArray, int num) {
	char **p = myArray;
	int i = 0;
	for (i = 0; i < num; i++) {
		if (p[i] != NULL) {
			free(p[i]);
			p[i] = NULL;
		}
		if (p != NULL) {
			free(p);
			p = NULL;
		}
	}
}
void main() {
	char **p = NULL;
	int i = 0;
	int num = 5;
	p = getMem(num);
	printArray(p, num);
	sortmyArray(p, num);
	getMem_free(p, num);


}

