#include"seqlist.cpp"
void disppart(RecType R[], int s, int t) {
	static int i = 1;
	int j;
	printf("第%d次划分：", i);
	for (j = 0; j < s; j++)
		printf("    ");
	for (j = s; j <= t; j++)
		printf(" %3d", R[j].key);
	printf("\n");
	i++;
}

int partition(RecType R[], int s, int t) {
	int i = s, j = t;
	RecType tmp = R[i];
	while (i < j) {
		while (j > i && R[j].key >= tmp.key)
			j--;
		if (j > i) {
			R[i] = R[j];
			i++;
		}
		while (i < j && R[i].key <= tmp.key)
			i++;
		if (i < j) {
			R[j] = R[i];
			j--;
		}
	}
	R[i] = tmp;
	disppart(R, s, t);
	return i;
}

void QuickSort(RecType R[], int s, int t) {
	int i;
	if (s < t) {
		i = partition(R, s, t);
		QuickSort(R, s, i - 1);
		QuickSort(R, i + 1, t);
	}
}

int main() {
	int n = 10;
	RecType R[MAXL];
	KeyType a[] = { 6,8,7,9,0,1,3,2,4,5 };
	CreateList(R, a, n);
	printf("排序前："); DispList(R, n);
	QuickSort(R,0,n-1);
	printf("排序后："); DispList(R, n);
	return 1;
}