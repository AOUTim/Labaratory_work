#include "functions.h"

//вывод матрицы в консоль
void output_matrix(double** matrix, int matrix_size) {
	for (int i = 0; i < matrix_size; i++) {
		for (int j = 0; j < matrix_size; j++) {
			printf(" %g ", matrix[i][j]);
		}
		cout << endl;
	}
}
//вывод вектора на экран
void output_array(double* array, int array_size) {
	for (int i = 0; i < array_size; i++) {
		if (i % 10 == 0) printf("\n");
		printf("%g  ", array[i]);
	}
	printf("\n");
}
