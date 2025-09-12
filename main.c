#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
	void *this_node;
	struct Node *next;
};

int main() {
	struct Node *head = NULL;

	for (int i = 0; i < 6; i++){
		struct Node *newNode = malloc(sizeof(struct Node));
		newNode->this_node = malloc(sizeof(i));
		memcpy(newNode->this_node, &i, sizeof(i));

		newNode->next = head;
		head = newNode;
	}


	while (head) {
		printf("%d", *(int*) head->this_node);
		head = head->next;
	};
}
