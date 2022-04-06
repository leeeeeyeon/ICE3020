#include <iostream>
#include <chrono>

using namespace std;
using namespace chrono;

// ������������ ������ �Ǿ����� Ȯ��
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
		cout << "checkSort: ���� �Ϸ�\n";
	}
	else {
		cout << "checkSort: ���� ����!\n";
	}

}

// ������������ ������ �Ǿ����� Ȯ��
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
		cout << "checkSort: ���� �Ϸ�\n";
	}
	else {
		cout << "checkSort: ���� ����!\n";
	}

}

// [0, 100) ������ ������ �����ϰ� �̸� �迭�� ���ҷ� ����
int* randomArr(int n) {
	int* arr = new int[n + 1]();

	for (int i = 0; i <= n; ++i) {
		arr[i] = rand() % 100;
	}
	return arr;
}

// �迭�� ����ϴ� �Լ�
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

// �ִ� ���� ����ȭ(heapify) �Լ�
void maxHeapify(int arr[], int i, int size) {
	int left = i * 2 + 1;
	int right = i * 2 + 2;
	int max = i;

	// ���� �ڽ� ��尡 ������ ��, �θ� ���� �� ��
	if (left<size && arr[left]>arr[max]) max = left;
	// ������ �ڽ� ��尡 ������ ��, �θ� ���� �� ��
	if (right<size && arr[right]>arr[max]) max = right;

	// �ڽ� ��� �� �θ� ��庸�� ū ���� �����ϴ� ���
	if (max != i) {
		swap(&arr[i], &arr[max]);

		// �θ� ��尡 ���ڸ��� ã�� ������ ��������
		maxHeapify(arr, max, size);
	}
}

// �ּ� ���� ����ȭ(heapify) �Լ�
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

// �ִ� �� ����
void buildMaxHeap(int arr[], int size) {
	int i, j;
	for (i = size / 2 - 1; i >= 0; i--) {
		maxHeapify(arr, i, size);
	}
}

// �ּ� �� ����
void buildMinHeap(int arr[], int size) {
	int i, j;
	for (i = size / 2 - 1; i >= 0; i--) {
		minHeapify(arr, i, size);
	}
}

// �ִ� ������ ����
void maxHeapSort(int arr[], int size) {
	int treeSize;

	// �ִ� �� ����
	buildMaxHeap(arr, size);

	// ��Ʈ�� ��ġ�� �ִ밪�� ������ ���� �ٲ㰡�� ���� �籸���Ѵ�
	// ���� ũ�⸦ �ٿ����� ���� ū ���Ҹ� ���ʷ� �����´�
	for (treeSize = size - 1; treeSize >= 0; treeSize--) {
		swap(&arr[0], &arr[treeSize]);
		maxHeapify(arr, 0, treeSize);
	}
}

// �ּ� ������ ����
void minHeapSort(int arr[], int size) {
	int treeSize;

	// �ּ� �� ����
	buildMinHeap(arr, size);

	// ��Ʈ�� ��ġ�� �ּҰ��� ������ ���� �ٲ㰡�� ���� �籸���Ѵ�
	// ���� ũ�⸦ �ٿ����� ���� ���� ���Ҹ� ���ʷ� �����´�
	for (treeSize = size - 1; treeSize >= 0; treeSize--) {
		swap(&arr[0], &arr[treeSize]);
		minHeapify(arr, 0, treeSize);
	}
}

int main() {
	int maxArr[10] = { 6,2,8,1,3,9,4,5,10,7 };
	int a = sizeof(maxArr) / sizeof(int); // �迭�� ũ��

	maxHeapSort(maxArr, a);
	
	cout << "MaxHeap ���� ���\n";
	printArray(maxArr, a);

	int minArr[10] = { 6,2,8,1,3,9,4,5,10,7 };
	int b = sizeof(minArr) / sizeof(int); // �迭�� ũ��

	minHeapSort(minArr, b);

	cout << "\nMinHeap ���� ���\n";
	printArray(minArr, b);

	// --------------------------------------

	int n[5] = { 10000, 50000, 100000, 500000, 1000000 };

	cout << '\n';
	cout << "--------------------------------------\n\n";

	// �ݺ����� Ȱ���Ͽ� ��� 2�� ����ϴ� �ڵ带 ª�� ����
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