#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// general segment definition
struct Segment {
	double *p1;
	double *p2;
};

// node for linked-list
struct Node {
	void *this_node;
	struct Node *next;
};

// Problem properties. Currently includes:
// 1. total number of nodes that need to be filled
// 2. dynamic array for filling segments
// 3. dynamic array for filling nodes
struct properties {
	int total_nodes;
	struct Segment *seg_list;
	struct Node *node_list;
};

int main() {

	struct properties shape;
	shape.total_nodes = 3;

	for (int i = 0; i < shape.total_nodes; i++){
		printf("Hello");
	}

}
