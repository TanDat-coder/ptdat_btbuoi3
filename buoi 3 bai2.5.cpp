#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100

// Hàm tạo ma trận vuông với các phần tử ngẫu nhiên
void createSquareMatrix(int a[MAX_SIZE][MAX_SIZE], int n, int minVal, int maxVal) {
	int i, j;
	srand(time(0)); // Khởi tạo seed cho số ngẫu nhiên
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			a[i][j] = minVal + rand() % (maxVal - minVal + 1);
		}
	}
}

// Hàm in ma trận vuông
void printSquareMatrix(int a[MAX_SIZE][MAX_SIZE], int n) {
	int i, j;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
}

// Hàm so sánh cho qsort
int compare(const void *a, const void *b) {
	return (*(int*)a - *(int*)b);
}

// Hàm sắp xếp ma trận theo kiểu zic-zắc
void sortMatrixZigzag(int a[MAX_SIZE][MAX_SIZE], int n) {
	int temp[MAX_SIZE * MAX_SIZE];
	int i, j, k = 0;

	// Lưu tất cả các phần tử của ma trận vào mảng tạm
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			temp[k++] = a[i][j];
		}
	}

	// Sắp xếp mảng tạm theo thứ tự tăng dần
	qsort(temp, n * n, sizeof(int), compare);

	// Đưa các phần tử đã sắp xếp trở lại ma trận theo kiểu zic-zắc
	k = 0;
	for (i = 0; i < n; i++) {
		if (i % 2 == 0) { // Hàng chẵn: sắp xếp từ trái qua phải
			for (j = 0; j < n; j++) {
				a[i][j] = temp[k++];
			}
		}
		else { // Hàng lẻ: sắp xếp từ phải qua trái
			for (j = n - 1; j >= 0; j--) {
				a[i][j] = temp[k++];
			}
		}
	}
}

int main() {
	int n, minVal, maxVal;
	int a[MAX_SIZE][MAX_SIZE];

	printf("Nhập cấp của ma trận vuông (n >= 5): ");
	scanf("%d", &n);
	if (n < 5 || n > MAX_SIZE) {
		printf("Cấp của ma trận phải từ 5 đến %d.\n", MAX_SIZE);
		return 1;
	}

	printf("Nhập giá trị nhỏ nhất (minVal): ");
	scanf("%d", &minVal);
	printf("Nhập giá trị lớn nhất (maxVal): ");
	scanf("%d", &maxVal);

	if (minVal > maxVal) {
		printf("Giá trị minVal phải nhỏ hơn hoặc bằng maxVal.\n");
		return 1;
	}

	createSquareMatrix(a, n, minVal, maxVal);
	printf("Ma trận vuông vừa tạo:\n");
	printSquareMatrix(a, n);

	printf("\n");
	sortMatrixZigzag(a, n);
	printf("Ma trận sau khi sắp xếp kiểu zic-zắc:\n");
	printSquareMatrix(a, n);

	return 0;
}
