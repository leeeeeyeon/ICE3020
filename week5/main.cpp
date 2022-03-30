#include <iostream>
#include <chrono> // ���� �ð� ������ ���� ���

using namespace std;
using namespace chrono;

// �迭�� ����� ���ĵǾ����� Ȯ���ϴ� �Լ�
void checkSort(int a[], int n) {
	int i, sorted;
	sorted = true;

	for (i = 0; i < n-1; i++) {
		if (a[i] > a[i + 1]) sorted = false;
		if (!sorted) {
			cout << a[i] << " " << a[i + 1] << '\n';
			break;
		}
	}

	if (sorted) {
		cout << "���� �Ϸ�\n";
	}
	else {
		cout << "���� ����!\n";
	}

}

// [0, 1000) ������ ������ �����ϰ� �̸� �迭�� ���ҷ� ����
int* randomArr(int n) {
	int* arr = new int[n + 1]();

	for (int i = 0; i <= n; ++i) {
		arr[i] = rand() % 1000;
	}
	return arr;
}

void printArray(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << '\n';
}

// ���� �ٸ� �� ���� ���� �迭�� odd-even sort �˰���
// while�� �ȿ� �迭�� ����ϴ� �Լ��� ���Ե�
void oddEvenSort1(int arr[], int n) {
	bool isSorted = false; // �ʱ� �迭�� ���ĵǾ� ���� �����Ƿ� false�� ����

	while (!isSorted) {
		isSorted = true;
		
		// Odd index�� ���� sorting
		// for�� ���ο��� Bubble sort�� ���
		for (int i = 0; i <= n - 2; i += 2) {
			if (arr[i] > arr[i + 1]) {
				swap(arr[i], arr[i + 1]);
				isSorted = false;
			}
		}
		cout << "odd index\n";
		printArray(arr, n); // �� phase�� ���� ���¸� ���

		// Even index�� ���� sorting
		// for�� ���ο��� Bubble sort�� ���
		for (int i = 1; i <= n - 2; i += 2) {
			if (arr[i] > arr[i + 1]) {
				swap(arr[i], arr[i + 1]);
				isSorted = false;
			}
		}
		cout << "even index\n";
		printArray(arr, n); // �� phase�� ���� ���¸� ���
	}

	checkSort(arr, n); // ������ ����� �Ǿ����� Ȯ��
}

// ������ ���� ���� �迭�� odd-even sort �˰���
// �迭�� ����ϴ� �Լ��� ���ԵǾ����� �ʴ�
void oddEvenSort2(int arr[], int n) {
	bool isSorted = false;

	while (!isSorted) {
		isSorted = true;

		// Odd index�� ���� sorting
		// for�� ���ο��� Bubble sort�� ���
		for (int i = 0; i <= n - 2; i += 2) {
			if (arr[i] > arr[i + 1]) {
				swap(arr[i], arr[i + 1]);
				isSorted = false;
			}
		}

		// Even index�� ���� sorting
		// for�� ���ο��� Bubble sort�� ���
		for (int i = 1; i <= n - 2; i += 2) {
			if (arr[i] > arr[i + 1]) {
				swap(arr[i], arr[i + 1]);
				isSorted = false;
			}
		}
	}

	checkSort(arr, n); // ������ ����� �Ǿ����� Ȯ��
}

int main() {
	int arr1[] = { 2, 10, 5, 3, 7, 9, 4, 10 };
	int n1 = sizeof(arr1) / sizeof(arr1[0]);

	int arr2[] = { 2, 1, 5, 3, 7, 9, 4, 10 };
	int n2 = sizeof(arr2) / sizeof(arr2[0]);

	int arr3[] = { 4, 13, 2, 5, 6, 70, 8, 3, 10, 11, 24, 23, 21, 7, 9, 12 };
	int n3 = sizeof(arr3) / sizeof(arr3[0]);

	oddEvenSort1(arr1, n1);
	cout << '\n';
	cout << "���� ���� ���\n";
	printArray(arr1, n1);

	cout << "------------------\n";
	oddEvenSort1(arr2, n2);
	cout << '\n';
	cout << "���� ���� ���\n";
	printArray(arr2, n2);

	cout << "------------------\n";
	oddEvenSort1(arr3, n3);
	cout << '\n';
	cout << "���� ���� ���\n";
	printArray(arr3, n3);
	cout << '\n';
	cout << '\n';

	int size1 = 10000;
	int size2 = 50000;
	int size3 = 100000;

	int* arr4 = randomArr(size1);
	int* arr5 = randomArr(size2);
	int* arr6 = randomArr(size3);

	system_clock::time_point start = system_clock::now();
	oddEvenSort2(arr4, size1);
	system_clock::time_point end = system_clock::now();
	cout << "N=10,000: " << duration_cast<milliseconds>(end - start).count() << " ms" << endl;

	start = system_clock::now();
	oddEvenSort2(arr5, size2);
	end = system_clock::now();
	cout << "N=50,000: " << duration_cast<milliseconds>(end - start).count() << " ms" << endl;

	start = system_clock::now();
	oddEvenSort2(arr6, size3);
	end = system_clock::now();
	cout << "N=100,000: " << duration_cast<milliseconds>(end - start).count() << " ms" << endl;

}