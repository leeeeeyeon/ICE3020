#include <iostream>
#include <chrono>

using namespace std;
using namespace chrono;

// [0, 100) ������ ������ �����ϰ� �̸� ����� ���ҷ� �����Ѵ�.
void initilizeMatrix(int** m, int row, int col) {
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j) {
			m[i][j] = rand() % 100;
		}
	}
}

// �迭�� �迭�� �Ҵ��ϰ� 0���� ���ҵ��� �ʱ�ȭ�Ѵ�.
int** allocateMatrix(int row, int col) {
	int** matrix = new int* [row];
	for (int i = 0; i < row; ++i) {
		matrix[i] = new int[col] {0};
	}
	return matrix;
}

// new�� �Ҵ��� ��İ� �� ��ҵ��� �Ҵ� �����Ѵ�.
int deallocateMatrix(int** matrix, int row) {
	for (int i = 0; i < row; ++i) {
		delete matrix[i];
	}
	delete[] matrix;
	return 0;
}

// 3�� for���� ���� m1, m2 �� ����� ���ϰ� �� ����� ret�̶�� ��Ŀ� �����Ѵ�.
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
	// ����� ������ش�.
	int** a = allocateMatrix(n, n);
	int** b = allocateMatrix(n, n);
	int** c = allocateMatrix(n, n);

	// ����� ��ҵ��� ä���ش�.
	initilizeMatrix(a, n, n);
	initilizeMatrix(b, n, n);
	initilizeMatrix(c, n, n);

	// ��� ������ ������ �� ���� �ð� ����
	system_clock::time_point start = system_clock::now();
	auto bc = multiplyMatrix(b, n, n, c, n, n); // ��� b�� c�� ���� ���ϰ�
	multiplyMatrix(a, n, n, bc, n, n); // �� ����� ��� a�� ���Ѵ�.
	system_clock::time_point end = system_clock::now();

	cout << "n = " << n << "�� �� �ҿ� �ð� : " << duration_cast<nanoseconds>(end - start).count() << " ns" << endl;
}

int main() {
	result(10);
	result(50);
	result(100);
	result(150);
	result(200);
	return 0;
}