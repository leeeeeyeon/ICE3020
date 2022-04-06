#include <iostream>
#include <chrono>

using namespace std;
using namespace chrono;

// 오름차순으로 정렬이 되었는지 확인
void maxCheckSort(int a[], int n) {
	int i, sorted;
	sorted = true;

	for (i = 0; i < n - 1; i++) {
		if (a[i] > a[i + 1]) sorted = false;
		if (!sorted) {
			cout << a[i] << " " << a[i + 1] << '\n';
			break;
		}
	}

	if (sorted) {
		cout << "checkSort: 정렬 완료\n";
	}
	else {
		cout << "checkSort: 정렬 오류!\n";
	}

}

// 내림차순으로 정렬이 되었는지 확인
void minCheckSort(int a[], int n) {
	int i, sorted;
	sorted = true;

	for (i = 0; i < n - 1; i++) {
		if (a[i] < a[i + 1]) sorted = false;
		if (!sorted) {
			cout << a[i] << " " << a[i + 1] << '\n';
			break;
		}
	}

	if (sorted) {
		cout << "checkSort: 정렬 완료\n";
	}
	else {
		cout << "checkSort: 정렬 오류!\n";
	}

}

// [0, 100) 범위의 난수를 생성하고 이를 배열의 원소로 저장
int* randomArr(int n) {
	int* arr = new int[n + 1]();

	for (int i = 0; i <= n; ++i) {
		arr[i] = rand() % 100;
	}
	return arr;
}

// 배열을 출력하는 함수
void printArray(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << '\n';
}

void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

// 최대 힙의 히프화(heapify) 함수
void maxHeapify(int arr[], int i, int size) {
	int left = i * 2 + 1;
	int right = i * 2 + 2;
	int max = i;

	// 왼쪽 자식 노드가 존재할 때, 부모 노드와 값 비교
	if (left<size && arr[left]>arr[max]) max = left;
	// 오른쪽 자식 노드가 존재할 때, 부모 노드와 값 비교
	if (right<size && arr[right]>arr[max]) max = right;

	// 자식 노드 중 부모 노드보다 큰 값이 존재하는 경우
	if (max != i) {
		swap(&arr[i], &arr[max]);

		// 부모 노드가 제자리를 찾을 때까지 내려간다
		maxHeapify(arr, max, size);
	}
}

// 최소 힙의 히프화(heapify) 함수
void minHeapify(int arr[], int i, int size) {
	int left = i * 2 + 1;
	int right = i * 2 + 2;
	int min = i;

	if (left<size && arr[left]<arr[min]) min = left;
	if (right<size && arr[right]<arr[min]) min = right;

	if (min != i) {
		swap(&arr[i], &arr[min]);
		minHeapify(arr, min, size);
	}
}

// 최대 힙 구성
void buildMaxHeap(int arr[], int size) {
	int i, j;
	for (i = size / 2 - 1; i >= 0; i--) {
		maxHeapify(arr, i, size);
	}
}

// 최소 힙 구성
void buildMinHeap(int arr[], int size) {
	int i, j;
	for (i = size / 2 - 1; i >= 0; i--) {
		minHeapify(arr, i, size);
	}
}

// 최대 힙으로 정렬
void maxHeapSort(int arr[], int size) {
	int treeSize;

	// 최대 힙 구성
	buildMaxHeap(arr, size);

	// 루트에 위치한 최대값을 마지막 노드와 바꿔가며 힙을 재구성한다
	// 힙의 크기를 줄여가며 값이 큰 원소를 차례로 가져온다
	for (treeSize = size - 1; treeSize >= 0; treeSize--) {
		swap(&arr[0], &arr[treeSize]);
		maxHeapify(arr, 0, treeSize);
	}
}

// 최소 힙으로 정렬
void minHeapSort(int arr[], int size) {
	int treeSize;

	// 최소 힙 구성
	buildMinHeap(arr, size);

	// 루트에 위치한 최소값을 마지막 노드와 바꿔가며 힙을 재구성한다
	// 힙의 크기를 줄여가며 값이 작은 원소를 차례로 가져온다
	for (treeSize = size - 1; treeSize >= 0; treeSize--) {
		swap(&arr[0], &arr[treeSize]);
		minHeapify(arr, 0, treeSize);
	}
}

int main() {
	int maxArr[10] = { 6,2,8,1,3,9,4,5,10,7 };
	int a = sizeof(maxArr) / sizeof(int); // 배열의 크기

	maxHeapSort(maxArr, a);
	
	cout << "MaxHeap 정렬 결과\n";
	printArray(maxArr, a);

	int minArr[10] = { 6,2,8,1,3,9,4,5,10,7 };
	int b = sizeof(minArr) / sizeof(int); // 배열의 크기

	minHeapSort(minArr, b);

	cout << "\nMinHeap 정렬 결과\n";
	printArray(minArr, b);

	// --------------------------------------

	int n[5] = { 10000, 50000, 100000, 500000, 1000000 };

	cout << '\n';
	cout << "--------------------------------------\n\n";

	// 반복문을 활용하여 출력 2를 출력하는 코드를 짧게 만듦
	for (int i = 0; i < 5; i++) {
		int* arr = randomArr(n[i]);

		system_clock::time_point start = system_clock::now();
		maxHeapSort(arr, n[i]);
		system_clock::time_point end = system_clock::now();

		cout << "Maxheap sorting complete!\n";
		maxCheckSort(arr, n[i]);

		cout << "Maxheap sorting (N=" << n[i] << ") time cost: " << duration_cast<milliseconds>(end - start).count() << " ms\n\n";

		start = system_clock::now();
		minHeapSort(arr, n[i]);
		end = system_clock::now();

		cout << "Minheap sorting complete!\n";
		minCheckSort(arr, n[i]);

		cout << "Minheap sorting (N=" << n[i] << ") time cost: " << duration_cast<milliseconds>(end - start).count() << " ms\n\n";

		cout << "--------------------------------------\n\n";

	}

	return 0;
}