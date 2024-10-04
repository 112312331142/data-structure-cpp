#include"seqlist.cpp"

int count = 1;
void DispHeap(RecType R[], int i, int n) {
	if (i <= n)
		printf("%d", R[i].key);
	if (2 * i <= n || 2 * i + 1 < n) {
		printf("(");
		if (2 * i <= n)
			DispHeap(R, 2 * i, n);
		printf(",");
		if (2 * i + 1 <= n)
			DispHeap(R, 2 * i + 1, n);
		printf(")");
	}
}

void Sift(RecType R[], int low, int high) {
	int i = low, j = 2 * i;
	RecType temp = R[i];
	while (j <= high) {
		if (j < high && R[j].key < R[j + 1].key)
			j++;
		if (temp.key < R[j].key) {
			R[i] = R[j];
			i = j;
			j = 2 * i;
		}
		else
			break;
	}
	R[i] = temp;
}

void HeapSort(RecType R[], int n) {
	int i, j;
	for (i = n / 2; i >= 1; i--)
		Sift(R, i, n);
	printf("初始堆："); DispHeap(R, 1, n); printf("\n");
	for (i = n; i >= 2; i--) {
		printf("第%d趟排序：",count++);
		printf(" 交换%d与%d，输出%d", R[i].key, R[1].key, R[1].key);
		swap(R[1], R[i]);
		printf("排序结果：");
		for (j = 1; j <= n; j++)
			printf("%2d", R[j].key);
		printf("\n");
		Sift(R, 1, i - 1);
		printf("筛选调整得到堆：");
		DispHeap(R, 1, i - 1);
		printf("\n");
	}
}

int main() {
	int n = 10;
	RecType R[MAXL];
	KeyType a[] = { 6,8,7,9,0,1,3,2,4,5 };
	CreateList1(R, a, n);
	printf("排序前："); DispList1(R, n);
	HeapSort(R, n);
	printf("排序后："); DispList1(R, n);
	return 1;
}
