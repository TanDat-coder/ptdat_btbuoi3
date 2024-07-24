#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100

// H�m t?o ma tr?n vu�ng v?i c�c ph?n t? ng?u nhi�n
void createSquareMatrix(int a[MAX_SIZE][MAX_SIZE], int n, int minVal, int maxVal) {
	int i, j;
	srand(time(0)); // Kh?i t?o seed cho s? ng?u nhi�n
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			a[i][j] = minVal + rand() % (maxVal - minVal + 1);
		}
	}
}

// H�m in ma tr?n vu�ng
void printSquareMatrix(int a[MAX_SIZE][MAX_SIZE], int n) {
	int i, j;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
}

// H�m in c�c ph?n t? tr�n ???ng ch�o ch�nh
void printMainDiagonal(int a[MAX_SIZE][MAX_SIZE], int n) {
	int i;
	printf("C�c ph?n t? tr�n ???ng ch�o ch�nh: ");
	for (i = 0; i < n; i++) {
		printf("%d ", a[i][i]);
	}
	printf("\n");
}

// H�m in c�c ph?n t? tr�n c�c ???ng ch�o song song v?i ???ng ch�o ch�nh
void printParallelDiagonals(int a[MAX_SIZE][MAX_SIZE], int n) {
	int i, j, k;

	// In c�c ???ng ch�o ph�a tr�n ???ng ch�o ch�nh
	for (k = 1; k < n; k++) {
		printf("???ng ch�o tr�n song song v?i ???ng ch�o ch�nh, c�ch %d ??n v?:\n", k);
		for (i = 0; i < n - k; i++) {
			j = i + k;
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}

	// In c�c ???ng ch�o ph�a d??i ???ng ch�o ch�nh
	for (k = 1; k < n; k++) {
		printf("???ng ch�o d??i song song v?i ???ng ch�o ch�nh, c�ch %d ??n v?:\n", k);
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

	printf("Nh?p c?p c?a ma tr?n vu�ng (n >= 5): ");
	scanf("%d", &n);
	if (n < 5 || n > MAX
