#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct Node {
    element data;
    struct Node *next;
} Node;

Node *insertFirst(Node *head, element data);
Node *insert(Node *head, Node *pre, element data);
Node *deleteFirst(Node *head);
Node *delete(Node *head, Node *pre);
void printList(Node *head);

// Code

int main() {
    Node *head = NULL;
    Node *temp = NULL;

    printf("[첫 위치 삽입]\n");
    for (int i = 0; i < 5; i++) {
        head = insertFirst(head, i); // 7. 첫위치에 i 삽입
        printList(head);
        if (i == 2)
            temp = head; // 데이터가 2인 노드 주소 저장
    }

    printf("[중간위치 삽입]\n");
    // 8. temp 다음 위치에 100 저장
    head = insert(head, temp, 100);
    printList(head);

    printf("[중간위치 삭제]\n");
    // 9. temp 다음위치 노드 삭제
    head = delete (head, temp);
    printList(head);

    printf("[첫 위치 삭제]\n");
    for (int i = 0; i < 5; i++) {
        // 10. 첫위치 노드 삭제
        head = deleteFirst(head);
        printList(head);
    }

    return 0;
}

// 처음으로 들어갈 노드를 삽입할 때 사용하는 함수
// 1. 동적할당으로 노드를 생성한다
// 2. 매개변수 data에 있는 값으로 새로 만들어진 노드의 data에 저장한다.
// 3. 매개변수 head에 있는 주소를 새로 만들어진 노드의 next에 저장한다.
// 4. newNode의 주소를 head에 저장한다.
// 5. 업데이트된 head의 주소를 반환한다.
Node *insertFirst(Node *head, element data) {
    Node *newNode = (Node *)malloc(sizeof(Node)); // 새로운 노드를 생성

    newNode->next = head; // 노드의 주소를 head에 저장
    newNode->data = data; // 새로운 노드의 데이터를 data에 저장
    head = newNode;       // head에 주소를 저장

    return head; // 업데이트된 노드의 주소를 반환
}

// 노드를 삽입할 때 사용하는 함수
// 1. 동적할당으로 노드를 생성한다
// 2. 매개변수 data에 있는 값으로 새로 만들어진 노드의 data에 저장한다.
// 3. 매개변수 head에 있는 주소를 새로 만들어진 노드의 next에 저장한다.
// 4. 매개변수 pre가 가진 next의 주소를 새로 만들어진 노드의 next에 저장한다.
// 5. 매개변수 pre가 가진 next에 새로 만들어진 노드를 저장한다.
// 6. 업데이트된 head의 주소를 반환한다.
Node *insert(Node *head, Node *pre, element data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = head;
    newNode->next = pre->next;
    pre->next = newNode;

    return head;
}

// 첫 위치의 노드를 삭제하는 함수
// 1. head의 주소를 가진 변수 removed를 생성한다.
// 2. head에 next의 주소를 저장한다.
// 3. removed(head)가 가리키고 있는 위치의 노드의 동적할당을 해제한다.
// 4. 노드가 있었던 위치에 쓰레기값이 남지 않도록 NULL로 변경한다.
// 5. 업데이트된 head의 주소를 반환한다.
Node *deleteFirst(Node *head) {
    Node *removed = head;

    head = head->next;
    free(removed);
    removed = NULL;

    return head;
}

// 매개변수 pre가 가리키는 다음 노드의 주소를 삭제하는 함수
// 1. pre가 가리키는 next의 주소를 가진 변수 removed를 생성한다.
// 2. pre가 가리키는 next의 주소를 removed의 next로 변경하여
//    pre->next->next의 주소를 가리키게끔 한다.
// 3. removed(pre->next)가 가리키고 있는 위치의 노드의 동적할당을 해제한다.
// 4. 노드가 있었던 위치에 쓰레기값이 남지 않도록 NULL로 변경한다.
// 5. 업데이트된 head의 주소를 반환한다.
Node *delete(Node *head, Node *pre) {
    Node *removed = pre->next;

    pre->next = removed->next; // pre->next = pre->next->next
    free(removed);
    removed = NULL;

    return head;
}

// head로부터 연결된 모든 노드를 출력하는 함수
void printList(Node *head) {
    Node *p = head;
    while (p != NULL) {
        printf("%d->", p->data);
        p = p->next; // 시험
    }
    // 6.head가 널이 아니면 노드데이터 출력
    printf("NULL\n");
}