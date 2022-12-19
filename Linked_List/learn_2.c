// 동적으로 구조체 생성하기
#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct Node {
    element data;
    struct Node *next; // 자기참조 구조체: 자신의 데이터형 타입으로 정의
} Node;

int main() {
    Node *n1, *n2, *n3, *ptr;
    n1 = (Node *)malloc(sizeof(Node));
    n2 = (Node *)malloc(sizeof(Node));
    n3 = (Node *)malloc(sizeof(Node));
    n1->data = 12;
    n1->next = n2;

    n2->data = 99;
    n2->next = n3;

    n3->data = 37;
    n3->next = NULL;

    ptr = n1;
    while (ptr) {
        if (ptr->next == NULL) // 만약 포인터가 가리키는 곳이 NULL일 경우
            printf("%d", ptr->data);
        else
            printf("%d->", ptr->data);
        ptr = ptr->next;
    }
}
