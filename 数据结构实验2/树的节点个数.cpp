//#include<iostream>
//using namespace std;
//
//#define MaxSize 100
//typedef char ElemType;
//typedef struct node {
//	ElemType data;
//	struct node* lchild;
//	struct node* rchild;
//}BTNode;
//
//void CreateBTree(BTNode*& b, const char* str) {
//	BTNode* St[MaxSize], * p;
//	p = (BTNode*)malloc(sizeof(BTNode));
//	int top = -1, k, j = 0;
//	char ch;
//	b = NULL;
//	ch = str[j];
//	while (ch != '\0') {
//		switch (ch) {
//		case'(':top++; St[top] = p; k = 1; break;
//		case')':top--; break;
//		case',':k = 2; break;
//		default:p = (BTNode*)malloc(sizeof(BTNode));
//			p->data = ch; p->lchild = p->rchild = NULL;
//			if (b == NULL)
//				b = p;
//			else {
//				switch (k) {
//				case 1:St[top]->lchild = p; break;
//				case 2:St[top]->rchild = p; break;
//				}
//			}
//		}
//		j++;
//		ch = str[j];
//	}
//}
//
//int Nodes(BTNode* b) {
//	int num1, num2;
//	if (b == NULL)
//		return 0;
//	else if (b->lchild == NULL && b->rchild == NULL)
//		return 1;
//	else {
//		num1 = Nodes(b->lchild);
//		num2 = Nodes(b->rchild);
//		return num1 + num2 + 1;
//	}
//}
//
//int main() {
//	BTNode* p;
//	CreateBTree(p, "A(B(D,E(H(J,K(L,M(,N))))),C(F,G(,I))");
//	cout << Nodes(p) << endl;
//}