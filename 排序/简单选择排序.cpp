//#include"seqlist.cpp"
//
//void SelectSort(RecType R[], int n) {
//	int i, j, k;
//	for (i = 0; i < n - 1; i++) {
//		k = i;
//		for (j = i + 1; j < n; j++)
//			if (R[j].key < R[k].key)
//				k = j;
//		if (k != i)
//			swap(R[i], R[k]);
//		printf("i=%d,选择关键字：%d，排序结果为：", i, R[i].key);
//		DispList(R, n);
//	}
//}
//
////int main() {
////	int n = 10;
////	RecType R[MAXL];
////	KeyType a[] = { 9,8,7,6,5,4,3,2,1,0 };
////	CreateList(R, a, n);
////	printf("排序前："); DispList(R, n);
////	SelectSort(R, n);
////	printf("排序后："); DispList(R, n);
////	return 1;
////}