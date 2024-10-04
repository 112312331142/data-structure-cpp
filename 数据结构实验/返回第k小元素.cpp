//#include<iostream>
//using namespace std;
//#define MaxSize 100
//typedef int ElemType;
//typedef struct LNode {
//	ElemType data;
//	struct LNode* next;
//}LinkNode;
//
//void Create(LinkNode*&L, ElemType a[], int n) {
//	LinkNode* r, * s;
//	L = new LinkNode;
//	L->next = NULL;
//	r = L;
//	for (int i = 0; i < n; i++) {
//		s = new LinkNode;
//		s->data = a[i];
//		r->next = s;
//		r = s;
//	}
//	r->next = NULL;
//}
//
////void Disp(LinkNode* L) {
////	LinkNode* p = L->next;
////	while (p != NULL) {
////		cout << p->data << " ";
////		p = p->next;
////	}
////	cout << endl;
////}
//
//int ListLength(LinkNode* L) {
//	int n = 0;
//	LinkNode* p = L;
//	while (p->next != NULL) {
//		n++;
//		p = p->next;
//	}
//	return n;
//}
//
//int Select(LinkNode*& L,int k) {
//	LinkNode* p = L->next, * pre = L, * minp = p, * minpre = pre;
//	for (int i = 0; i < k; i++) {
//		LinkNode* p = L->next, * pre = L, * minp = p, * minpre = pre;
//		while (p != NULL) {
//			if (minp->data > p->data) {
//				minp = p;
//				minpre = pre;
//			}
//			pre = p;
//			p = p->next;
//		}
//		if (i != k - 1) {
//			minpre->next = minp->next;
//			delete []minp;
//		}
//		else
//		    return minp->data;
//		}
//	
//}
//
//int main() {
//	LinkNode* ha;
//	int a[MaxSize];
//	int n,k;
//	cin >> n;
//	for (int i = 0; i < n; i++) {
//		cin >> a[i];
//	}
//	cout << "输入k值";
//	cin >> k;
//	if (n < k)
//		exit(0);
//	Create(ha, a, n);
//	/*Disp(ha);*/
//	cout << Select(ha, k) << endl;
//}