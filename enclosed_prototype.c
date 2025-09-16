#include <stdio.h>
#include <stdlib.h>


// double** solveShape(int n, int m, int arr[n][m]){
//
// }

void print2Darray(int n, int m, double arr[n][m]) {
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			printf("%.3f ", arr[i][j]);
		}
		printf("\n");
	}
}

int main() {
	int total_nodes = 4;

	// initialize with triangle
	double shape[total_nodes][2];
	shape[0][0] = 0.0;
	shape[0][1] = 0.0;
	shape[1][0] = 1.0;
	shape[1][1] = 0.0;
	shape[2][0] = 0.5;
	shape[2][1] = 1.0;

	print2Darray(total_nodes, 2, shape);

	// for (int i=0;i<total_nodes;i++){
	// 	int random_number = rand() % (total_nodes + 1);
	// 	double random_modifier = random_number*1.0f/(total_nodes*1.0f);
	//
	// }
}
