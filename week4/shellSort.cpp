#include <iostream>
#include <chrono> // 수행 시간 측정을 위해 사용

using namespace std;
using namespace chrono;

void checkSort(int a[], int n) {
	int i, sorted;
	sorted = true;

	for (i = 1; i < n; i++) {
		if (a[i] > a[i + 1]) sorted = false;
		if (!sorted) break;
	}

	if (sorted) {
		cout << "정렬 완료\n";
	}
	else {
		cout << "정렬 오류!\n";
	}

}

// [0, 100) 범위의 난수를 생성하고 이를 배열의 원소로 저장
int* randomArr(int n) {
	int* arr = new int[n + 1]();

	for (int i = 1; i <= n; ++i) {
		arr[i] = rand() % 100;
	}
	return arr;
}

void shellSort1(int arr[], int n) {
	int gap, v, i, j;

	for (gap = 1; gap < n; gap = 3 * gap + 1); // 증가식에 따라 gap을 증가시킴

	for (; gap > 0; gap /= 3) { // 감소식에 따라 gap을 감소시키면서 반복
		// 부분 배열에 대해 삽입 정렬을 진행
		for (i = gap + 1; i <= n; i++) {
			v = arr[i];
			j = i;
			while (j > gap && arr[j - gap] > v) {
				arr[j] = arr[j - gap];
				j -= gap;
			}
			arr[j] = v;
		}
	}
}

void shellSort2(int arr[], int n) {
	int gap, v, i, j;

	for (gap = 1; gap < n; gap = 3 * gap);

	for (; gap > 0; gap /= 3) {
		for (i = gap + 1; i <= n; i++) {
			v = arr[i];
			j = i;
			while (j > gap && arr[j - gap] > v) {
				arr[j] = arr[j - gap];
				j -= gap;
			}
			arr[j] = v;
		}
	}
}

void shellSort3(int arr[], int n) {
	int gap, v, i, j;

	for (gap = 1; gap < n; gap = 5 * gap + 1);

	for (; gap > 0; gap /= 5) {
		for (i = gap + 1; i <= n; i++) {
			v = arr[i];
			j = i;
			while (j > gap && arr[j - gap] > v) {
				arr[j] = arr[j - gap];
				j -= gap;
			}
			arr[j] = v;
		}
	}
}

/*
증가식1: h = 3*h+1 감소식: h = h/3
증가식2: h = 3*h 감소식: h = h/3
증가식3: h = 5*h + 1 감소식: h = h/5
*/

void first() {
	int n1 = 100000;
	int n2 = 500000;
	int n3 = 1000000;
	int n4 = 5000000;
	int n5 = 10000000;

	int* arr1 = randomArr(n1);
	int* arr2 = randomArr(n2);
	int* arr3 = randomArr(n3);
	int* arr4 = randomArr(n4);
	int* arr5 = randomArr(n5);

	system_clock::time_point start = system_clock::now();
	shellSort1(arr1, n1);
	system_clock::time_point end = system_clock::now();
	cout << "증가식1: h = 3*h+1 감소식: h = h/3 쉘 정렬 실행 시간(N=100,000): " << duration_cast<nanoseconds>(end - start).count() << " ns" << endl;
	checkSort(arr1, n1);

	start = system_clock::now();
	shellSort1(arr2, n2);
	end = system_clock::now();
	cout << "증가식1: h = 3*h+1 감소식: h = h/3 쉘 정렬 실행 시간(N=500,000): " << duration_cast<nanoseconds>(end - start).count() << " ns" << endl;
	checkSort(arr2, n2);

	start = system_clock::now();
	shellSort1(arr3, n3);
	end = system_clock::now();
	cout << "증가식1: h = 3*h+1 감소식: h = h/3 쉘 정렬 실행 시간(N=1,000,000): " << duration_cast<nanoseconds>(end - start).count() << " ns" << endl;
	checkSort(arr3, n3);

	start = system_clock::now();
	shellSort1(arr4, n4);
	end = system_clock::now();
	cout << "증가식1: h = 3*h+1 감소식: h = h/3 쉘 정렬 실행 시간(N=5,000,000): " << duration_cast<nanoseconds>(end - start).count() << " ns" << endl;
	checkSort(arr4, n4);

	start = system_clock::now();
	shellSort1(arr5, n5);
	end = system_clock::now();
	cout << "증가식1: h = 3*h+1 감소식: h = h/3 쉘 정렬 실행 시간(N=10,000,000): " << duration_cast<nanoseconds>(end - start).count() << " ns" << endl;
	checkSort(arr5, n5);

	delete arr1;
	delete arr2;
	delete arr3;
	delete arr4;
	delete arr5;
}

