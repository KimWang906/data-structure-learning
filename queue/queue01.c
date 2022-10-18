#include <stdio.h>
#include <stdlib.h>
#define MAX_Q_SIZE 5
typedef int element;

// 선형 Queue의 기본구조

//Queue 구조체 정의
typedef struct {
	int front;
	int rear;
	element data[MAX_Q_SIZE];
} Queue;

void error(char *message)
{
	printf("%s\n", message);
	exit(0); //메인함수 종료
}

void initQueue(Queue *q)
{
	q->front = q->rear = -1;
}

int isFull(Queue *q)
{
	return q->rear == MAX_Q_SIZE - 1;
}

int isEmpty(Queue *q)
{
	return q->front == q->rear;
}

void enQueue(Queue *q, element item)
{
	if (isFull(q))
		error("Queue is full");
	q->rear++; // rear가 가리키는 위치를 다음 위치로 이동
	q->data[q->rear] = item; // data[rear]에 item을 저장
}

element deQueue(Queue *q)
{
	if (isEmpty(q))
		error("Queue is empty");

	q->front++; // front가 가리키는 위치를 다음 위치로 이동
	return q->data[q->front]; // data[front]를 반환
}

void queuePrint(Queue *q)
{
	int i;
	for (i = 0; i < MAX_Q_SIZE; i++) {
		if (i <= q->front || i > q->rear) {
			printf(" | ");
		} else {
			printf("%d | ", q->data[i]);
		}
	}
	printf("\n");
}
int main()
{
	element item = 0;
	Queue q;
	initQueue(&q);
	enQueue(&q, 10);
	queuePrint(&q);
	enQueue(&q, 20);
	queuePrint(&q);
	enQueue(&q, 30);
	queuePrint(&q);
	item = deQueue(&q);
	queuePrint(&q);
	item = deQueue(&q);
	queuePrint(&q);
	return 0;
}