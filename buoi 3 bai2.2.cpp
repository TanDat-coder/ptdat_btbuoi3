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

int main() {
	int n, minVal, maxVal;
	int a[MAX_SIZE][MAX_SIZE];

	printf("Nh?p c?p c?a ma tr?n vu�ng (n >= 5): ");
	scanf("%d", &n);
	if (n < 5 || n > MAX_SIZE) {
		printf("C?p c?a ma tr?n ph?i t? 5 ??n %d.\n", MAX_SIZE);
		return 1;
	}

	printf("Nh?p gi� tr? nh? nh?t (minVal): ");
	scanf("%d", &minVal);
	printf("Nh?p gi� tr? l?n nh?t (maxVal): ");
	scanf("%d", &maxVal);

	if (minVal > maxVal) {
		printf("Gi� tr? minVal ph?i nh? h?n ho?c b?ng maxVal.\n");
		return 1;
	}

	createSquareMatrix(a, n, minVal, maxVal);
	printf("Ma tr?n vu�ng v?a t?o:\n");
	printSquareMatrix(a, n);

	printf("\n");
	printMainDiagonal(a, n);

	return 0;
}
