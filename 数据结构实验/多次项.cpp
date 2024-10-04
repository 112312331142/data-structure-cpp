//#include<iostream>
//using namespace std;
//#define MaxSize 100//节点最多100个
//typedef struct {
//	double coef;//系数
//	int exp;//指数
//}polyArray;
//
//typedef struct node {
//	double coef;
//	int exp;
//	node* next;
//}pnode;
//
//void dispoly(pnode* L) {//输出单项式多链表
//	int  a = 1;
//	pnode* p = L->next;
//	while (p != NULL) {
//		if (a)
//			a = 0;
//		else if (p->coef > 0)
//			cout << "+";
//		if (p->exp == 0)
//			cout << p->coef;
//		else if (p->exp == 1)
//			if (p->coef == 1)//如果系数为1，且指数不为0时，不用输入1
//				cout << "x";
//			else
//				cout << p->coef << "x";
//		else
//			if (p->coef == 1)
//				cout << "x^" << p->exp;
//			else
//			cout << p->coef << "x^" << p->exp;
//		p = p->next;
//	}
//	cout << endl;
//}
//
//void createpoly(pnode*& L, polyArray a[], int n) {//用尾插法建表
//	pnode* s, * r;
//	int i;
//	L = new pnode;
//	L->next = NULL;
//	r = L;
//	for (i = 0; i < n; i++) {
//		s = new pnode;
//		s->coef = a[i].coef;
//		s->exp = a[i].exp;
//		r->next = s;
//		r = s;
//	}
//	r->next = NULL;
//}
//void sort(pnode*& L) {//将多项式里的项顺序排列
//	pnode* p = L->next, * pre, * q;
//	if (p != NULL) {//扫描节点
//		q = p->next;
//		p->next = NULL;
//		p = q;
//		while (p != NULL) {
//			q = p->next;
//			pre = L;
//			while (pre->next != NULL && pre->next->exp > p->exp)
//				pre = pre->next;
//			p->next = pre->next;
//			pre->next = p;
//			p = q;
//		}
//	}
//}
//
//void add(pnode* a, pnode* b, pnode*& c) {//两个多项式相加
//	pnode* na = a->next, * nb = b->next, * s, * r;
//	double number;
//	c = new pnode;
//	r = c;
//	while (na != NULL && nb != NULL) {
//		if (na->exp > nb->exp) {//将指数较大的复制到c中
//			s = new pnode;
//			s->exp = na->exp;
//			s->coef = na->coef;
//			r->next = s;
//			r = s;
//			na = na->next;
//		}
//		else if (na->exp < nb->exp) {
//			s = new pnode;
//			s->exp = nb->exp;
//			s->coef = nb->coef;
//			r->next = s;
//			r = s;
//			nb = nb->next;
//		}
//		else {
//			number = na->coef + nb->coef;
//			if (number != 0) {
//				s = new pnode;
//				s->exp = na->exp;
//				s->coef = number;
//				r->next = s;
//				r = s;
//			}
//			na = na->next;
//			nb = nb->next;
//		}
//	}
//	if (nb != NULL)na = nb;//扫描余下的项
//	if (na != NULL) {
//		s = new pnode;
//		s->exp = na->exp;
//		s->coef = nb->coef;
//		r->next = s;
//		r = s;
//		na = na->next;
//	}
//	r->next = NULL;
//}
//
//int main() {
//	cout << "输入两个多项式的项数;" << endl;
//	pnode* a, * b, * c;
//	int m, n, i;
//	polyArray a1[MaxSize], b1[MaxSize];
//	cin >> m >> n;
//	cout << "输入指数与系数:" << endl;
//	for (i = 0; i < m; i++) {
//		cout << "输入第一个多项式第" << i + 1 << "项:";
//		cin >> a1[i].coef >> a1[i].exp;
//		cout << endl;
//	}
//	for (i = 0; i < n; i++) {
//		cout << "输入第二个多项式第" << i + 1 << "项:";
//		cin >> b1[i].coef >> b1[i].exp;
//		cout << endl;
//	}
//	createpoly(a, a1, m);
//	createpoly(b, b1, n);
//	cout << "输入的多项式:" << endl;
//	dispoly(a);
//	dispoly(b);
//	cout << "排列后:" << endl;
//	sort(a);
//	sort(b);
//	dispoly(a);
//	dispoly(b);
//	add(a, b, c);
//	cout << "最终结果:" << endl;
//	dispoly(c);
//	return 0;
//}
//
