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

// Hàm s?p x?p t?ng dòng c?a ma tr?n theo th? t? t?ng d?n
void sortRows(int a[MAX_ROW][MAX_COL], int m, int n) {
	int i, j, k, temp;
	for (i = 0; i < m; i++) {
		// S? d?ng Bubble Sort ?? s?p x?p dòng i
		for (j = 0; j < n - 1; j++) {
			for (k = j + 1; k < n; k++) {
				if (a[i][j] > a[i][k]) {
					// Hoán ??i a[i][j] và a[i][k]
					temp = a[i][j];
					a[i][j] = a[i][k];
					a[i][k] = temp;
				}
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

	printf("\nS?p x?p các ph?n t? trong t?ng dòng theo th? t? t?ng d?n:\n");
	sortRows(a, m, n);
	printMatrix(a, m, n);

	return 0;
}
