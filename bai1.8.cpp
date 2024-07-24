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

// H�m ki?m tra xem m?t s? c� ph?i l� s? ch?n hay kh�ng
int isEven(int num) {
	return num % 2 == 0;
}

// H�m in c�c d�ng ch? ch?a s? ch?n
void printEvenRows(int a[MAX_ROW][MAX_COL], int m, int n) {
	int i, j, isEvenRow;

	printf("C�c d�ng ch? ch?a s? ch?n:\n");
	for (i = 0; i < m; i++) {
		isEvenRow = 1; // Gi? s? d�ng ch? ch?a s? ch?n
		for (j = 0; j < n; j++) {
			if (!isEven(a[i][j])) {
				isEvenRow = 0; // N?u t�m th?y s? l?, g�n isEvenRow = 0
				break;
			}
		}
		if (isEvenRow) {
			// In d�ng ch? ch?a s? ch?n
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

	printf("\nC�c d�ng ch? ch?a s? ch?n:\n");
	printEvenRows(a, m, n);

	return 0;
}
