#include <stdio.h>

#define MAX 100

void printMatrix(int matrix[MAX][MAX], int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}
}

void sortDiagonal(int matrix[MAX][MAX], int n) {
	// L?y c�c ph?n t? tr�n ???ng ch�o ch�nh
	int diagonal[MAX];
	for (int i = 0; i < n; i++) {
		diagonal[i] = matrix[i][i];
	}

	// S?p x?p c�c ph?n t? ???ng ch�o ch�nh
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (diagonal[i] > diagonal[j]) {
				int temp = diagonal[i];
				diagonal[i] = diagonal[j];
				diagonal[j] = temp;
			}
		}
	}

	// G�n l?i c�c ph?n t? ?� s?p x?p v�o ???ng ch�o ch�nh c?a ma tr?n
	for (int i = 0; i < n; i++) {
		matrix[i][i] = diagonal[i];
	}
}

int main() {
	int n;
	printf("Nh?p c?p c?a ma tr?n (n): ");
	scanf("%d", &n);

	int matrix[MAX][MAX];
	printf("Nh?p c�c ph?n t? c?a ma tr?n:\n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &matrix[i][j]);
		}
	}

	printf("Ma tr?n tr??c khi s?p x?p ???ng ch�o ch�nh:\n");
	printMatrix(matrix, n);

	sortDiagonal(matrix, n);

	printf("Ma tr?n sau khi s?p x?p ???ng ch�o ch�nh:\n");
	printMatrix(matrix, n);

	return 0;
}
