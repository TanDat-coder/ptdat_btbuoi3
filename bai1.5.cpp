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

// H�m ki?m tra xem m?t ph?n t? c� ph?i l� c?c ??i hay kh�ng
int isLocalMaxima(int a[MAX_ROW][MAX_COL], int m, int n, int i, int j) {
	int current = a[i][j];
	if ((i > 0 && current < a[i - 1][j]) ||  // Ki?m tra ph?n t? ph�a tr�n
		(i < m - 1 && current < a[i + 1][j]) ||  // Ki?m tra ph?n t? ph�a d??i
		(j > 0 && current < a[i][j - 1]) ||  // Ki?m tra ph?n t? b�n tr�i
		(j < n - 1 && current < a[i][j + 1]))  // Ki?m tra ph?n t? b�n ph?i
	{
		return 0;  // Kh�ng ph?i c?c ??i
	}
	return 1;  // L� c?c ??i
}

// H�m in c�c ph?n t? c?c ??i
void printLocalMaxima(int a[MAX_ROW][MAX_COL], int m, int n) {
	int i, j;
	printf("C�c ph?n t? c?c ??i:\n");
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			if (isLocalMaxima(a, m, n, i, j)) {
				printf("%d t?i v? tr� (%d, %d)\n", a[i][j], i, j);
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

	printf("\nC�c ph?n t? c?c ??i trong ma tr?n:\n");
	printLocalMaxima(a, m, n);

	return 0;
}
