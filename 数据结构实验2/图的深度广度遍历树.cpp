//#include<iostream>
//#include<iomanip>
//using namespace std;
//
//#define MAXV 100//图最大结点个数
//#define INF 32767
//#define MaxSize 100//队列最大结点个数
//typedef char InfoType;
////以下定义邻接表类型
//typedef struct ANode {
//	int adjvex;//该边的邻接点编号
//	struct ANode* nextarc;//指向下一条边的指针
//	int weight;//该边的相关信息
//}ArcNode;//边界点类型
//typedef struct Vnode {
//	InfoType info;//顶点的其他类型
//	ArcNode* firstarc;//指向第一条边
//}VNode;//邻接表的头结点类型
//typedef struct {
//	VNode adjlist[MAXV];//邻接表的节点数组
//	int n, e;//顶点数n和边数e
//}AdjGraph;//完整的邻接表类型
//
//void CreateAdj(AdjGraph*& G, int A[MAXV][MAXV], int n,int e) {//创建图的邻接表
//	int i, j;
//	ArcNode* p;
//	G = new AdjGraph;
//	for (i = 0; i < n; i++) {
//		G->adjlist[i].firstarc = NULL;//邻接表头指针置空
//	}
//	for (i = 0; i < n; i++) {
//		for (j = n - 1; j >= 0; j--)
//			if (A[i][j] != 0 && A[i][j] != INF) {//检查两点之间是否存在边
//				p = new ArcNode;
//				p->adjvex = j;
//				p->weight = A[i][j];
//				p->nextarc = G->adjlist[i].firstarc;//头插法
//				G->adjlist[i].firstarc = p;
//			}
//	}
//	G->n = n;
//	G->e = e;//图G的边数和结点数
//}
//
//void DispAdj(AdjGraph* G) {//输出图
//	int i;
//	ArcNode* p;
//	for (i = 0; i < G->n; i++) {
//		p = G->adjlist[i].firstarc;
//		cout << setw(3) << i;
//		while (p != NULL) {
//			cout << setw(3) << p->adjvex << "[" << p->weight << "]->";
//			p = p->nextarc;
//		}
//		printf("\n");
//	}
//}
//
//typedef struct {//队列的声明，用于广度有先遍历
//	int data[MaxSize];
//	int front, rear;
//}SqQueue;
//
//void InitQueue(SqQueue*& q) {//初始化队列
//	q = new SqQueue;
//	q->front = q->rear = 0;
//}
//
//bool QueueEmpty(SqQueue* q) {//判断队列是否为空
//	return (q->front == q->rear);
//}
//
//void enQueue(SqQueue* q, int e) {//进队
//	if ((q->rear+1)%MaxSize == q->front)
//		return;
//	q->rear=(q->rear+1)%MaxSize;
//	q->data[q->rear] = e;
//}
//
//void deQueue(SqQueue* q, int& e) {//出队
//	if (q->rear == q->front)
//		return;
//	q->front=(q->front+1)%MaxSize;
//	e = q->data[q->front];
//}
//
//int visited[MAXV] = { 0 };//全局数组
//void DFS(AdjGraph* G, int v) {//深度优先遍历
//	ArcNode* p;
//	visited[v] = 1;//为1时，表示已访问过
//	p = G->adjlist[v].firstarc;//p指向v的第一个邻接点
//	while (p != NULL) {
//		if (visited[p->adjvex] == 0) {
//			cout << "(" << v << "," << p->adjvex << ")";
//			DFS(G, p->adjvex);
//		}
//		p = p->nextarc;
//	}
//}
//
//void BFS(AdjGraph* G, int v) {//广度优先遍历
//	int w, i;
//	ArcNode* p;
//	SqQueue* qu;//环形队列指针
//	InitQueue(qu);
//	int visited[MAXV];
//	for (i = 0; i < G->n; i++) {
//		visited[i]=0;
//	}
//	visited[v] = 1;//设置已访问标记
//	enQueue(qu, v);
//	while (!QueueEmpty(qu)) {//队不空时循环
//		deQueue(qu, w);//出队顶点w
//		p = G->adjlist[w].firstarc;
//		while (p != NULL) {//产找w的所有邻接点
//			if (visited[p->adjvex] == 0) {
//				cout << "(" << w << "," << p->adjvex<< ")";
//				visited[p->adjvex] = 1;//置访问标记
//				enQueue(qu, p->adjvex);//该顶点进队
//			}
//			p = p->nextarc;//下一个邻接点
//		}
//	}
//	cout << endl;
//}
//
//int main() {
//	AdjGraph* G;
//	int A[MAXV][MAXV] = { { 0,1,0,1,1 },{ 1,0,1,1,0 },{0,1,0,1,1},{1,1,1,0,1},{1,0,1,1,0}};
//	int n = 5, e = 8;
//	CreateAdj(G, A, n, e);
//	cout << "图G的邻接表：\n";
//	DispAdj(G);
//	int v = 2;
//	cout << "深度优先生成树：" << endl;
//	DFS(G, v);
//	cout << endl;
//	cout << "广度优先生成树：" << endl;
//	BFS(G, v);
//
//}