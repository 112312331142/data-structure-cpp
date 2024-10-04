//#include<iostream>
//#include<iomanip>
//using namespace std;
//
//#define MAXV 100//最大结点个数
//#define INF 32767//表示不相连 
//typedef struct ANode {//图的存储结构与基本运算方法
//	int adjvex;
//	struct ANode* nextarc;
//	int weight;
//}ArcNode;
//typedef struct Vnode {
//	ArcNode* firstarc;
//}VNode;
//typedef struct {
//	VNode adjlist[MAXV];
//	int n, e;
//}AdjGraph;
//
//void CreateAdj(AdjGraph*& G, int A[MAXV][MAXV], int n, int e) {
//	int i, j;
//	ArcNode* p;
//	G = new AdjGraph;
//	for (i = 0; i < n; i++)
//		G->adjlist[i].firstarc = NULL;
//	for (i = 0; i < n; i++) {
//		for (j = n - 1; j >= 0; j--)
//			if (A[i][j] != 0 && A[i][j] != INF) {
//				p = new ArcNode;
//				p->adjvex = j;
//				p->weight = A[i][j];
//				p->nextarc = G->adjlist[i].firstarc;
//				G->adjlist[i].firstarc = p;
//			}
//	}
//	G->n = n;
//	G->e = e;
//}
//
//void DispAdj(AdjGraph* G) {
//	int i;
//	ArcNode* p;
//	for (i = 0; i < G->n; i++) {
//		p = G->adjlist[i].firstarc;
//		cout << setw(3) << i;
//		while (p != NULL) {
//			cout << setw(3) << p->adjvex << "[" << p->weight << "]->";
//			p = p->nextarc;
//		}
//		cout << "^" << endl;
//	}
//}
//
//typedef int ElemType;
//#define MaxSize 100
//typedef struct {//栈的存储结构与基本运算算法
//	ElemType data[MaxSize];
//	int top;
//}SqStack;
//
//void InitStack(SqStack*& s) {
//	s = new SqStack;
//	s->top = -1;
//}
//
//void Push(SqStack*& s, ElemType e) {
//	if (s->top == MaxSize - 1)
//		return;
//	s->top++;
//	s->data[s->top] = e;
//}
//
//void Pop(SqStack*& s, ElemType& e) {
//	if (s->top == -1)
//		return;
//	e = s->data[s->top];
//	s->top--;
//}
//
//bool StackEmpty(SqStack* s) {
//	return s->top == -1;
//}
//
//void TopSort(AdjGraph* G) {//拓扑排序算法
//	SqStack* S;//定义栈存放顶点
//	InitStack(S);
//	int count = 0;//累加器count初始化
//	int indegree[MAXV];
//	for (int i = 0; i < G->n; i++)
//		indegree[i] = 0;
//	for (int i = 0; i < G->n; i++) {//求所有顶点的入度
//		ArcNode* p = G->adjlist[i].firstarc;
//		while (p != NULL) {
//			int w = p->adjvex;//找到顶点i的邻接点w
//			indegree[w]++;//顶点w的入度增一
//			p = p->nextarc;
//		}
//	}
//	for (int i = 0; i < G->n; i++) {//入度为0的顶点入栈
//		if (indegree[i] == 0)
//			Push(S, i);
//	}
//	int i;
//	while (!StackEmpty(S)) {//当栈S非空时循环
//		Pop(S, i);
//		cout << setw(3) << i;//将顶点i出栈，并访问
//		count++;//累加器加一
//		ArcNode* p = G->adjlist[i].firstarc;//寻找第一个邻接点
//		while (p != NULL) {//循环使顶点i的邻接点减一
//			int w = p->adjvex;
//			indegree[w]--;
//			if (indegree[w] == 0)//减一后将新的邻接点进栈
//				Push(S, w);
//			p = p->nextarc;
//		}
//	}
//	if (count < G->n)//当count<图的边数时
//		cout << "该图存在回路" << endl;//输出有回路信息
//}
//
//int main() {
//	int n = 5, e = 7;
//	int A[MAXV][MAXV] = { {0,1,1,0,0},{0,0,1,0,0},{0,0,0,1,1},
//	{0,0,0,0,1},{1,0,0,0,0} };
//	int n1 = 7, e1 = 8;
//	int B[MAXV][MAXV] = { {0,0,1,0,0,0,0},{0,0,0,1,1,0,1},{0,0,0,1,0,0,0},
//	{0,0,0,0,1,1,0},{0,0,0,0,0,0,0},{0,0,0,0,0,0,0},{0,0,0,0,0,1,0} };
//	AdjGraph* G;
//	AdjGraph* G1;
//	CreateAdj(G, A, n, e);
//	cout << "图G的邻接表输出为:" << endl;
//	DispAdj(G);
//	CreateAdj(G1, B, n1, e1);
//	cout << "图G1的邻接表输出为:" << endl;
//	DispAdj(G1);
//	cout << "图G的拓扑排序输出为:" << endl;
//	TopSort(G);
//	cout << "图G1的拓扑排序输出为:" << endl;
//	TopSort(G1);
//}
//
//
//
//
//
//
