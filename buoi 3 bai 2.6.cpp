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
	// L?y các ph?n t? trên ???ng chéo chính
	int diagonal[MAX];
	for (int i = 0; i < n; i++) {
		diagonal[i] = matrix[i][i];
	}

	// S?p x?p các ph?n t? ???ng chéo chính
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (diagonal[i] > diagonal[j]) {
				int temp = diagonal[i];
				diagonal[i] = diagonal[j];
				diagonal[j] = temp;
			}
		}
	}

	// Gán l?i các ph?n t? ?ã s?p x?p vào ???ng chéo chính c?a ma tr?n
	for (int i = 0; i < n; i++) {
		matrix[i][i] = diagonal[i];
	}
}

int main() {
	int n;
	printf("Nh?p c?p c?a ma tr?n (n): ");
	scanf("%d", &n);

	int matrix[MAX][MAX];
	printf("Nh?p các ph?n t? c?a ma tr?n:\n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &matrix[i][j]);
		}
	}

	printf("Ma tr?n tr??c khi s?p x?p ???ng chéo chính:\n");
	printMatrix(matrix, n);

	sortDiagonal(matrix, n);

	printf("Ma tr?n sau khi s?p x?p ???ng chéo chính:\n");
	printMatrix(matrix, n);

	return 0;
}
