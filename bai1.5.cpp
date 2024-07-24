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

// Hàm ki?m tra xem m?t ph?n t? có ph?i là c?c ??i hay không
int isLocalMaxima(int a[MAX_ROW][MAX_COL], int m, int n, int i, int j) {
	int current = a[i][j];
	if ((i > 0 && current < a[i - 1][j]) ||  // Ki?m tra ph?n t? phía trên
		(i < m - 1 && current < a[i + 1][j]) ||  // Ki?m tra ph?n t? phía d??i
		(j > 0 && current < a[i][j - 1]) ||  // Ki?m tra ph?n t? bên trái
		(j < n - 1 && current < a[i][j + 1]))  // Ki?m tra ph?n t? bên ph?i
	{
		return 0;  // Không ph?i c?c ??i
	}
	return 1;  // Là c?c ??i
}

// Hàm in các ph?n t? c?c ??i
void printLocalMaxima(int a[MAX_ROW][MAX_COL], int m, int n) {
	int i, j;
	printf("Các ph?n t? c?c ??i:\n");
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			if (isLocalMaxima(a, m, n, i, j)) {
				printf("%d t?i v? trí (%d, %d)\n", a[i][j], i, j);
			}
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

	printf("\nCác ph?n t? c?c ??i trong ma tr?n:\n");
	printLocalMaxima(a, m, n);

	return 0;
}
