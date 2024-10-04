//#include"seqlist.cpp"
//int BinSearch(RecType R[], int n, KeyType k) {
//	int low = 0, high = n - 1, mid, count = 0;
//	while (low <= high) {
//		mid = (low + high) / 2;
//		printf("  第%d次比较：在[%d,%d]中比较元素R[%d]:%d\n", ++count, low, high, mid, R[mid].key);
//		if (R[mid].key == k)
//			return mid + 1;
//		if (R[mid].key > k)
//			high = mid - 1;
//		else
//			low = mid + 1;
//	}
//	return 0;
//}
//
//int main() {
//	RecType R[MAXL];
//	KeyType k = 90;
//	int a[] = { 1,2,3,4,5,6,7,8,9,10 }, i, n = 10;
//	CreateList(R, a, n);
//	printf("关键字序列："); DispList(R,n);
//	printf("查找%d的比较过程如下：\n", k);
//	if ((i = BinSearch(R, n, k)) != 0)
//		printf("元素%d的位置是%d\n", k, i);
//	else
//		printf("元素%d不在表中\n", k);
//	return 0;
//}