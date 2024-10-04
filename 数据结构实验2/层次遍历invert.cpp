//
//#include<iostream>
//using namespace std;
//
//#define MaxSize 100
//typedef int ElemType;
//typedef struct BiNode {
//	ElemType data;
//	BiNode* lchild;
//	BiNode* rchild;
//
//}BiNode, * BiTree;
//
////构建二叉树
//BiNode* Create(BiNode* bt) {
//	static int i = 0;
//	char ch;
//	//string str = "AB#D##C##";
//	//string str = "124##56##7##3##";
//	string str = "ABD#G##E##CF###";
//	ch = str[i++];
//	if (ch == '#')bt = NULL;//建立一棵空树 
//	else {
//		bt = (BiTree)malloc(sizeof(BiNode)); bt->data = ch;//生成一个结点，数据域为ch
//		bt->lchild = Create(bt->lchild);//递归建立左子树
//		bt->rchild = Create(bt->rchild);//递归建立右子树
//	}
//	return bt;
//}
//
//void visit(int x) {
//	printf("%c ", x);
//}
//
//typedef struct {
//	BiTree data[MaxSize];//存放栈中元素
//	int top;//栈顶指针
//}SqStack;
//
////（1）初始化
//void InitStack(SqStack& S) {
//	S.top = -1;//初始化栈顶指针
//}
////（2）判栈空
//bool IsEmpty(SqStack& S) {
//	if (S.top == -1) {//栈空
//		return true;
//	}
//	else {//不空
//		return false;
//	}
//}
////（3）进栈
//bool Push(SqStack& S, BiTree& p) {
//	if (S.top == MaxSize - 1) {//栈满，报错
//		return false;
//	}
//	S.data[++S.top] = p;//指针先加1，再加入栈
//	return true;
//}
////（4）出栈
//bool Pop(SqStack& S, BiTree& p) {
//	if (S.top == -1) {//栈空，报错
//		return false;
//	}
//	p = S.data[S.top--];//先出栈，指针再减1
//	return true;
//}
////（5）读栈顶元素
//bool GetTop(SqStack& S, BiTree& p) {
//	if (S.top == -1) {//栈空，报错
//		return false;
//	}
//	p = S.data[S.top];//先出栈，指针再减1
//	return true;
//}
//
//typedef struct {
//	BiTree data[MaxSize];//存放队列元素
//	int front, rear;//队头指针和队尾指针
//}SqQueue;
//
////循环队列的操作
//
////初始化
//void InitQueue(SqQueue& Q) {
//	Q.rear = Q.front = 0;//初始化队首、队尾指针
//}
//
////判断队空
//bool QIsEmpty(SqQueue Q) {
//	if (Q.rear == Q.front) {//队空条件
//		return true;
//	}
//	else {
//		return false;
//	}
//}
//
////入队
//bool EnQueue(SqQueue& Q, BiTree& p) {
//	if ((Q.rear + 1) % MaxSize == Q.front)//队满则报错
//		return false;
//	Q.data[Q.rear] = p;
//	Q.rear = (Q.rear + 1) % MaxSize;//队尾指针加1取模
//	return true;
//}
//
////出队
//bool DeQueue(SqQueue& Q, BiTree& p) {
//	if (Q.rear == Q.front)//队空则报错
//		return false;
//	p = Q.data[Q.front];
//	Q.front = (Q.front + 1) % MaxSize;//队头指针加1取模
//	return true;
//}
//
//void InvertLevel(BiTree bt) {
//	SqStack S;
//	SqQueue Q;
//	BiNode* p;
//	if (bt != NULL) {
//		InitStack(S);//栈初始化，栈中存放二叉树结点的指针
//		InitQueue(Q);//队列初始化，队列中存放二叉树结点的指针
//		EnQueue(Q, bt);
//		while (QIsEmpty(Q) == false) {//从上而下层次遍历
//			DeQueue(Q, p);
//			Push(S, p);//出队，入栈
//			if (p->lchild)
//				EnQueue(Q, p->lchild);//若左子女不空，则入队列
//			if (p->rchild)
//				EnQueue(Q, p->rchild);//若右子女不空，则入队列
//		}
//		while (IsEmpty(S) == false) {
//			Pop(S, p);
//			visit(p->data);
//		}//自下而上，从右到左的层次遍历
//	}//if结束
//}
//
//int main() {
//	//创建一棵二叉树
//	BiTree T = (BiTree)malloc(sizeof(BiNode));//创建一颗二叉树
//	T = Create(T);
//	printf("自下而上、从右到左的层序遍历 \n");
//	//自下而上、从右到左的层序遍历
//	InvertLevel(T);
//}