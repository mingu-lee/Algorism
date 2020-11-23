#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include <conio.h>
#include <queue>

#define DATA_NUM	50
#define SWAP(x, y, t) ( (t)=(x), (x)=(y), (y)=(t) )
#define MAX_QUEUE_SIZE DATA_NUM+1
void selection_sort(int list[], int n)
{
	int i, j, least, temp;
	for (i = 0; i < n - 1; i++) {
		least = i;
		for (j = i + 1; j < n; j++) { 			// 최솟값 탐색
			if (list[j] < list[least]) least = j;
		}
		SWAP(list[i], list[least], temp);
		for (j = 0; j < n; j++) {
			printf("%d ", list[j]);
		}
		printf("\n");
	}
}

void insertion_sort(int list[], int n)
{
	int i, j, key;
	for (i = 1; i < n; i++) {
		key = list[i];
		for (j = i - 1; j >= 0 && list[j] > key; j--)
			list[j + 1] = list[j]; 		// 레코드의 오른쪽 이동
		list[j + 1] = key;

		for (j = 0; j < n; j++) {
			printf("%d ", list[j]);
		}
		printf("\n");
	}
}

void bubble_sort(int list[], int n)
{
	int i, j, temp;
	for (i = n - 1; i > 0; i--) {
		for (j = 0; j < i; j++) 	// 앞뒤의 레코드를 비교한 후 교체
			if (list[j] > list[j + 1])
				SWAP(list[j], list[j + 1], temp);

		for (j = 0; j < n; j++) {
			printf("%d ", list[j]);
		}
		printf("\n");
	}
}

void inc_insertion_sort(int list[], int first, int last, int gap)
{
	int i, j, key;
	for (i = first + gap; i <= last; i = i + gap) {
		key = list[i];
		for (j = i - gap; j >= first && key < list[j]; j = j - gap)
			list[j + gap] = list[j];
		list[j + gap] = key;
	}
}

void inv_insertion_sort(int list[], int first, int last, int gap)
{
	int i, j, key;
	for (i = first + gap; i <= last; i = i + gap) {
		key = list[i];
		for (j = i - gap; j >= first && key > list[j]; j = j - gap)
			list[j + gap] = list[j];
		list[j + gap] = key;
	}
}
void shell_sort(int list[], int n)   // n = size
{
	int i, gap;
	for (gap = n / 2; gap > 0; gap = gap / 2) {
		if ((gap % 2) == 0) gap++;
		for (i = 0; i < gap; i++) {		// 부분 리스트의 개수는 gap
			inc_insertion_sort(list, i, n - 1, gap);
			for (int j = 0; j < n; j++) {
				printf("%d ", list[j]);
			}
			printf("\n");
		}
	}
}

int sorted[DATA_NUM]; // 추가 공간이 필요
// i는 정렬된 왼쪽리스트에 대한 인덱스
// j는 정렬된 오른쪽리스트에 대한 인덱스
// k는 정렬될 리스트에 대한 인덱스

void merge(int list[], int left, int mid, int right)
{
	int i, j, k, l;
	i = left; j = mid + 1; k = left;
	// 분할 정렬된 list의 합병
	while (i <= mid && j <= right) {
		if (list[i] <= list[j]) sorted[k++] = list[i++];
		else sorted[k++] = list[j++];
	}
	if (i > mid) 	// 남아 있는 레코드의 일괄 복사
		for (l = j; l <= right; l++)
			sorted[k++] = list[l];
	else 	// 남아 있는 레코드의 일괄 복사
		for (l = i; l <= mid; l++)
			sorted[k++] = list[l];
	// 배열 sorted[]의 리스트를 배열 list[]로 복사
	for (l = left; l <= right; l++)
		list[l] = sorted[l];
}

