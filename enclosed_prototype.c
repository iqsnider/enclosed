#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

// iterative solving and 2D array memory allocator
double** solveShape(int n, int m, double arr[n][m],
		    double new_internal_angle, double tolerance){
	double** result_matrix = malloc(n*sizeof(double));
	for(int i = 0; i < n; i++){
		result_matrix[i] = malloc(m*sizeof(double));
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
	shape[0][0] = 0.0;
	shape[0][1] = 0.0;
	shape[1][0] = 1.0;
	shape[1][1] = 0.0;
	shape[2][0] = 0.5;
	shape[2][1] = sqrt(shape[2][0]*shape[2][0] + 1);

	double** result = solveShape(total_nodes, 2, shape, M_PI, 0.0000001);
	print2Darray(total_nodes, 2, result);

	// for (int i=0;i<total_nodes;i++){
	// 	int random_number = rand() % (total_nodes + 1);
	// 	double random_modifier = random_number*1.0f/(total_nodes*1.0f);
	//
	// }

	return 0;
}
