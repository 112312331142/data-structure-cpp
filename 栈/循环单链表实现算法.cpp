//#include<stdio.h>
//#include<malloc.h>
//typedef int ElemType;
//typedef struct LNode {
//	ElemType data;
//	struct LNode* next;
//}LinkNode;
//
//void CreateListF(LinkNode*& L, ElemType a[], int n) {
//	LinkNode* s;
//	int i;
//	L = (LinkNode*)malloc(sizeof(LinkNode));
//	L->next = NULL;
//	for (i = 0; i < n; i++) {
//		s = (LinkNode*)malloc(sizeof(LinkNode));
//		s->data = a[i];
//		s->next = L->next;
//		L->next = s;
//	}
//	s = L->next;
//	while (s->next != NULL)
//		s = s->next;
//	s->next = L;
//}
//
//void CreateListR(LinkNode*& L, ElemType a[], int n) {
//	LinkNode* s, * r;
//	int i;
//	L = (LinkNode*)malloc(sizeof(LinkNode));
//	L->next = NULL;
//	r = L;
//	for (i = 0; i < n; i++) {
//		s = (LinkNode*)malloc(sizeof(LinkNode));
//		s->data = a[i];
//		r->next=s;
//		r = s;
//	}
//	r->next = L;
//}
//
//void InitList(LinkNode*& L) {
//	L = (LinkNode*)malloc(sizeof(LinkNode));
//	L->next = L;
//}
//
//void DestroyList(LinkNode*& L) {
//	LinkNode* pre = L, * p = pre->next;
//	while (p != L) {
//		free(pre);
//		pre = p;
//		p = pre->next;
//	}
//	free(pre);
//}
//
//bool ListEmpty(LinkNode* L) {
//	return L->next == NULL;
//}
//
//int ListLength(LinkNode* L) {
//	LinkNode* p = L;
//	int i = 0;
//	while (p->next != L) {
//		i++;
//		p = p->next;
//	}
//	return (i);
//}
//
//void DispList(LinkNode* L) {
//	LinkNode* p = L->next;
//	while (p != L) {
//		printf("%c", p->data);
//		p = p->next;
//	}
//	printf("\n");
//}
//
//bool GetElem(LinkNode* L, int i, ElemType& e) {
//	int j = 1;
//	LinkNode* p = L->next;
//	if (i <= 0 || L->next == L)
//		return false;
//	if (i == 1) {
//		e = L->next->data;
//		return true;
//	}
//	else {
//		while (j <=i - 1 && p != L) {
//			j++;
//			p = p->next;
//		}
//		if (p == L)
//			return false;
//		else {
//			e = p->data;
//			return true;
//		}
//	}
//}
//
//int LocateElem(LinkNode* L, ElemType e) {
//	LinkNode* p = L->next;
//	int i = 1;
//	while (p != L && p->data != e) {
//		p = p->next;
//		i++;
//	}
//	if (p == L)
//		return 0;
//	else
//		return i;
//}
//
//bool ListInsert(LinkNode* &L, int i, ElemType e) {
//	int j = 1;
//	LinkNode* p = L, *s;
//	if (i <= 0)
//		return false;
//	if (p->next == L || i == 1) {
//		s = (LinkNode*)malloc(sizeof(LinkNode));
//		s->data = e;
//		s->next = p->next;
//		p->next = s;
//		return true;
//	}
//	else {
//		p = L->next;
//		while (j <= i - 2 && p != L) {
//			j++;
//			p = p->next;
//		}
//		if (p == L)
//			return false;
//		else {
//			s = (LinkNode*)malloc(sizeof(LinkNode));
//			s->data = e;
//			s->next = p->next;
//			p->next = s;
//			return true;
//		}
//	}
//}
//
//bool ListDelete(LinkNode*& L, int i, ElemType &e) {
//	int j = 1;
//	LinkNode* p = L, * q;
//	if (i <= 0 || L->next == L)
//		return false;
//	if (i == 1) {
//		q = L->next;
//		e = q->data;
//		L->next = q->next;
//		free(q);
//		return true;
//	}
//	else {
//		p = L->next;
//		while (j <= i - 2 && p != L) {
//			j++;
//			p = p->next;
//		}
//		if (p == L)
//			return false;
//		else {
//			q = p->next;
//			e = q ->data;
//			p->next = q->next;
//			free(q);
//			return true;
//		}
//	}
//}
//
//int main() {
//		LinkNode* h;
//		ElemType e;
//		printf("������Ļ�����������:\n");
//		printf("(1)��ʼ��������h\n");
//		InitList(h);
//		printf("(2)���β���β�巨����Ԫ��a,b,c,d,e\n");
//		ListInsert(h, 1, 'a');
//		ListInsert(h, 2, 'b');
//		ListInsert(h, 3, 'c');
//		ListInsert(h, 4, 'd');
//		ListInsert(h, 5, 'e');
//		printf("(3)���������h:"); DispList(h);
//		printf("(4)������h���ȣ�%d\n", ListLength(h));
//		printf("(5)������hΪ%s\n", (ListEmpty(h)?"��":"�ǿ�"));
//		GetElem(h, 3, e);
//		//DispList(h);
//		printf("(6)������h�ĵ�����Ԫ�أ�%c\n", e);
//		printf("(7)Ԫ��a��λ�ã�%d\n", LocateElem(h, 'a'));
//		printf("(8)�ڵ�4��Ԫ��λ���ϲ���Ԫ��f\n");
//		ListInsert(h, 4, 'f');
//		printf("(9)���������h:"); DispList(h);
//		printf("(10)ɾ��h�ĵ�����Ԫ��\n");
//		ListDelete(h, 3, e);
//		printf("(11)���������h:"); DispList(h);
//		printf("(12)�ͷŵ�����h\n");
//		DestroyList(h);
//		return 0;
//	}