void second() {
	int n1 = 100000;
	int n2 = 500000;
	int n3 = 1000000;
	int n4 = 5000000;
	int n5 = 10000000;

	int* arr1 = randomArr(n1);
	int* arr2 = randomArr(n2);
	int* arr3 = randomArr(n3);
	int* arr4 = randomArr(n4);
	int* arr5 = randomArr(n5);

	system_clock::time_point start = system_clock::now();
	shellSort2(arr1, n1);
	system_clock::time_point end = system_clock::now();
	cout << "증가식2: h = 3*h 감소식: h = h/3 쉘 정렬 실행 시간(N=100,000): " << duration_cast<nanoseconds>(end - start).count() << " ns" << endl;
	checkSort(arr1, n1);

	start = system_clock::now();
	shellSort2(arr2, n2);
	end = system_clock::now();
	cout << "증가식2: h = 3*h 감소식: h = h/3 쉘 정렬 실행 시간(N=500,000): " << duration_cast<nanoseconds>(end - start).count() << " ns" << endl;
	checkSort(arr2, n2);

	start = system_clock::now();
	shellSort2(arr3, n3);
	end = system_clock::now();
	cout << "증가식2: h = 3*h 감소식: h = h/3 쉘 정렬 실행 시간(N=1,000,000): " << duration_cast<nanoseconds>(end - start).count() << " ns" << endl;
	checkSort(arr3, n3);

	start = system_clock::now();
	shellSort2(arr4, n4);
	end = system_clock::now();
	cout << "증가식2: h = 3*h 감소식: h = h/3 쉘 정렬 실행 시간(N=5,000,000): " << duration_cast<nanoseconds>(end - start).count() << " ns" << endl;
	checkSort(arr4, n4);

	start = system_clock::now();
	shellSort2(arr5, n5);
	end = system_clock::now();
	cout << "증가식2: h = 3*h 감소식: h = h/3 쉘 정렬 실행 시간(N=10,000,000): " << duration_cast<nanoseconds>(end - start).count() << " ns" << endl;
	checkSort(arr5, n5);

	delete arr1;
	delete arr2;
	delete arr3;
	delete arr4;
	delete arr5;
}

void third() {
	int n1 = 100000;
	int n2 = 500000;
	int n3 = 1000000;
	int n4 = 5000000;
	int n5 = 10000000;

	int* arr1 = randomArr(n1);
	int* arr2 = randomArr(n2);
	int* arr3 = randomArr(n3);
	int* arr4 = randomArr(n4);
	int* arr5 = randomArr(n5);

	system_clock::time_point start = system_clock::now();
	shellSort3(arr1, n1);
	system_clock::time_point end = system_clock::now();
	cout << "증가식3: h = 5*h+1 감소식: h = h/5 쉘 정렬 실행 시간(N=100,000): " << duration_cast<nanoseconds>(end - start).count() << " ns" << endl;
	checkSort(arr1, n1);

	start = system_clock::now();
	shellSort3(arr2, n2);
	end = system_clock::now();
	cout << "증가식3: h = 5*h+1 감소식: h = h/5 쉘 정렬 실행 시간(N=500,000): " << duration_cast<nanoseconds>(end - start).count() << " ns" << endl;
	checkSort(arr2, n2);

	start = system_clock::now();
	shellSort3(arr3, n3);
	end = system_clock::now();
	cout << "증가식3: h = 5*h+1 감소식: h = h/5 쉘 정렬 실행 시간(N=1,000,000): " << duration_cast<nanoseconds>(end - start).count() << " ns" << endl;
	checkSort(arr3, n3);

	start = system_clock::now();
	shellSort3(arr4, n4);
	end = system_clock::now();
	cout << "증가식3: h = 5*h+1 감소식: h = h/5 쉘 정렬 실행 시간(N=5,000,000): " << duration_cast<nanoseconds>(end - start).count() << " ns" << endl;
	checkSort(arr4, n4);

	start = system_clock::now();
	shellSort3(arr5, n5);
	end = system_clock::now();
	cout << "증가식3: h = 5*h+1 감소식: h = h/5 쉘 정렬 실행 시간(N=10,000,000): " << duration_cast<nanoseconds>(end - start).count() << " ns" << endl;
	checkSort(arr5, n5);

	delete arr1;
	delete arr2;
	delete arr3;
	delete arr4;
	delete arr5;
}

int main() {
	first();
	cout << '\n';
	second();
	cout << '\n';
	third();

}