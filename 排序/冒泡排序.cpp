//#include"seqlist.cpp"
//
//void BubbleSort(RecType R[], int n) {
//	int i, j;
//	bool exchange;
//	for (i = 0; i < n - 1; i++) {
//		exchange = false;
//		for (j = n - 1; j > i; j--)
//			if (R[j].key < R[j - 1].key) {
//				swap(R[j], R[j - 1]);
//				exchange = true;
//			}
//		printf("  i=%d:归位元素%d，排序结果：", i, R[i].key);
//		DispList(R, n);
//		if (!exchange)
//			return;
//	}
//}
//
//int main() {
//	int n = 10;
//	RecType R[MAXL];
//	KeyType a[] = { 4,3,2,1,0,9,8,7,6,5 };
//	CreateList(R, a, n);
//	printf("排序前："); DispList(R, n);
//	BubbleSort(R, n);
//	printf("排序后："); DispList(R, n);
//}