#include <iostream>
#include <chrono> // 수행 시간 측정을 위해 사용

using namespace std;
using namespace chrono;

// 배열이 제대로 정렬되었는지 확인하는 함수
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
		cout << "정렬 완료\n";
	}
	else {
		cout << "정렬 오류!\n";
	}

}

// [0, 1000) 범위의 난수를 생성하고 이를 배열의 원소로 저장
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

// 서로 다른 세 개의 정수 배열의 odd-even sort 알고리즘
// while문 안에 배열을 출력하는 함수가 포함됨
void oddEvenSort1(int arr[], int n) {
	bool isSorted = false; // 초기 배열은 정렬되어 있지 않으므로 false로 시작

	while (!isSorted) {
		isSorted = true;
		
		// Odd index일 때의 sorting
		// for문 내부에서 Bubble sort를 사용
		for (int i = 0; i <= n - 2; i += 2) {
			if (arr[i] > arr[i + 1]) {
				swap(arr[i], arr[i + 1]);
				isSorted = false;
			}
		}
		cout << "odd index\n";
		printArray(arr, n); // 각 phase별 정렬 상태를 출력

		// Even index일 때의 sorting
		// for문 내부에서 Bubble sort를 사용
		for (int i = 1; i <= n - 2; i += 2) {
			if (arr[i] > arr[i + 1]) {
				swap(arr[i], arr[i + 1]);
				isSorted = false;
			}
		}
		cout << "even index\n";
		printArray(arr, n); // 각 phase별 정렬 상태를 출력
	}

	checkSort(arr, n); // 정렬이 제대로 되었는지 확인
}

// 임의의 랜덤 정수 배열의 odd-even sort 알고리즘
// 배열을 출력하는 함수가 포함되어있지 않다
void oddEvenSort2(int arr[], int n) {
	bool isSorted = false;

	while (!isSorted) {
		isSorted = true;

		// Odd index일 때의 sorting
		// for문 내부에서 Bubble sort를 사용
		for (int i = 0; i <= n - 2; i += 2) {
			if (arr[i] > arr[i + 1]) {
				swap(arr[i], arr[i + 1]);
				isSorted = false;
			}
		}

		// Even index일 때의 sorting
		// for문 내부에서 Bubble sort를 사용
		for (int i = 1; i <= n - 2; i += 2) {
			if (arr[i] > arr[i + 1]) {
				swap(arr[i], arr[i + 1]);
				isSorted = false;
			}
		}
	}

	checkSort(arr, n); // 정렬이 제대로 되었는지 확인
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
	cout << "최종 정렬 결과\n";
	printArray(arr1, n1);

	cout << "------------------\n";
	oddEvenSort1(arr2, n2);
	cout << '\n';
	cout << "최종 정렬 결과\n";
	printArray(arr2, n2);

	cout << "------------------\n";
	oddEvenSort1(arr3, n3);
	cout << '\n';
	cout << "최종 정렬 결과\n";
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