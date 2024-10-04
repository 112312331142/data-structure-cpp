//#include<stdio.h>
//#include<malloc.h>
//#define MaxSize 50
//typedef char ElemType;
//
//typedef struct {
//	ElemType data[MaxSize];
//	int length;
//}SqList;
//
//void CreateList(SqList*& L, ElemType a[], int n) {
//	L = (SqList*)malloc(sizeof(SqList));
//	for (int i = 0; i < n; i++) {
//		L->data[i] = a[i];
//	}
//	L->length = n;
//}
//
//void InitList(SqList*& L) {
//	L = (SqList*)malloc(sizeof(SqList));
//	L->length = 0;
//}
//
//void DestroyList(SqList*& L) {
//	free(L);
//}
//
//bool ListEmpty(SqList* L) {
//	return (L->length == 0);
//}
//
//int ListLength(SqList* L) {
//	return L->length;
//}
//
//void DispList(SqList* L) {
//	for (int i = 0; i < L->length; i++)
//		printf(" %c", L->data[i]);
//	printf("\n");
//}
//
//bool GetElem(SqList* L, int i, ElemType& e) {
//	if (i<1 || i>L->length)
//		return false;
//		e = L->data[i - 1];
//	return true;
//}
//
//int LocateElem(SqList* L, ElemType e) {
//	int i = 0;
//	while (i < L->length && L->data[i] != e)
//		i++;
//	if (i >= L->length)
//		return 0;
//	else
//		return i+1;
//}
//
//bool ListInsert(SqList*& L, int i, ElemType e) {
//	int j;
//	if (i<1 || i>L->length + 1 || L->length == MaxSize)
//		return false;
//	i--;
//	for (j = L->length; j >i; j--) 
//		L->data[j] = L->data[j - 1];
//		L->data[i] = e;
//		L->length++;
//		return true;
//}
//
//bool ListDelete(SqList*& L, int i, ElemType& e) {
//	int j;
//	if (i<1 || i>L->length)
//		return false;
//	i--;
//	e = L->data[i];
//	for (j = i; j < L->length; j++)
//		L->data[j] = L->data[j + 1];
//	L->length--;
//	return true;
//}
//
//
//int main() {
//	SqList* L;
//	ElemType e;
//	//printf("˳���Ļ�����������:\n");
//	//printf("��1����ʼ��˳���L:\n");
//	InitList(L);
//	//printf("��2�����β���Ԫ��a,b,c,d,e\n");
//	ListInsert(L, 1, 'a');
//	ListInsert(L, 2, 'b');
//	ListInsert(L, 3, 'c');
//	ListInsert(L, 4, 'd');
//	ListInsert(L, 5, 'e');
//	//printf("��3������˳���L:");
//	DispList(L);
//	printf(" (4) ˳���L����:%d\n",ListLength(L));
//	printf("��5��˳���LΪ%s\n", (ListEmpty(L) ? "" : ""));
//	GetElem(L, 3, e);
//	printf("��6��˳���L�ĵ�3��Ԫ��: % c\n", e);
//	printf("��7��Ԫ��a��λ��:%d\n", LocateElem(L, 'a'));
//	printf("��8���ڵ�4��Ԫ��λ�ò���Ԫ��f\n");
//	ListInsert(L, 4, 'f');
//	printf("��9�����˳���L:");
//	DispList(L);
//	printf("��10��ɾ��L�ĵ�����Ԫ��\n");
//	ListDelete(L, 3, e);
//	printf("��11�����˳���L:");
//	DispList(L);
//	printf("��12���ͷ�˳c乘�L\n");
//	DestroyList(L);
//	return 1;
//
//}
//
//
//
//
//
//
//
//
//
