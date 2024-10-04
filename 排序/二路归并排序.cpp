//#include"seqlist.cpp"
//#include<malloc.h>
//void Merge(RecType R[], int low, int mid, int high) {
//	RecType* R1;
//	int i = low,j=mid + 1, k = 0;
//	R1 = (RecType*)malloc((high - low + 1) * sizeof(RecType));
//	while(i<=mid&&j<=high)
//		if (R[i].key <= R[j].key) {
//			R1[k] = R[i];
//			i++;
//			k++;
//		}
//		else {
//			R1[k] = R[j];
//			j++;
//			k++;
//		}
//	while (i <= mid) {
//		R1[k] = R[i];
//		i++; k++;
//	}
//	while (j <= high) {
//		R1[k] = R[j];
//		j++;
//		k++;
//	}
//	for (k = 0, i = low; i <= high; k++, i++)
//		R[i] = R1[k];
//}
//
//int count = 1;
//void MergePass(RecType R[], int length, int n) {
//	int i;
//	printf("第%d趟归并：", count++);
//	for (i = 0; i + 2 * length - 1 < n; i = i + 2 * length) {
//		printf("R[%d,%d]和R[%d,%d]归并   ", i, i + length - 1, i + length, i + 2 * length - 1);
//		Merge(R, i, i + length - 1, i + 2 * length - 1);
//	}
//	if (i + length - 1 < n - 1) {
//		printf("*R[%d,%d]和R[%d,%d]归并    ", i, i + length - 1, i + length, n - 1);
//		Merge(R, i, i + length - 1, n - 1);
//	}
//	printf("\n归并结果： "); DispList(R, n);
//}
//
//void MergeSort(RecType R[],int n) {
//	int length;
//	for (length = 1; length < n; length = 2 * length)
//		MergePass(R, length, n);
//}
//
//int main() {
//	int n = 11;
//	RecType R[MAXL];
//	KeyType a[] = { 18,2,20,34,12,32,6,16,5,8,1 };
//	CreateList(R, a, n);
//	printf("排序前："); DispList(R, n);
//	MergeSort(R, n);
//	printf("排序后："); DispList(R, n);
//}