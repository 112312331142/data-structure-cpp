﻿#include"seqlist.cpp"

void ShellSort(RecType R[], int n) {
	int i, j, d;
	RecType tmp;
	d = n / 2;
	while (d > 0) {
		for (i = d; i < n; i++) {
			tmp = R[i];
			j = i - d;
			while (j >= 0 && tmp.key < R[j].key) {
				R[j + d] = R[j];
				j = j - d;
			}
			R[j + d] = tmp;
		}
		printf("  d=%d:", d); DispList(R, n);
		d = d / 2;
	}
}

int main() {
	int n = 10;
	RecType R[MAXL];
	KeyType a[] = { 9,8,7,6,5,4,3,2,1,0 };
	CreateList(R, a, n);
	printf("排序前："); DispList(R, n);
	ShellSort(R, n);
	printf("排序后："); DispList(R, n);
}

