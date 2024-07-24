#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROW 100
#define MAX_COL 100

// Hàm tạo ma trận với các phần tử ngẫu nhiên
void createMatrix(int a[MAX_ROW][MAX_COL], int m, int n, int minVal, int maxVal) {
	int i, j;
	srand(time(0)); // Khởi tạo seed cho số ngẫu nhiên
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			a[i][j] = minVal + rand() % (maxVal - minVal + 1);
		}
	}
}

// Hàm in ma trận
void printMatrix(int a[MAX_ROW][MAX_COL], int m, int n) {
	int i, j;
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
}

// Hàm kiểm tra xem một số có phải là số chẵn hay không
int isEven(int num) {
	return num % 2 == 0;
}

// Hàm in các dòng chỉ chứa số chẵn
void printEvenRows(int a[MAX_ROW][MAX_COL], int m, int n) {
	int i, j, isEvenRow;

	printf("Các dòng chỉ chứa số chẵn:\n");
	for (i = 0; i < m; i++) {
		isEvenRow = 1; // Giả sử dòng chỉ chứa số chẵn
		for (j = 0; j < n; j++) {
			if (!isEven(a[i][j])) {
				isEvenRow = 0; // Nếu tìm thấy số lẻ, gán isEvenRow = 0
				break;
			}
		}
		if (isEvenRow) {
			// In dòng chỉ chứa số chẵn
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

	printf("Nhập số dòng (m): ");
	scanf("%d", &m);
	printf("Nhập số cột (n): ");
	scanf("%d", &n);
	printf("Nhập giá trị nhỏ nhất (minVal): ");
	scanf("%d", &minVal);
	printf("Nhập giá trị lớn nhất (maxVal): ");
	scanf("%d", &maxVal);

	if (m <= 0 || n <= 0 || m > MAX_ROW || n > MAX_COL) {
		printf("Kích thước ma trận không hợp lệ.\n");
		return 1;
	}

	if (minVal > maxVal) {
		printf("Giá trị minVal phải nhỏ hơn hoặc bằng maxVal.\n");
		return 1;
	}

	createMatrix(a, m, n, minVal, maxVal);
	printf("Ma trận vừa tạo:\n");
	printMatrix(a, m, n);

	printf("\nCác dòng chỉ chứa số chẵn:\n");
	printEvenRows(a, m, n);

	return 0;
}
