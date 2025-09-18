#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

// iterative solving
double** solveShapeByIterating(int n, int m, double arr[n][m],
		    double new_internal_angle, double step_size){
	// initialize the result matrix
	double** result_matrix = malloc(n*sizeof(double));

	// iterate through all empty nodes, last three nodes are reserved
	// for the initial triangle definition
	for (int i = n-4; i >= 0; i--){
		// general location of added node, n-1 is location of the origin
		arr[i][0] = arr[n-1][0] + cos(new_internal_angle);
		arr[i][1] = arr[n-1][1] + sin(new_internal_angle);

		// solve the locations of all nodes after the added node
		// such that all segments remain a length of 1
		for (int j = i; j < n; j++){
			// sweep and check validity of node location
			for (double k = 0; k <= M_PI; k += step_size){
				double x = arr[j][0] + cos(new_internal_angle + k);
				double y = arr[j][1] + sin(new_internal_angle + k);

				// check the segment length
				double length_to_next_node = sqrt((x - arr[j+1][0])*(x - arr[j+1][0]) + (y - arr[j+1][1])*(y - arr[j+1][1]));
				if (length_to_next_node <= 1 + step_size && length_to_next_node >= 1 - step_size){
					arr[j+1][0] = x;
					arr[j+1][1] = y;
					break;
				}

				// // step_size resolution catch case
				// if (k > M_PI - step_size && k < M_PI + step_size){
				// 	double x = arr[j][0] + cos(new_internal_angle);
				// 	double y = arr[j][1] + sin(new_internal_angle);
				// 	arr[j+1][0] = x;
				// 	arr[j+1][1] = y;
				// }
			}
		}
	}
	
	// copy augmented matrix into result_matrix
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
	int total_nodes = 8;

	// initialize with triangle
	double shape[total_nodes][2];
	shape[total_nodes-1][0] = 0.0;
	shape[total_nodes-1][1] = 0.0;
	shape[total_nodes-2][0] = 0.5;
	shape[total_nodes-2][1] = sqrt(1 - shape[total_nodes-2][0]*shape[total_nodes-2][0]);
	shape[total_nodes-3][0] = 1.0;
	shape[total_nodes-3][1] = 0.0;
	
	double** iterating_result = solveShapeByIterating(total_nodes, 2, shape, M_PI/4, 0.0001);
	print2Darray(total_nodes, 2, iterating_result);

	free(iterating_result);
	// for (int i=0;i<total_nodes;i++){
	// 	int random_number = rand() % (total_nodes + 1);
	// 	double random_modifier = random_number*1.0f/(total_nodes*1.0f);
	//
	// }

	return 0;
}
