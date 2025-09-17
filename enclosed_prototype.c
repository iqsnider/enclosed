#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

// iterative solving
double** solveShape(int n, int m, double arr[n][m],
		    double new_internal_angle, double step_size){
	double** result_matrix = malloc(n*sizeof(double));

	// general location of added node
	arr[0][0] = arr[n-1][0] + cos(new_internal_angle);
	arr[0][1] = arr[n-1][1] + sin(new_internal_angle);

	// solve for the new location of the node next to added node
	// such that all segments remain a length of 1
	for (double j = 0; j <= M_PI; j += step_size){
		double x = arr[0][0] + cos(new_internal_angle + j);
		double y = arr[0][1] + sin(new_internal_angle + j);

		// check the segment length
		double length_to_next_node = sqrt((x - arr[1][0])*(x - arr[1][0]) + (y - arr[1][1])*(y - arr[1][1]));
		if (length_to_next_node <= 1 + step_size && length_to_next_node >= 1 - step_size){
			arr[1][0] = x;
			arr[1][1] = y;
			break;
		}
	}
	
	for(int i = 0; i < n; i++){
		result_matrix[i] = malloc(m*sizeof(double*));
		memcpy(result_matrix[i], arr[i], m*sizeof(double));
	}

	return result_matrix;
}

// print all vertice coordinates
void print2Darray(int n, int m, double** arr) {
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			printf("%.3f ", arr[i][j]);
		}
		printf("\n");
	}
}

// Yay!
int main() {
	int total_nodes = 4;

	// initialize with triangle
	double shape[total_nodes][2];
	shape[total_nodes-1][0] = 0.0;
	shape[total_nodes-1][1] = 0.0;
	shape[total_nodes-2][0] = 1.0;
	shape[total_nodes-2][1] = 0.0;
	shape[total_nodes-3][0] = 0.5;
	shape[total_nodes-3][1] = sqrt(1 - shape[total_nodes-1][0]*shape[total_nodes-1][0]);

	double** result = solveShape(total_nodes, 2, shape, M_PI/4, 0.1);
	print2Darray(total_nodes, 2, result);

	// for (int i=0;i<total_nodes;i++){
	// 	int random_number = rand() % (total_nodes + 1);
	// 	double random_modifier = random_number*1.0f/(total_nodes*1.0f);
	//
	// }

	return 0;
}
