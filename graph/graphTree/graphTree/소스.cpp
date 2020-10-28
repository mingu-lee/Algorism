#include <stdio.h>
#include <conio.h>
#include <stdlib.h> // qsrot �Լ��� ����� ��� ���� (������)

#define TRUE 1
#define FALSE 0

#define MAX_VERTICES 100
#define INF 1000

int parent[MAX_VERTICES];		// �θ� ���
				// �ʱ�ȭ
void set_init(int n)
{
	for (int i = 0; i < n; i++)
		parent[i] = -1;
}
// curr�� ���ϴ� ������ ��ȯ�Ѵ�.
int set_find(int curr)
{
	if (parent[curr] == -1)
		return curr; 			// ��Ʈ 
	while (parent[curr] != -1) curr = parent[curr];
	return curr;
}
// �ΰ��� ���Ұ� ���� ������ ��ģ��.
void set_union(int a, int b)
{
	int root1 = set_find(a);	// ��� a�� ��Ʈ�� ã�´�. 
	int root2 = set_find(b);	// ��� b�� ��Ʈ�� ã�´�. 
	if (root1 != root2) 		// ���Ѵ�. 
		parent[root1] = root2;
}

struct Edge {			// ������ ��Ÿ���� ����ü
	int start, end, weight;
};

typedef struct GraphType {
	int n;	// ������ ����
	struct Edge edges[2 * MAX_VERTICES];
} GraphType;

// �׷��� �ʱ�ȭ 
void graph_init(GraphType* g)
{
	g->n = 0;
	for (int i = 0; i < 2 * MAX_VERTICES; i++) {
		g->edges[i].start = 0;
		g->edges[i].end = 0;
		g->edges[i].weight = INF;
	}
}
// ���� ���� ����
void insert_edge(GraphType* g, int start, int end, int w)
{
	g->edges[g->n].start = start;
	g->edges[g->n].end = end;
	g->edges[g->n].weight = w;
	g->n++;
}
// qsort()�� ���Ǵ� �Լ�
int compare(const void* a, const void* b)
{
	struct Edge* x = (struct Edge*)a;
	struct Edge* y = (struct Edge*)b;
	return (x->weight - y->weight);
}
// kruskal�� �ּ� ��� ���� Ʈ�� ���α׷�
void kruskal(int n)
{
	int edge_accepted = 0;	// ������� ���õ� ������ ��	
	int uset, vset;		// ���� u�� ���� v�� ���� ��ȣ
	struct Edge e;
	GraphType* g = NULL;

	set_init(n);		// ���� �ʱ�ȭ
	qsort(g->edges, n, sizeof(struct Edge), compare);

	printf("ũ�罺Į �ּ� ���� Ʈ�� �˰��� \n");
	int i = 0;
	while (edge_accepted < n-1)	// ����Ʈ�� ������ �� = (n-1)
	{
		e = g->edges[i];
		uset = set_find(e.start);	// ���� u�� ���� ��ȣ 
		vset = set_find(e.end);		// ���� v�� ���� ��ȣ
		if (uset != vset) {		// ���� ���� ������ �ٸ���
			printf("���� (%d,%d) %d ����\n", e.start, e.end, e.weight);
			edge_accepted++;
			set_union(uset, vset);	// �ΰ��� ������ ��ģ��.
		}
		i++;
	}
}

int main() {
	FILE *fp;
	int num_node;
	int *weight;
	int i, j;
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
				printf("%d ", weight[i*num_node + j]);
			printf("\n");
		}
	}

	kruskal(num_node); // ũ������ �˰��� ȣ��
	_getch();
}