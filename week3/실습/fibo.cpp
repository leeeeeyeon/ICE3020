#include <iostream>
#include <chrono> // ���� �ð� ������ ���� ���
using namespace std;
using namespace chrono;

// ��� �Լ��� Ȱ���Ͽ� �Ǻ���ġ ���� �˰��� ����
int fibo(int n) {
	if (n <= 0) return 0;
	else if (n == 1) return 1;
	return fibo(n - 1) + fibo(n - 2); // fivo() �Լ� 2���� ���� ���� return�ϹǷ� �� 2^n�� ������ ����ȴ�.
}

int main() {
	system_clock::time_point start = system_clock::now();
	fibo(10);
	system_clock::time_point end = system_clock::now();
	cout << "n = 10�� �� �Ǻ���ġ ��: " << fibo(10) << ", �ҿ� �ð�: " << duration_cast<nanoseconds>(end - start).count() << " ns" << endl;

	start = system_clock::now();
	fibo(20);
	end = system_clock::now();
	cout << "n = 20�� �� �Ǻ���ġ ��: " << fibo(20) << ", �ҿ� �ð�: " << duration_cast<nanoseconds>(end - start).count() << " ns" << endl;

	start = system_clock::now();
	fibo(30);
	end = system_clock::now();
	cout << "n = 30�� �� �Ǻ���ġ ��: " << fibo(30) << ", �ҿ� �ð�: " << duration_cast<nanoseconds>(end - start).count() << " ns" << endl;
	return 0;
}