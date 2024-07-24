#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100

// Hàm t?o ma tr?n vuông v?i các ph?n t? ng?u nhiên
void createSquareMatrix(int a[MAX_SIZE][MAX_SIZE], int n, int minVal, int maxVal) {
	int i, j;
	srand(time(0)); // Kh?i t?o seed cho s? ng?u nhiên
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			a[i][j] = minVal + rand() % (maxVal - minVal + 1);
		}
	}
}

// Hàm in ma tr?n vuông
void printSquareMatrix(int a[MAX_SIZE][MAX_SIZE], int n) {
	int i, j;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
}

// Hàm in các ph?n t? trên ???ng chéo chính
void printMainDiagonal(int a[MAX_SIZE][MAX_SIZE], int n) {
	int i;
	printf("Các ph?n t? trên ???ng chéo chính: ");
	for (i = 0; i < n; i++) {
		printf("%d ", a[i][i]);
	}
	printf("\n");
}

// Hàm in các ph?n t? trên các ???ng chéo song song v?i ???ng chéo chính
void printParallelDiagonals(int a[MAX_SIZE][MAX_SIZE], int n) {
	int i, j, k;

	// In các ???ng chéo phía trên ???ng chéo chính
	for (k = 1; k < n; k++) {
		printf("???ng chéo trên song song v?i ???ng chéo chính, cách %d ??n v?:\n", k);
		for (i = 0; i < n - k; i++) {
			j = i + k;
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}

	// In các ???ng chéo phía d??i ???ng chéo chính
	for (k = 1; k < n; k++) {
		printf("???ng chéo d??i song song v?i ???ng chéo chính, cách %d ??n v?:\n", k);
		for (j = 0; j < n - k; j++) {
			i = j + k;
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
}

int main() {
	int n, minVal, maxVal;
	int a[MAX_SIZE][MAX_SIZE];

	printf("Nh?p c?p c?a ma tr?n vuông (n >= 5): ");
	scanf("%d", &n);
	if (n < 5 || n > MAX
