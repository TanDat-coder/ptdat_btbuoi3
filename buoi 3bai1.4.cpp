#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROW 100
#define MAX_COL 100

// Hàm t?o ma tr?n v?i các ph?n t? ng?u nhiên
void createMatrix(int a[MAX_ROW][MAX_COL], int m, int n, int minVal, int maxVal) {
	int i, j;
	srand(time(0)); // Kh?i t?o seed cho s? ng?u nhiên
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			a[i][j] = minVal + rand() % (maxVal - minVal + 1);
		}
	}
}

// Hàm in ma tr?n
void printMatrix(int a[MAX_ROW][MAX_COL], int m, int n) {
	int i, j;
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
}

// Hàm in các ph?n t? thu?c ???ng biên
void printBorders(int a[MAX_ROW][MAX_COL], int m, int n) {
	int i, j;

	// ???ng biên trên
	printf("???ng biên trên: ");
	for (j = 0; j < n; j++) {
		printf("%d ", a[0][j]);
	}
	printf("\n");

	// ???ng biên d??i
	printf("???ng biên d??i: ");
	for (j = 0; j < n; j++) {
		printf("%d ", a[m - 1][j]);
	}
	printf("\n");

	// ???ng biên trái (tr? ph?n t? góc)
	printf("???ng biên trái: ");
	for (i = 1; i < m - 1; i++) {
		printf("%d ", a[i][0]);
	}
	printf("\n");

	// ???ng biên ph?i (tr? ph?n t? góc)
	printf("???ng biên ph?i: ");
	for (i = 1; i < m - 1; i++) {
		printf("%d ", a[i][n - 1]);
	}
	printf("\n");
}

int main() {
	int m, n, minVal, maxVal;
	int a[MAX_ROW][MAX_COL];

	printf("Nh?p s? dòng (m): ");
	scanf("%d", &m);
	printf("Nh?p s? c?t (n): ");
	scanf("%d", &n);
	printf("Nh?p giá tr? nh? nh?t (minVal): ");
	scanf("%d", &minVal);
	printf("Nh?p giá tr? l?n nh?t (maxVal): ");
	scanf("%d", &maxVal);

	if (m <= 0 || n <= 0 || m > MAX_ROW || n > MAX_COL) {
		printf("Kích th??c ma tr?n không h?p l?.\n");
		return 1;
	}

	if (minVal > maxVal) {
		printf("Giá tr? minVal ph?i nh? h?n ho?c b?ng maxVal.\n");
		return 1;
	}

	createMatrix(a, m, n, minVal, maxVal);
	printf("Ma tr?n v?a t?o:\n");
	printMatrix(a, m, n);

	printf("\nCác ph?n t? thu?c các ???ng biên:\n");
	printBorders(a, m, n);

	return 0;
}
