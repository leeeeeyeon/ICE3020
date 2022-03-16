#include <iostream>
#include <chrono> // 수행 시간 측정을 위해 사용
using namespace std;
using namespace chrono;

// 재귀 함수를 활용하여 피보나치 수열 알고리즘 구현
int fibo(int n) {
	if (n <= 0) return 0;
	else if (n == 1) return 1;
	return fibo(n - 1) + fibo(n - 2); // fivo() 함수 2개를 더한 값을 return하므로 총 2^n번 연산이 수행된다.
}

int main() {
	system_clock::time_point start = system_clock::now();
	fibo(10);
	system_clock::time_point end = system_clock::now();
	cout << "n = 10일 때 피보나치 수: " << fibo(10) << ", 소요 시간: " << duration_cast<nanoseconds>(end - start).count() << " ns" << endl;

	start = system_clock::now();
	fibo(20);
	end = system_clock::now();
	cout << "n = 20일 때 피보나치 수: " << fibo(20) << ", 소요 시간: " << duration_cast<nanoseconds>(end - start).count() << " ns" << endl;

	start = system_clock::now();
	fibo(30);
	end = system_clock::now();
	cout << "n = 30일 때 피보나치 수: " << fibo(30) << ", 소요 시간: " << duration_cast<nanoseconds>(end - start).count() << " ns" << endl;
	return 0;
}