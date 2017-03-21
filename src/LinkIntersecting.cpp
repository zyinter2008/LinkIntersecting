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

int main() {
	Link *head = NULL;
	buildLoopLink(head);

	Link *loop = existLoop(head);
	if (NULL != loop) {
		cout << "Exist loop, value:" << loop->data << endl; // prints !!!Hello World!!!
	}

	return 0;
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
