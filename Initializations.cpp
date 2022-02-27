#include "header_main.h"
using namespace std;

void initialization(double* array_A, double* array_B, int array_size_1, int array_size_2, double** matrix_A, double** matrix_B, int matrix_size) {
	for (int i = 0; i < matrix_size; i++)
		for (int j = 0; j < matrix_size; j++) {
			matrix_A[i][j] = rand() % 255 - 100;
			matrix_B[i][j] = rand() % 255 - 200;
		}
	for (int i = 0; i < array_size_1; i++)
		array_A[i] = i + rand() % 255 - i * rand() % 255;
	for (int i = 0; i < array_size_2; i++)
		array_B[i] = i + i * rand() % 255 - rand() % 255;
}
