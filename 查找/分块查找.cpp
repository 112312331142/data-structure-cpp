﻿//#include"seqlist.cpp"
//#define MAXI 20
//typedef struct {
//	KeyType key;
//	int link;
//}IdxType;
//
//int IdxSearch(IdxType I[], int b, RecType R[], int n, KeyType k) {
//	int s = (n + b - 1) / b;
//	int count1 = 0, count2 = 0;
//	int low = 0, high = b - 1, mid, i;
//	printf("(1)在索引表中折半查找\n");
//	while (low <= high) {
//		mid = (low + high) / 2;
//		printf("  第%d次比较：在[%d,%d]中比较元素R[%d]:%d\n", count1 + 1, low, high, mid, I[mid].key);
//		if (I[mid].key >= k)high = mid - 1;
//		else
//			low = mid + 1;
//		count1++;
//	}
//	printf("比较%d次，在第%d块中查找对应元素%d\n", count1, low+1, k);
//	i = I[high + 1].link;
//	printf("(2)在对应块中顺序查找：\n");
//	while (i <= I[high + 1].link + s - 1) {
//		printf(" %d ", R[i].key);
//		count2++;
//		if (R[i].key == k)
//			break;
//		i++;
//	}
//	printf("比较%d次，在顺序表中查找元素%d\n", count2, k);
//	if (i <= I[high+1].link + s - 1)
//		return i + 1;
//	else
//		return 0;
//}
//
//int main() {
//	RecType R[MAXL];
//	IdxType I[MAXL];
//	int n = 25, i;
//	int a[] = { 8,14,6,9,10,22,34,18,19,31,40,38,54,66,46,71,78,68,80,85,100,94,88,96,87 };
//	CreateList(R, a, n);
//	I[0].key = 14; I[0].link = 0;
//	I[1].key = 34; I[1].link = 5;
//	I[2].key = 66; I[2].link = 10;
//	I[3].key = 85; I[3].link = 15;
//	I[4].key = 100; I[4].link = 20;
//	printf("关键字序列:");
//	for (i = 0; i < n; i++) {
//		printf("%4d", R[i].key);
//		if (((i + 1) % 5) == 0)printf("    ");
//		if (((i + 1) % 5) == 0)printf("\n\t   ");
//	}
//	printf("\n");
//	KeyType k = 46;
//	printf("查找%d的比较过程如下：\n", k);
//	if ((i = IdxSearch(I, 5, R, 25, k)) != -1)
//		printf("元素%d的位置是%d\n", k, i);
//	else
//		printf("error");
//	return 0;
//}
//
