#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 10

typedef struct node {
	int number;
	char* name;
	struct node* next;
} node;

node* head = NULL;
node* tail = NULL;

int addNode() {
	int i = 0;
	if (tail != NULL)	i = tail->number;
	if (i == MAX_SIZE) {
		printf("오류: 연결리스트 최대 길이 도달\n");
		return 1;
	}
	char name_buffer[MAX_SIZE];
	printf("%d번째 학생 이름은: ", i + 1);
	fgets(name_buffer, MAX_SIZE, stdin);
	name_buffer[strcspn(name_buffer, "\n")] = 0;
	node* newnode = (node*)malloc(sizeof(node));
	if (newnode == NULL) {
		printf("메모리 할당 오류\n");
		return 0;
	}
	newnode->name = (char*)malloc(strlen(name_buffer) + 1);
	if (newnode->name == NULL) {
		free(newnode);
		printf("메모리 할당 오류\n");
		return 0;
	}
	strcpy_s(newnode->name, strlen(name_buffer) + 1, name_buffer);
	newnode->number = i + 1;
	newnode->next = NULL;

	if (head == NULL) head = newnode;
	else tail->next = newnode;
	tail = newnode;
	return 1;
}

int deleteNode() {
	if (head == NULL) {
		printf("리스트가 비어있습니다.\n");
		return 1;
	}
	int n;
	printf("삭제할 번호 입력: ");
	scanf_s("%d", &n);
	//입력버퍼 비우기
	while (getchar() != '\n');

	if (n < 1 || n > tail->number) {
		printf("오류: 없는 번호입니다.\n");
		return 1;
	}
	node* cur_prev = NULL;
	node* cur = head;
	while (cur != NULL) {
		if (cur->number == n) break;
		cur_prev = cur;
		cur = cur->next;
	}
	if (cur == NULL) {
		printf("오류: 해당 번호를 찾지 못했습니다.\n");
		return 1;
	}

	if (cur == head) head = cur->next;
	else cur_prev->next = cur->next;
	if (cur == tail) tail = cur_prev;
	printf("%d번 %s 학생 삭제됨.\n", n, cur->name);
	free(cur->name);
	free(cur);
	cur = (cur_prev == NULL) ? head : cur_prev->next;
	int current_num = n;
	while (cur != NULL) {
		cur->number = current_num++;
		cur = cur->next;
	}
	return 1;
}

void showNode() {
	if (head == NULL) {
		printf("리스트가 비어있습니다.\n");
		return;
	}
	node* cur = head;
	while (cur != NULL) {
		printf("%d번 학생: %s\n", cur->number, cur->name);
		cur = cur->next;
	}
}

int main() {
	int rep = 1;
	while (rep) {
		int todo = 0;
		printf("\n실행: [1] 추가 [2] 삭제 [3] 확인 [기타] 종료\n-> ");
		scanf_s("%d", &todo);
		//입력버퍼 비우기
		while (getchar() != '\n');
		switch (todo) {
		case 1:
			addNode();
			break;
		case 2:
			deleteNode();
			break;
		case 3:
			showNode();
			break;
		default:
			printf("종료합니다.\n");
			rep = 0;
			break;
		}
	}

	node* cur = head;
	while (cur != NULL) {
		node* temp = cur;
		cur = cur->next;
		free(temp->name);
		free(temp);
	}

	return 0;
}
