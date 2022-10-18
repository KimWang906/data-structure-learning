#include <stdlib.h>
#include <stdio.h>

/*
  선형 Queue의 문제점: Queue의 앞 부분이 비더라도 자료를 추가할 수 없으므로 메모리 낭비가 생긴다.
  --> 이를 원형 Queue를 이용하여 해결할 수 있다.

  원형 Queue의 원리 :
 
  초기 상태는 front, rear의 값이 0이고, 최대 Queue size는 MAX_Q_SIZE(n)로 정의한다.

  enqueue() 호출 시 rear 값에 (rear + 1) % n을 더한다.
  dequeue() 호출 시 front 값에 (front + 1) % n을 더한다.

  원형 Queue의 문제로는 full 상태와 empty 상태일 때 front와 rear 값이 같은 문제점이 발생한다.
  ==> 이를 해결하기 위해 front와 rear 사이에 하나의 공백을 두었다.
*/

#define MAX_Q_SIZE 5

typedef int element;
typedef struct {
	int rear;
	int front;
	element data[MAX_Q_SIZE];
} Queue;

void initQueue(Queue *q)
{
	//front, rear 초기화
	q->front = q->rear = 0;
}

int isEmpty(Queue *q)
{
	// front가 가리키는 위치와 rear가 가리키는 위치가 같을 경우
	return q->front == q->rear;
}

int isFull(Queue *q)
{
	// rear의 다음 위치(rear + 1)의 값이 front와 같을 경우
	return (q->rear + 1) % MAX_Q_SIZE == q->front;
}

void enQueue(Queue *q, element item)
{
	// Queue를 추가하기 전에 Queue가 가득 찼는지 검사를 진행합니다.
	if (isFull(q))
		printf("큐가 포화상태입니다.\n");
	else {
		q->rear++;
		q->data[q->rear % MAX_Q_SIZE] = item;
	}
}
element deQueue(Queue *q)
{
	// Queue를 제거하기 전에 Queue가 비었는지 검사를 진행합니다.
	if (isEmpty(q))
		printf("큐는 공백상태입니다.\n");
	else {
		q->front++;
		return q->data[q->front % MAX_Q_SIZE];
	}
}
void printQueue(Queue *q)
{
	int i;

	printf("QUEUE(front=%d rear=%d) = ", q->front, q->rear);

	if (isEmpty(q)) {
		printf("큐는 공백상태입니다.\n");

		return;
	}

	i = q->front;

	do {
		i = (i + 1) % (MAX_Q_SIZE);

		printf("%d | ", q->data[i]);

		if (i == q->rear)
			break;
	} while (i != q->front);

	printf("\n");
}

int main()
{
	Queue q;
	element item;

	initQueue(&q);

	printf("--데이터 추가 단계--\n");

	while (!isFull(&q)) {
		printf("정수를 입력하시오.");
		scanf("%d", &item);
		enQueue(&q, item);
		printQueue(&q);
	}

	printf("큐는 포화상태입니다.\n\n");
	printf("--데이터 삭제 단계--\n");

	while (!isEmpty(&q)) {
		item = deQueue(&q);
		printf("꺼내진 정수 : %d\n", item);
		printQueue(&q);
	}

	printf("큐는 공백상태입니다.\n\n");

	return 0;
}
