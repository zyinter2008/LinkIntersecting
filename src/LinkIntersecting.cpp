#include <iostream>
#include <stdio.h>
using namespace std;

struct Link {
	int data;
	Link *next;
};

void insertNode(Link *&head, Link *&tail, int data);
void buildLoopLink(Link *&head);
Link *existLoop(Link *head);

void buildCrossLink(Link *&headA, Link *&headB, Link *&tail);

int main() {
	Link *head = NULL;
//判断是否有环
	buildLoopLink(head);
	Link *loop = existLoop(head);
	if (NULL != loop) {
		cout << "Exist loop, value:" << loop->data << endl;
	}

//判断两个链表是否相交，简单场景，假设俩个链表均不带环
	Link *headA = NULL, *headB = NULL, *tail = NULL;
	buildCrossLink(headA, headB, tail);
	tail->next = headA;
	Link *loopAB = existLoop(headB);
	if (NULL != loopAB) {
		cout << "Two list cross, value:" << loopAB->data << endl;
	}

	return 0;
}

void buildLoopLink(Link *&head) {
	Link *tail = NULL;
	for (int i = 1; i <= 10; i++) {
		insertNode(head, tail, i);
	}
	tail->next = head;
	for (int i = 11; i <= 15; i++) {
		insertNode(head, tail, i);
	}
}

void insertNode(Link *&head, Link *&tail, int data) {
	Link *node = new Link;
	node->data = data;
	node->next = head;
	if (NULL == head) {
		tail = node;
	}
	head = node;
}

Link * existLoop(Link *head) {
	Link * fast, *slow;
	fast = slow = head;
	while (fast != NULL && fast->next != NULL) {
		fast = fast->next->next;
		slow = slow->next;
		if (slow == fast) {
			return slow;
		}
	}

	return NULL;
}

void buildCrossLink(Link *&headA, Link *&headB, Link *&tail) {
	Link *tailA = NULL, *tailB = NULL;
	Link *cross = NULL;
	for (int i = 1; i <= 10; i++) {
		insertNode(headA, tailA, i);
		if (i == 6) {
			cross = headA;
		}
	}
	tail = tailA;

	for (int i = 11; i <= 15; i++) {
		insertNode(headB, tailB, i);
	}
	tailB->next = cross;
}

