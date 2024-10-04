//#include<iostream>
//using namespace std;
//typedef int ElemType;
//typedef struct LNode {
//	ElemType data;
//	struct LNode* next;
//}LinkNode;
//
//void CreateListR(LinkNode*& L, ElemType a[], int n) {
//	LinkNode* s, * r;
//	L = (LinkNode*)malloc(sizeof(LinkNode));
//	L->next = NULL;
//	r = L;
//	for (int i = 0; i < n; i++) {
//		s = (LinkNode*)malloc(sizeof(LinkNode));
//		s->data = a[i];
//		r->next = s;
//		r = s;
//	}
//	r->next = NULL;
//}
//
//
//void DispList(LinkNode* a) {
//	LinkNode* pa = a->next;
//	while (pa != NULL) {
//		cout << pa->data << " ";
//		pa = pa->next;
//	}
//	cout << endl;
//}
//
//void InterSection(LinkNode* a, LinkNode* b, LinkNode*& c) {
//	LinkNode *pa = a->next,*pb,*s,*nc;
//	c = new LinkNode;
//	nc = c;
//	while (pa != NULL) {
//		pb = b->next;
//		while (pb != NULL && pb->data < pa->data)
//			pb = pb->next;
//		if (pb != NULL && pb->data == pa->data) {
//			s = new LinkNode;
//			s->data = pa->data;
//			nc->next = s;
//			nc = s;
//		}
//		pa = pa->next;
//	}
//	nc->next = NULL;
//}
//
//int main() {
//	LinkNode* ha, * hb, * hc;
//	ElemType a[] = { 2,4,6,8 }, b[] = { 4,6,8,10 };
//	CreateListR(ha, a, 4);
//	CreateListR(hb, b, 4);
//	InterSection(ha, hb, hc);
//	DispList(ha);
//	DispList(hb);
//	cout << "交集：";
//	DispList(hc);
//
//}