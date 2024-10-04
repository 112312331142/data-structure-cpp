//#include<iostream>
//using namespace std;
//
//#define MaxSize 100
//typedef char ElemType;
//typedef struct node {//二叉树的声明
//	ElemType data;//数据元素
//	int flag ;//标志位flag
//	struct node* lchild;//指向左孩子节点
//	struct node* rchild;//指向右孩子节点
//}BTNode;
//
//void CreateBTree(BTNode*& b, const char* str) {
//	BTNode* St[MaxSize], * p;//St作为顺序栈
//	p = new BTNode;
//	int top1 = -1, k, j = 0;//top1作为栈顶指针
//	char ch;//用ch遍历str中的每个字符
//	b = NULL;
//	ch = str[j];
//	while (ch != '\0') {
//		switch (ch) {
//		case'(':top1++; St[top1] = p; k = 1; break;//处理左孩子节点
//		case')':top1--; break;//栈顶节点的子树处理完毕
//		case',':k = 2; break;//处理右孩子节点
//		default:
//			p = new BTNode;
//			p->data = ch;//用p存放节点值
//			p->lchild = p->rchild = NULL;
//			if (b == NULL) {//未建立根节点时
//				b = p;
//			}
//			else {
//				switch (k) {
//				case 1:St[top1]->lchild = p; break;
//				case 2:St[top1]->rchild = p; break;
//				}
//			}
//		}
//		j++;
//		ch = str[j];//继续遍历str
//	}
//}
//
//void DispBTree(BTNode* b) {//输出二叉树
//	if (b != NULL) {
//		cout << b->data;
//		if (b->lchild != NULL || b->rchild != NULL) {
//			cout << "(";
//			DispBTree(b->lchild);
//			if (b->rchild != NULL) {
//				cout << ",";
//			}
//			DispBTree(b->rchild);
//			cout << ")";
//		}
//	}
//}
//
//typedef struct stack {
//	BTNode* data1[MaxSize];
//	int top;
//}SqStack;//定义存储树类型的栈
//
//void InitStack(SqStack*& s) {//栈的初始化
//	s = new SqStack;
//	s->top = -1;
//}
//
//bool StackEmpty(SqStack* s) {//判断栈是否为空
//	return s->top == -1;
//}
//
//void Push(SqStack*& s, BTNode* e) {//入栈
//	if (s->top == MaxSize - 1) {
//		return;
//	}
//	s->top++;
//	s->data1[s->top] = e;
//}
//
//void Pop(SqStack*& s, BTNode*& e) {//出栈
//	if (s->top == -1) {
//		return;
//	}
//	e = s->data1[s->top];
//	s->top--;
//}
//
//void PostOrder(BTNode* b) {
//	BTNode* root;//定义树节点来遍历
//	SqStack* s;//定义顺序栈
//	InitStack(s);//初始化栈
//	root = b;//首先指向树的根节点
//	while (root != NULL || !StackEmpty(s)) {//循环到root和栈均为空
//		 while(root != NULL) {//root入栈，直至没有左孩子时
//			 root->flag = 1;
//			 Push(s, root);
//			 root = root->lchild;
//		 }
//		  if(!StackEmpty(s)) {
//			 Pop(s, root);
//			 if (root->flag == 1) {//第一次出栈
//				 root->flag = 2;
//				 Push(s, root);
//				 root = root->rchild;
//			 }
//			 else if (root->flag == 2) {//第二次出栈
//				 cout << root->data << " ";
//				 root = NULL;
//			 }
//		    
//		 }
//	}
//}
//
//int main() {
//	BTNode* p;
//	CreateBTree(p, "A(B(D(,G)),C(E,F))");//定义一个树
//	cout << "原二叉树：";
//	DispBTree(p);
//	cout << endl;
//	cout << "后续遍历：";
//	PostOrder(p);
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
//
//
//
//
//
//
//
//
//