void inv_merge(int list[], int left, int mid, int right)
{
	int i, j, k, l;
	i = left; j = mid + 1; k = left;
	// 분할 정렬된 list의 합병
	while (i <= mid && j <= right) {
		if (list[i] >= list[j]) sorted[k++] = list[i++];
		else sorted[k++] = list[j++];
	}
	if (i > mid) 	// 남아 있는 레코드의 일괄 복사
		for (l = j; l <= right; l++)
			sorted[k++] = list[l];
	else 	// 남아 있는 레코드의 일괄 복사
		for (l = i; l <= mid; l++)
			sorted[k++] = list[l];
	// 배열 sorted[]의 리스트를 배열 list[]로 복사
	for (l = left; l <= right; l++)
		list[l] = sorted[l];
}

void merge_sort(int list[], int left, int right, int n)
{
	int mid;
	if (left < right)
	{
		mid = (left + right) / 2;              // 리스트의 균등분할
		merge_sort(list, left, mid, n);     // 부분리스트 정렬
		merge_sort(list, mid + 1, right, n);//부분리스트 정렬
		merge(list, left, mid, right);    // 합병
		for (int j = 0; j < n; j++) {
			printf("%d ", list[j]);
		}
		printf("\n");
	}
}

void inv_merge_sort(int list[], int left, int right, int n)
{
	int mid;
	if (left < right)
	{
		mid = (left + right) / 2;              // 리스트의 균등분할
		inv_merge_sort(list, left, mid, n);     // 부분리스트 정렬
		inv_merge_sort(list, mid + 1, right, n);//부분리스트 정렬
		inv_merge(list, left, mid, right);    // 합병
		for (int j = 0; j < n; j++) {
			printf("%d ", list[j]);
		}
		printf("\n");
	}
}

int partition(int list[], int left, int right, int n)
{
	int pivot, temp;
	int low, high;

	low = left;
	high = right + 1;
	pivot = list[left];
	do {
		do
			low++;
		while (low <= right && list[low] < pivot);
		do
			high--;
		while (high >= left && list[high] > pivot);
		if (low < high) {
			SWAP(list[low], list[high], temp);
			for (int j = 0; j < n; j++) {
				printf("%d ", list[j]);
			}
			printf("\n");
		}
	} while (low < high);
	
	SWAP(list[left], list[high], temp);
	for (int j = 0; j < n; j++) {
		printf("%d ", list[j]);
	}
	printf("\n");
	return high;
}

int inv_partition(int list[], int left, int right, int n)
{
	int pivot, temp;
	int low, high;

	low = left;
	high = right + 1;
	pivot = list[left];
	do {
		do
			low++;
		while (low <= right && list[low] > pivot);
		do
			high--;
		while (high >= left && list[high] < pivot);
		if (low < high) {
			SWAP(list[low], list[high], temp);
			for (int j = 0; j < n; j++) {
				printf("%d ", list[j]);
			}
			printf("\n");
		}
	} while (low < high);

	SWAP(list[left], list[high], temp);
	for (int j = 0; j < n; j++) {
		printf("%d ", list[j]);
	}
	printf("\n");
	return high;
}

void quick_sort(int list[], int left, int right, int n)
{
	if (left < right) {
		int q = partition(list, left, right, n);
		quick_sort(list, left, q - 1, n);
		quick_sort(list, q + 1, right, n);
		
	}
}

void inv_quick_sort(int list[], int left, int right, int n)
{
	if (left < right) {
		int q = inv_partition(list, left, right, n);
		inv_quick_sort(list, left, q - 1, n);
		inv_quick_sort(list, q + 1, right, n);

	}
}

#define BUCKETS 10
#define DIGITS 4

typedef int element;

typedef struct {

	element  queue[MAX_QUEUE_SIZE];

	int  front, rear;

} QueueType;



void error(const char *message)

{

	fprintf(stderr, "%s\n", message);

	exit(1);

}

// 초기화 함수

void init(QueueType *q)

{

	q->front = q->rear = 0;

}

// 공백 상태 검출 함수

int is_empty(QueueType *q)

{

	return (q->front == q->rear);

}

// 포화 상태 검출 함수

int is_full(QueueType *q)

{

	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);

}

// 삽입 함수

void enqueue(QueueType *q, element item)

{

	if (is_full(q))

		error("큐가 포화상태입니다");

	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;

	q->queue[q->rear] = item;

}

