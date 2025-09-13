#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// a basic point
struct Point {
	double x, y;
};

// a basic segment
struct Segment {
	struct Point p1;
	struct Point p2;
};

// a function for stochastically generating the next point
struct Point stochasticPoint(struct Point p) {
	int xrn = rand();
	int yrn = rand();

	struct Point next_point = {xrn, yrn};

	return next_point;
}

struct Properties {
	int total_nodes;
};

int main() {
	struct Properties shape;
	shape.total_nodes = 3;
	
	struct Point point_list[shape.total_nodes];

	for (int i = 0; i < shape.total_nodes; i++){
	}

}
