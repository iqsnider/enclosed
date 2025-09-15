#include <stdio.h>
#include <stdlib.h>

int main() {
	int total_nodes = 100;

	// initialize with triangle
	double shape[total_nodes][2];
	shape[0][0] = 0.0;
	shape[0][1] = 0.0;
	shape[1][0] = 1.0;
	shape[1][1] = 0.0;
	shape[2][0] = 0.5;
	shape[2][1] = 1.0;

	for (int i=0;i<total_nodes;i++){
		int random_number = rand() % (total_nodes + 1);
		double random_modifier = random_number*1.0f/(total_nodes*1.0f);

		printf("%.3f",random_modifier);
	}
}
