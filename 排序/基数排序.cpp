//#include<stdio.h>
//#include<malloc.h>
//#define MAXE 20
//#define MAXR 10
//typedef struct node {
//	int key;
//	struct node* next;
//}NodeType;
//
//void CreateLink(NodeType*& p, int a[], int n) {
//	NodeType* s, * t=NULL;
//	for (int i = 0; i < n; i++) {
//		s = (NodeType*)malloc(sizeof(NodeType));
//		s->key = a[i];
//		if (i == 0) {
//			p = s; t = s;
//		}
//		else {
//			t->next = s;
//			t = s;
//		}
//	}
//	t->next = NULL;
//}
//
//void DispLink(NodeType* p) {
//	while (p != NULL) {
//		printf("%4d", p->key);
//		p = p->next;
//	}
//	printf("\n");
//}
//
//void DestroyLink(NodeType* p) {
//	NodeType* pre = p, * q = pre->next;
//	while (q != NULL) {
//		free(pre);
//		pre = q;
//		q = q->next;
//	}
//	free(pre);
//}
//
//int keyi(int s, int i) {
//	for (int j = 0; j < i; j++)
//		s = s / 10;
//	return s % 10;
//}
//
//void RadixSort(NodeType*& p, int r, int d) {
//	NodeType* head[MAXR], * tail[MAXR], * t=NULL;
//	int i, j, k;
//	for (i = 0; i < d; i++) {
//		for (j = 0; j < r; j++)
//			head[j] = tail[j] = NULL;
//		while (p != NULL) {
//			k = keyi(p->key, i);
//			if (head[k] == NULL) {
//				head[k] = p;
//				tail[k] = p;
//			}
//			else {
//				tail[k]->next = p;
//				tail[k] = p;
//			}
//			p = p->next;
//		}
//		p = NULL;
//		for(j=0;j<r;j++)
//			if (head[j] != NULL) {
//				if (p == NULL) {
//					p = head[j];
//					t = tail[j];
//				}
//				else {
//					t->next = head[j];
//					t = tail[j];
//				}
//			}
//		t->next = NULL;
//		printf("按%d位排序：", i + 1); DispLink(p);
//	}
//}
//
//int main() {
//	int n = 10;
//	NodeType* p;
//	int a[] = { 75,223,98,44,157,2,29,164,38,82 };
//	CreateLink(p, a, n);
//	printf("排序前："); DispLink(p);
//	RadixSort(p, 10,3);
//	printf("排序后："); DispLink(p);
//}