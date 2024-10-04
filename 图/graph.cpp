#include<stdio.h>
#include<malloc.h>
#define INF 32767
#define MAXV 100

typedef char InfoType;
typedef struct {//邻接矩阵类型
	int no;//顶点的编号
	InfoType info;//顶点的其他信息
}VertexType;//顶点的类型
typedef struct {
	int edges[MAXV][MAXV];//邻接矩阵数组
	int n, e;//顶点数、边数
	VertexType vexs[MAXV];//存放顶点信息
}MatGraph;//完整的邻接矩阵类型

typedef struct ANode {//邻接表类型
	int adjvex;//临界点编号
	struct ANode* nextarc;//指向下一条边的指针
	int weight;//该边的权值
}ArcNode;//边节点类型
typedef struct Vnode {
	InfoType info;//顶点的其他信息
	int count;//存放顶点入边，仅用于拓扑排序
	ArcNode* firstarc;//指向第一条边
}VNode;//邻接表头节点类型
typedef struct {
	VNode adjlist[MAXV];//邻接表头节点数组
	int n, e;//顶点数和变数
}AdjGraph;//完整的图邻接表类型

//邻接矩阵的基本算法
void CreateMat(MatGraph& g, int A[MAXV][MAXV], int n, int e) {
	int i, j;
	g.n = n;
	g.e = e;
	for (i = 0; i < g.n; i++)
		for (j = 0; j < g.n; j++)
			g.edges[i][j] = A[i][j];
}

void DispMat(MatGraph g) {
	int i, j;
	for (i = 0; i < g.n; i++) {
		for (j = 0; j < g.n; j++)
			if (g.edges[i][j] != INF)
				printf("%4d", g.edges[i][j]);
			else
				printf("%4s", "∞");
		printf("\n");
	}
}

//邻接表的基本算法
void CreateAdj(AdjGraph*& G, int A[MAXV][MAXV], int n, int e) {
	int i, j;
	ArcNode* p;
	G = (AdjGraph*)malloc(sizeof(AdjGraph));
	for (i = 0; i < n; i++)
		G->adjlist[i].firstarc = NULL;
	for (i = 0; i < n; i++) {
		for(j=n-1;j>=0;j--)
			if (A[i][j] != 0 && A[i][j] != INF) {
				p = (ArcNode*)malloc(sizeof(ArcNode));
				p->adjvex = j;
				p->weight = A[i][j];
				p->nextarc = G->adjlist[i].firstarc;
				G->adjlist[i].firstarc = p;
			}
		G->n = n; G->e = n;
	}
}

void DispAdj(AdjGraph* G) {
	ArcNode* p;
	for (int i = 0; i < G->n; i++) {
		p = G->adjlist[i].firstarc;
		printf("%3d:", i);
		while (p != NULL) {
			printf("%3d[%d]➡️", p->adjvex, p->weight);
			p = p->nextarc;
		}
		printf("^\n");
	}
}

void DestroyAdj(AdjGraph*& G) {
	ArcNode* pre, * p;
	for (int i = 0; i < G->n; i++) {
		pre = G->adjlist[i].firstarc;
		if (pre!=NULL) {
			p = pre->nextarc;
			while (p != NULL) {
				free(pre);
				pre = p;
				p = p->nextarc;
			}
			free(pre);
		}
	}
	free(G);
}

