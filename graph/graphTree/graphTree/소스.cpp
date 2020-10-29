#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <conio.h>
#define TRUE 1
#define FALSE 0
#define MAX_VERTICES	100	
#define INF	1000000	/* 무한대 (연결이 없는 경우) */
int parent[MAX_VERTICES];		// 부모 노드
				// 초기화
typedef struct GraphType {
	int n;	// 정점의 개수
	int weight[MAX_VERTICES][MAX_VERTICES];
} GraphType;

int distance[MAX_VERTICES];/* 시작정점으로부터의 최단경로 거리 */
int found[MAX_VERTICES];		/* 방문한 정점 표시 */
int selected[MAX_VERTICES];


int choose(int distance[], int n, int found[])
{
	int i, min, minpos;
	min = INT_MAX;
	minpos = -1;
	for (i = 0; i < n; i++)
		if (distance[i] < min && !found[i]) {
			min = distance[i];
			minpos = i;
		}
	return minpos;
}
void print_status(GraphType* g)
{
	static int step = 1;
	printf("STEP %d: ", step++);
	printf("distance: ");
	for (int i = 0; i < g->n; i++) {
		if (distance[i] == INF)
			printf(" * ");
		else
			printf("%2d ", distance[i]);
	}
	printf("\n");
	printf("        found:    ");
	for (int i = 0; i < g->n; i++)
		printf("%2d ", found[i]);
	printf("\n\n");
}
//
void shortest_path(GraphType* g, int start)
{
	int i, u, w;
	for (i = 0; i < g->n; i++) /* 초기화 */
	{
		distance[i] = g->weight[start][i];
		found[i] = FALSE;
	}
	found[start] = TRUE;    /* 시작 정점 방문 표시 */
	distance[start] = 0;
	for (i = 0; i < g->n - 1; i++) {
		print_status(g);
		u = choose(distance, g->n, found);
		found[u] = TRUE;
		for (w = 0; w < g->n; w++)
			if (!found[w])
				if (distance[u] + g->weight[u][w] < distance[w])
					distance[w] = distance[u] + g->weight[u][w];
	}
}
int get_min_vertex(int n)
{
	int v, i;
	for (i = 0; i < n; i++)
		if (!selected[i]) {
			v = i;
			break;
		}
	for (i = 0; i < n; i++)
		if (!selected[i] && (distance[i] < distance[v])) v = i;
	return (v);
}
void prim(GraphType* g, int s)
{
	int i, u, v;

	for (u = 0; u < g->n; u++)
		distance[u] = INF;
	distance[s] = 0;
	for (i = 0; i < g->n; i++) {
		u = get_min_vertex(g->n);
		selected[u] = TRUE;
		if (distance[u] == INF) return;
		printf("정점 %d 추가\n", u);
		for (v = 0; v < g->n; v++)
			if (g->weight[u][v] != INF)
				if (!selected[v] && g->weight[u][v] < distance[v])
					distance[v] = g->weight[u][v];
	}
}
int A[MAX_VERTICES][MAX_VERTICES];

void printA(GraphType *g)
{
	int i, j;
	printf("===============================\n");
	for (i = 0; i < g->n; i++) {
		for (j = 0; j < g->n; j++) {
			if (A[i][j] == INF)
				printf("  * ");
			else printf("%3d ", A[i][j]);
		}
		printf("\n");
	}
	printf("===============================\n");
}

void floyd(GraphType* g)
{

	int i, j, k;
	for (i = 0; i < g->n; i++)
		for (j = 0; j < g->n; j++)
			A[i][j] = g->weight[i][j];
	printA(g);

	for (k = 0; k < g->n; k++) {
		for (i = 0; i < g->n; i++)
			for (j = 0; j < g->n; j++)
				if (A[i][k] + A[k][j] < A[i][j])
					A[i][j] = A[i][k] + A[k][j];
		printA(g);
	}
}
int main(void)
{

	GraphType g = { 7,
	{{ 0, 8, 10, INF, INF, INF, INF },
	{ 8,  0, INF, INF, INF, INF, INF },
	{ 10, INF, 0, 5, INF, INF, INF },
	{ INF, 9, 5, 0, 13, 12, INF },
	{ INF, 11, INF, 13, 0, 11, 10 },
	{ INF, INF, INF, 12, 11, 0, 7 },
	{ INF, INF, INF, INF, 10, 7 ,0 } }
	};
	
	prim(&g, 3);
	shortest_path(&g, 0);
	floyd(&g);
	_getch();
	return 0;
}