// 삭제 함수

element dequeue(QueueType *q)

{

	if (is_empty(q))

		error("큐가 공백상태입니다");

	q->front = (q->front + 1) % MAX_QUEUE_SIZE;

	return q->queue[q->front];

}

// 삭제 함수

element peek(QueueType *q)

{

	if (is_empty(q))

		error("큐가 공백상태입니다");

	return q->queue[(q->front + 1) % MAX_QUEUE_SIZE];

}
void radix_sort(int list[], int n)
{
	int i, b, d, factor = 1;
	QueueType queues[BUCKETS];

	for (b = 0; b < BUCKETS; b++) init(&queues[b]);	// 큐들의 초기화

	for (d = 0; d < DIGITS; d++) {
		for (int j = 0; j < n; j++) {
			printf("%d ", list[j]);
		}
		printf("\n");
		for (i = 0; i < n; i++)				// 데이터들을 자리수에 따라 큐에 입력
			enqueue(&queues[(list[i] / factor) % 10], list[i]);

		for (b = i = 0; b < BUCKETS; b++)			// 버켓에서 꺼내어 list로 합친다.
			while (!is_empty(&queues[b]))
				list[i++] = dequeue(&queues[b]);
		factor *= 10;				// 그 다음 자리수로 간다.
	}
	
}
void inv_radix_sort(int list[], int n)
{
	int i, b, d, factor = 1;
	QueueType queues[BUCKETS];

	for (b = 0; b < BUCKETS; b++) init(&queues[b]);	// 큐들의 초기화

	for (d = 0; d < DIGITS; d++) {
		for (int j = n-1; j >= 0; j--) {
			printf("%d ", list[j]);
		}
		printf("\n");
		for (i = 0; i < n; i++)				// 데이터들을 자리수에 따라 큐에 입력
			enqueue(&queues[(list[i] / factor) % 10], list[i]);

		for (b = i = 0; b < BUCKETS; b++)			// 버켓에서 꺼내어 list로 합친다.
			while (!is_empty(&queues[b]))
				list[i++] = dequeue(&queues[b]);
		factor *= 10;				// 그 다음 자리수로 간다.
	}

}

void swap(int list[], int a, int b) {
	int temp = list[a];
	list[a] = list[b];
	list[b] = temp;
}


void heapify(int list[], int n, int i) {
	int p = i;
	int l = i * 2 + 1;
	int r = i * 2 + 2;
	int temp;

	if (l < n && list[p] < list[l]) {
		p = l;
	}

	if (r < n && list[p] < list[r]) {
		p = r;
	}

	if (i != p) {
		swap(list, p, i);
		heapify(list, n, p);
	}
}

void inv_heapify(int list[], int n, int i) {
	int p = i;
	int l = i * 2 + 1;
	int r = i * 2 + 2;
	int temp;

	if (l < n && list[p] > list[l]) {
		p = l;
	}

	if (r < n && list[p] > list[r]) {
		p = r;
	}

	if (i != p) {
		swap(list, p, i);
		inv_heapify(list, n, p);
	}
}

void heap_sort(int list[], int n) {

	// init, max heap
	for (int i = n / 2 - 1; i >= 0; i--) {
		heapify(list, n, i);
	}

	// for extract max element from heap
	for (int i = n - 1; i > 0; i--) {
		swap(list, 0, i);
		heapify(list, i, 0);
		for (int j = 0; j < n; j++) {
			printf("%d ", list[j]);
		}
		printf("\n");
	}
}

void inv_heap_sort(int list[], int n) {

	// init, max heap
	for (int i = n / 2 - 1; i >= 0; i--) {
		inv_heapify(list, n, i);
	}

	// for extract max element from heap
	for (int i = n - 1; i > 0; i--) {
		swap(list, 0, i);
		inv_heapify(list, i, 0);
		for (int j = 0; j < n; j++) {
			printf("%d ", list[j]);
		}
		printf("\n");
	}
}

