#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

// additive solving
double** solveShapeByAdding(int n, int m, double arr[n][m], double step_size){
	// initialize the result matrix
	double** result_matrix = malloc(n*sizeof(double));

	// for the initial triangle definition
	for (int i = n-4; i >= 0; i--){
		int random_number = rand() % (n + 1);
		double random_modifier = random_number*1.0f/(n*1.0f);
		double new_internal_angle = M_PI * random_modifier;

		// general location of added node, n-1 is location of the origin
		arr[i][0] = arr[n-1][0] + cos(new_internal_angle);
		arr[i][1] = arr[n-1][1] + sin(new_internal_angle);

		for (int j = i; j < n; j++){
			arr[j][0] += cos(new_internal_angle)/(n-i);
			arr[j][1] += sin(new_internal_angle)/(n-i);
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
	
	double** adding_result = solveShapeByAdding(total_nodes, 2, shape, 0.0001);
	print2Darray(total_nodes, 2, adding_result);

	free(adding_result);
	// for (int i=0;i<total_nodes;i++){
	// 	int random_number = rand() % (total_nodes + 1);
	// 	double random_modifier = random_number*1.0f/(total_nodes*1.0f);
	//
	// }

	return 0;
}
