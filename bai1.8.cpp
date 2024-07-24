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

// Hàm ki?m tra xem m?t s? có ph?i là s? ch?n hay không
int isEven(int num) {
	return num % 2 == 0;
}

// Hàm in các dòng ch? ch?a s? ch?n
void printEvenRows(int a[MAX_ROW][MAX_COL], int m, int n) {
	int i, j, isEvenRow;

	printf("Các dòng ch? ch?a s? ch?n:\n");
	for (i = 0; i < m; i++) {
		isEvenRow = 1; // Gi? s? dòng ch? ch?a s? ch?n
		for (j = 0; j < n; j++) {
			if (!isEven(a[i][j])) {
				isEvenRow = 0; // N?u tìm th?y s? l?, gán isEvenRow = 0
				break;
			}
		}
		if (isEvenRow) {
			// In dòng ch? ch?a s? ch?n
			for (j = 0; j < n; j++) {
				printf("%d ", a[i][j]);
			}
			printf("\n");
		}
	}
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

	printf("\nCác dòng ch? ch?a s? ch?n:\n");
	printEvenRows(a, m, n);

	return 0;
}