void menu()
{
	printf("\n-sorting menu-\n");
	printf(" s(선택정렬)\n i(삽입정렬)\n b(버블정렬)\n m(합병정렬)\n h(히프정렬)\n q(퀵정렬)\n r(기수정렬)\n l(쉘정렬)");
	printf("\n---------------\n");
}

void smenu()
{
	printf("\n-sorting order-\n");
	printf("1(오름차순)\n2(내림차순)");
	printf("\n---------------\n");
}

void main(int argc, char* argv[])
{
	FILE* fp;
	int num_data;
	int* data;
	int i, j;
	char cmd, str[64], order_cmd;

	if (argc == 2) {
		fp = fopen(argv[1], "r");
		fscanf(fp, "%d", &num_data);
		data = (int*)malloc(sizeof(int) * num_data);
		for (i = 0; i < num_data; i++)
			fscanf(fp, "%d", &data[i]);
		fclose(fp);
	}
	else {
		printf("Enter the number to be sorted in line by line(at most 50 lines)\n");
		data = (int*)malloc(sizeof(int) * DATA_NUM);
		num_data = 0;
		do {
			gets_s(str, 64);
			if (str == NULL || strcmp(str, "=") == 0) break;
			else data[num_data++] = atoi(str);
		} while (str != NULL);
	}
	printf("Input data:\n");		// unsorted data
	for (i = 0; i < num_data; i++)
		printf("%d ", data[i]);
	printf("\n");

	menu();
	cmd = getchar();
	getchar();		// 엔터키제거
	if (cmd == 'x') {
		printf("Exit...\n");
		return;
	}
	smenu();
	order_cmd = getchar();
	getchar();		// 엔터키제거

	switch (cmd) {
	case 's': 
		printf("selection sort with %s order\n", (order_cmd == '1' ? "오름차순" : "내림차순"));
		if (order_cmd == '1') {
			
			selection_sort(data, num_data); // 선택정렬 호출
			
			printf("\n");
			printf("결과!\n");
			for (i = 0; i < num_data; i++)
				printf("%d ", data[i]);
			printf("\n");
			break;
		}
		if (order_cmd == '2') {
			int i, j, least, temp;
			for (i = 0; i < num_data - 1; i++) {
				least = i;
				for (j = i + 1; j < num_data; j++) { 		
					if (data[j] > data[least]) least = j;
				}
				SWAP(data[i], data[least], temp);
				for (j = 0; j < num_data; j++) {
					printf("%d ", data[j]);
				}
				printf("\n");
			}
			
			
			printf("\n");
			printf("결과!\n");
			for (i = 0; i < num_data; i++)
				printf("%d ", data[i]);
			printf("\n");
			break;
		}
		break;
	case 'i': 
		printf("insertion sort with %s order\n", (order_cmd == '1' ? "오름차순" : "내림차순"));
		if (order_cmd == '1') {

			insertion_sort(data, num_data); 

			printf("\n");
			printf("결과!\n");
			for (i = 0; i < num_data; i++)
				printf("%d ", data[i]);
			printf("\n");
			break;
		}
		if (order_cmd == '2') {
			int i, j, key;
			for (i = 1; i < num_data; i++) {
				key = data[i];
				for (j = i - 1; j >= 0 && data[j] < key; j--)
					data[j + 1] = data[j]; 		// 레코드의 오른쪽 이동
				data[j + 1] = key;

				for (j = 0; j < num_data; j++) {
					printf("%d ", data[j]);
				}
				printf("\n");
			}

			printf("\n");
			printf("결과!\n");
			for (i = 0; i < num_data; i++)
				printf("%d ", data[i]);
			printf("\n");
			break;
		}
		break;
	case 'b':
		printf("bubble sort with %s order\n", (order_cmd == '1' ? "오름차순" : "내림차순"));
		if (order_cmd == '1') {

			bubble_sort(data, num_data); 

			printf("\n");
			printf("결과!\n");
			for (i = 0; i < num_data; i++)
				printf("%d ", data[i]);
			printf("\n");
			break;
		}
		if (order_cmd == '2') {
			int i, j, temp;
			for (i = num_data - 1; i > 0; i--) {
				for (j = 0; j < i; j++) 	// 앞뒤의 레코드를 비교한 후 교체
					if (data[j] < data[j + 1])
						SWAP(data[j], data[j + 1], temp);

				for (j = 0; j < num_data; j++) {
					printf("%d ", data[j]);
				}
				printf("\n");
			}
			printf("\n");
			printf("결과!\n");
			for (i = 0; i < num_data; i++)
				printf("%d ", data[i]);
			printf("\n");
			break;
		}
		break;
	case 'l':
		printf("Shell sort with %s order\n", (order_cmd == '1' ? "오름차순" : "내림차순"));
		if (order_cmd == '1') {

			shell_sort(data, num_data); 

			printf("\n");
			printf("결과!\n");
			for (i = 0; i < num_data; i++)
				printf("%d ", data[i]);
			printf("\n");
			break;
		}
		if (order_cmd == '2') {
			int i, gap;
			for (gap = num_data / 2; gap > 0; gap = gap / 2) {
				if ((gap % 2) == 0) gap++;
				for (i = 0; i < gap; i++) {		// 부분 리스트의 개수는 gap
					inv_insertion_sort(data, i, num_data - 1, gap);
					for (int j = 0; j < num_data; j++) {
						printf("%d ", data[j]);
					}
					printf("\n");
				}
			}
			printf("\n");
			printf("결과!\n");
			for (i = 0; i < num_data; i++)
				printf("%d ", data[i]);
			printf("\n");
			break;
		}
		break;
	case 'm':
		printf("merge sort with %s order\n", (order_cmd == '1' ? "오름차순" : "내림차순"));
		if (order_cmd == '1') {

			merge_sort(data, 0, num_data-1, num_data); 

			printf("\n");
			printf("결과!\n");
			for (i = 0; i < num_data; i++)
				printf("%d ", data[i]);
			printf("\n");
			break;
		}
		if (order_cmd == '2') {

			inv_merge_sort(data, 0, num_data - 1, num_data);

			printf("\n");
			printf("결과!\n");
			for (i = 0; i < num_data; i++)
				printf("%d ", data[i]);
			printf("\n");
			break;
		}
		break;
	case 'q':
		printf("quick sort with %s order\n", (order_cmd == '1' ? "오름차순" : "내림차순"));
		if (order_cmd == '1') {

			quick_sort(data, 0, num_data - 1, num_data); 

			printf("\n");
			printf("결과!\n");
			for (i = 0; i < num_data; i++)
				printf("%d ", data[i]);
			printf("\n");
			break;
		}
		if (order_cmd == '2') {

			inv_quick_sort(data, 0, num_data - 1, num_data);

			printf("\n");
			printf("결과!\n");
			for (i = 0; i < num_data; i++)
				printf("%d ", data[i]);
			printf("\n");
			break;
		}
		break;
	case 'r':
		printf("radix sort with %s order\n", (order_cmd == '1' ? "오름차순" : "내림차순"));
		if (order_cmd == '1') {

			radix_sort(data, num_data); 

			printf("\n");
			printf("결과!\n");
			for (i = 0; i < num_data; i++)
				printf("%d ", data[i]);
			printf("\n");
			break;
		}
		if (order_cmd == '2') {

			inv_radix_sort(data, num_data);

			printf("\n");
			printf("결과!\n");
			for (i = num_data-1; i >= 0 ; i--)
				printf("%d ", data[i]);
			printf("\n");
			break;
		}
		break;
	case 'h':
		printf("heap sort with %s order\n", (order_cmd == '1' ? "오름차순" : "내림차순"));
		if (order_cmd == '1') {

			heap_sort(data, num_data); 

			printf("\n");
			printf("결과!\n");
			for (i = 0; i < num_data; i++)
				printf("%d ", data[i]);
			printf("\n");
			break;
		}
		if (order_cmd == '2') {

			inv_heap_sort(data, num_data); 

			printf("\n");
			printf("결과!\n");
			for (i = 0; i < num_data; i++)
				printf("%d ", data[i]);
			printf("\n");
			break;
		}
		break;
	}

	_getch();
}