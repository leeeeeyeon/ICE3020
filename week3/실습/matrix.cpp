#include <iostream>
#include <chrono>

using namespace std;
using namespace chrono;

// [0, 100) 범위의 난수를 생성하고 이를 행렬의 원소로 저장한다.
void initilizeMatrix(int** m, int row, int col) {
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j) {
			m[i][j] = rand() % 100;
		}
	}
}

// 배열의 배열을 할당하고 0으로 원소들을 초기화한다.
int** allocateMatrix(int row, int col) {
	int** matrix = new int* [row];
	for (int i = 0; i < row; ++i) {
		matrix[i] = new int[col] {0};
	}
	return matrix;
}

// new로 할당한 행렬과 각 요소들을 할당 해제한다.
int deallocateMatrix(int** matrix, int row) {
	for (int i = 0; i < row; ++i) {
		delete matrix[i];
	}
	delete[] matrix;
	return 0;
}

// 3중 for문을 돌며 m1, m2 두 행렬을 곱하고 그 결과를 ret이라는 행렬에 저장한다.
int** multiplyMatrix(int** m1, int row1, int col1, int** m2, int row2, int col2) {
	if (col1 != row2) return nullptr;
	auto ret = allocateMatrix(row1, col2);


	for (int i = 0; i < row1; i++) {
		for (int j = 0; j < col2; j++) {
			for (int k = 0; k < col1; k++) {
				ret[i][j] += m1[i][k] * m2[k][j];
			}
		}
	}

	return ret;
}

void result(int n) {
	// 행렬을 만들어준다.
	int** a = allocateMatrix(n, n);
	int** b = allocateMatrix(n, n);
	int** c = allocateMatrix(n, n);

	// 행렬의 요소들을 채워준다.
	initilizeMatrix(a, n, n);
	initilizeMatrix(b, n, n);
	initilizeMatrix(c, n, n);

	// 행렬 곱셈을 수행한 뒤 수행 시간 측정
	system_clock::time_point start = system_clock::now();
	auto bc = multiplyMatrix(b, n, n, c, n, n); // 행렬 b와 c를 먼저 곱하고
	multiplyMatrix(a, n, n, bc, n, n); // 그 결과를 행렬 a와 곱한다.
	system_clock::time_point end = system_clock::now();

	cout << "n = " << n << "일 때 소요 시간 : " << duration_cast<nanoseconds>(end - start).count() << " ns" << endl;
}

int main() {
	result(10);
	result(50);
	result(100);
	result(150);
	result(200);
	return 0;
}