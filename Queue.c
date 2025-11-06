#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 6 // 실제로는 n-1개까지 저장 가능

//문자열 배열 구조체, 큐 구조체 선언
typedef struct {
  char str[MAX_SIZE];
} str;
typedef struct {
  int front;
  int rear;
  str* data[MAX_SIZE];
} Queue;

//입력버퍼 초기화 함수
void clearInputBuffer(void) {
  int c;
  while ((c = getchar()) != '\n' && c != EOF);
}

//큐 기본함수
void init(Queue* queue) {
  queue->front = 0;
  queue->rear = 0;
  for (int i = 0; i < MAX_SIZE; i++) queue->data[i] = (str*)malloc(sizeof(str));
}
int isEmpty(Queue* queue) { return queue->front == queue->rear; }
int isFull(Queue* queue) { return (queue->rear + 1) % MAX_SIZE == queue->front; }
void enqueue(Queue* queue) {
  if (isFull(queue)) {
    printf("Queue is full.\n");
    return;
  }
  queue->rear = (queue->rear + 1) % MAX_SIZE;
  getchar(); //입력버퍼 개행문자 삭제
  printf("입력: ");
  fgets(queue->data[queue->rear]->str, MAX_SIZE, stdin);
  if (strchr(queue->data[queue->rear]->str, '\n') == NULL) clearInputBuffer();
  queue->data[queue->rear]->str[strcspn(queue->data[queue->rear]->str, "\n")] = '\0';
}
char* dequeue(Queue* queue) {
  if (isEmpty(queue)) {
    printf("Queue is empty.\n");
    return NULL;
  }
  queue->front = (queue->front + 1) % MAX_SIZE;
  return queue->data[queue->front]->str;
}
void display(Queue* queue) {
  if (isEmpty(queue)) {
    printf("Queue is empty.\n");
    return;
  }
  printf("rear=%d, front=%d\nQueue 내용: ", queue->rear, queue->front);
  int i = (queue->front + 1) % MAX_SIZE;
  while (i != (queue->rear + 1) % MAX_SIZE) {
    printf("%s ", queue->data[i]->str);
    i = (i + 1) % MAX_SIZE;
  }
  printf("\n");
}

int main() {
  Queue* queue = (Queue*)malloc(sizeof(Queue));
  init(queue);
  int rep = 1, execute = 0;
  while (rep) {
    printf("실행: [1] enqueue [2] dequeue [3] display [0] quit\n");
    int result = scanf("%d", &execute);
    if (result != 1) {
      printf("숫자를 입력해주세요.\n");
      clearInputBuffer();
      continue;
    }
    switch (execute) {
    case 1:
      enqueue(queue);
      break;
    case 2: {
      char* val = dequeue(queue);
      if (val) printf("data: %s\n", val);
      break;
    }
    case 3:
      display(queue);
      break;
    case 0:
      rep = 0;
      break;
    default:
      printf("잘못된 입력입니다.\n");
      break;
    }
  }

  //할당한 메모리 해제
  for (int i = 0; i < MAX_SIZE; i++) free(queue->data[i]);
  free(queue);
  return 0;
}