/*#include <stdio.h>
#include <conio.h>
#include <stdlib.h> // qsrot 함수가 선언된 헤더 파일 (퀵정렬)

#define TRUE 1
#define FALSE 0

#define MAX_VERTICES 100
#define INF 1000

int parent[MAX_VERTICES];		// 부모 노드
				// 초기화
void set_init(int n)
{
	for (int i = 0; i < n; i++)
		parent[i] = -1;
}
// curr가 속하는 집합을 반환한다.
int set_find(int curr)
{
	if (parent[curr] == -1)
		return curr; 			// 루트 
	while (parent[curr] != -1) curr = parent[curr];
	return curr;
}
// 두개의 원소가 속한 집합을 합친다.
void set_union(int a, int b)
{
	int root1 = set_find(a);	// 노드 a의 루트를 찾는다. 
	int root2 = set_find(b);	// 노드 b의 루트를 찾는다. 
	if (root1 != root2) 		// 합한다. 
		parent[root1] = root2;
}

struct Edge {			// 간선을 나타내는 구조체
	int start, end, weight;
};

typedef struct GraphType {
	int n;	// 간선의 개수
	struct Edge edges[2 * MAX_VERTICES];
} GraphType;

// 그래프 초기화 
void graph_init(GraphType* g)
{
	g->n = 0;
	for (int i = 0; i < 2 * MAX_VERTICES; i++) {
		g->edges[i].start = 0;
		g->edges[i].end = 0;
		g->edges[i].weight = INF;
	}
}
// 간선 삽입 연산
void insert_edge(GraphType* g, int start, int end, int w)
{
	g->edges[g->n].start = start;
	g->edges[g->n].end = end;
	g->edges[g->n].weight = w;
	g->n++;
}
// qsort()에 사용되는 함수
int compare(const void* a, const void* b)
{
	struct Edge* x = (struct Edge*)a;
	struct Edge* y = (struct Edge*)b;
	return (x->weight - y->weight);
}
// kruskal의 최소 비용 신장 트리 프로그램
void kruskal(GraphType* g)
{
	int edge_accepted = 0;	// 현재까지 선택된 간선의 수	
	int uset, vset;		// 정점 u와 정점 v의 집합 번호
	struct Edge e;

	set_init(g->n);		// 집합 초기화
	qsort(g->edges, g->n, sizeof(struct Edge), compare);

	printf("크루스칼 최소 신장 트리 알고리즘 \n");
	int i = 0;
	while (edge_accepted < g->n)	// 신장트리 간선의 수 = (n-1)
	{
		e = g->edges[i];
		uset = set_find(e.start);	// 정점 u의 집합 번호 
		vset = set_find(e.end);		// 정점 v의 집합 번호
		if (uset != vset) {		// 서로 속한 집합이 다르면
			printf("간선 (%d,%d) %d 선택\n", e.start, e.end, e.weight);
			edge_accepted++;
			set_union(uset, vset);	// 두개의 집합을 합친다.
		}
		i++;
	}
}

int main() {
	FILE *fp;
	int num_node;
	int *weight;
	int i, j;
	GraphType *g;
	g = new GraphType[100];
	g = (GraphType *)malloc(sizeof(GraphType));
	graph_init(g);
	weight = new int[100];
	fp = fopen("graph_N.txt", "r");
	if (fp != NULL) {
		fscanf(fp, "%d", &num_node);
		weight = (int *)malloc(sizeof(int) * num_node * num_node);
		for (i = 0; i < num_node; i++)
			for (j = 0; j < num_node; j++)
				fscanf(fp, "%d", &weight[i*num_node + j]);
		printf("\n");
		for (i = 0; i < num_node; i++) {
			for (j = 0; j < num_node; j++)
				insert_edge(g, i+1, j+1, weight[i*num_node + j]);
		}
	}

	kruskal(g); // 크러스컬 알고리즘 호출
	_getch();
}*/