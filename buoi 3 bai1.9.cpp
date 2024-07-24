#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROW 100
#define MAX_COL 100

// H�m t?o ma tr?n v?i c�c ph?n t? ng?u nhi�n
void createMatrix(int a[MAX_ROW][MAX_COL], int m, int n, int minVal, int maxVal) {
	int i, j;
	srand(time(0)); // Kh?i t?o seed cho s? ng?u nhi�n
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			a[i][j] = minVal + rand() % (maxVal - minVal + 1);
		}
	}
}

// H�m in ma tr?n
void printMatrix(int a[MAX_ROW][MAX_COL], int m, int n) {
	int i, j;
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
}

// H�m s?p x?p t?ng d�ng c?a ma tr?n theo th? t? t?ng d?n
void sortRows(int a[MAX_ROW][MAX_COL], int m, int n) {
	int i, j, k, temp;
	for (i = 0; i < m; i++) {
		// S? d?ng Bubble Sort ?? s?p x?p d�ng i
		for (j = 0; j < n - 1; j++) {
			for (k = j + 1; k < n; k++) {
				if (a[i][j] > a[i][k]) {
					// Ho�n ??i a[i][j] v� a[i][k]
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

	printf("Nh?p s? d�ng (m): ");
	scanf("%d", &m);
	printf("Nh?p s? c?t (n): ");
	scanf("%d", &n);
	printf("Nh?p gi� tr? nh? nh?t (minVal): ");
	scanf("%d", &minVal);
	printf("Nh?p gi� tr? l?n nh?t (maxVal): ");
	scanf("%d", &maxVal);

	if (m <= 0 || n <= 0 || m > MAX_ROW || n > MAX_COL) {
		printf("K�ch th??c ma tr?n kh�ng h?p l?.\n");
		return 1;
	}

	if (minVal > maxVal) {
		printf("Gi� tr? minVal ph?i nh? h?n ho?c b?ng maxVal.\n");
		return 1;
	}

	createMatrix(a, m, n, minVal, maxVal);
	printf("Ma tr?n v?a t?o:\n");
	printMatrix(a, m, n);

	printf("\nS?p x?p c�c ph?n t? trong t?ng d�ng theo th? t? t?ng d?n:\n");
	sortRows(a, m, n);
	printMatrix(a, m, n);

	return 0;
}
