#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// node for linked-list
struct Node {
	void *this_node;
	struct Node *next;
};

// general segment definition
struct Segment {
	struct Node *p1;
	struct Node *p2;
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

	struct Node *a_node = malloc(sizeof(struct Node));

	double tmp_point[2] = {0, 0};
	double *target_array = malloc(2*sizeof(double));
	memcpy(target_array, tmp_point, 2*sizeof(double));

	a_node->this_node = target_array;

	free(a_node->this_node);
	free(a_node);

	return 0;
}
