#include"graph.cpp"
int visited[MAXV];
void DFSALL(AdjGraph* G, int v, int path[], int d) {
	ArcNode* p;
	visited[v] = 1;
	path[d] = v;
	d++;
	if (d == G->n) {
		for (int k = 0; k < d; k++)
			printf("%2d", path[k]);
		printf("\n");
		visited[v] = 0;
		return;
	}
	p = G->adjlist[v].firstarc;
	while (p != NULL) {
		if (visited[p->adjvex] == 0)
			DFSALL(G, p->adjvex, path, d);
		p = p->nextarc;
	}
	visited[v] = 0;
}

int main() {
	AdjGraph* G;
	int A[MAXV][MAXV] = { {0,1,0,1,1},{1,0,1,1,0},{0,1,0,1,1},{1,1,1,0,1},{1,0,1,1,0} };
	int n = 5, e = 8;
	CreateAdj(G, A, n, e);
	DispAdj(G);
	int path[MAXV], v = 1;
	DFSALL(G, v, path, 0);
	printf("\n");
	DestroyAdj(G);
	return 0;
}