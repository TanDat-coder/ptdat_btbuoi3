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

// Hàm tìm ph?n t? l?n nh?t trong tam giác trên c?a ???ng chéo chính
int findMaxAboveMainDiagonal(int a[MAX_SIZE][MAX_SIZE], int n) {
	int i, j;
	int maxVal = a[0][0]; // Kh?i t?o maxVal là ph?n t? ??u tiên trên ???ng chéo chính

	for (i = 0; i < n; i++) {
		for (j = i; j < n; j++) { // Duy?t t? c?t i ??n cu?i hàng
			if (a[i][j] > maxVal) {
				maxVal = a[i][j];
			}
		}
	}
	return maxVal;
}

int main() {
	int n, minVal, maxVal;
	int a[MAX_SIZE][MAX_SIZE];

	printf("Nh?p c?p c?a ma tr?n vuông (n >= 5): ");
	scanf("%d", &n);
	if (n < 5 || n > MAX_SIZE) {
		printf("C?p c?a ma tr?n ph?i t? 5 ??n %d.\n", MAX_SIZE);
		return 1;
	}

	printf("Nh?p giá tr? nh? nh?t (minVal): ");
	scanf("%d", &minVal);
	printf("Nh?p giá tr? l?n nh?t (maxVal): ");
	scanf("%d", &maxVal);

	if (minVal > maxVal) {
		printf("Giá tr? minVal ph?i nh? h?n ho?c b?ng maxVal.\n");
		return 1;
	}

	createSquareMatrix(a, n, minVal, maxVal);
	printf("Ma tr?n vuông v?a t?o:\n");
	printSquareMatrix(a, n);

	printf("\n");
	int maxAboveMainDiagonal = findMaxAboveMainDiagonal(a, n);
	printf("Ph?n t? l?n nh?t trong tam giác trên c?a ???ng chéo chính là: %d\n", maxAboveMainDiagonal);

	return 0;
}
