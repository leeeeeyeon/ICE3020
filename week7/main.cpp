#include <iostream>
#include <string>
#include <vector>

using namespace std;

// KMP 알고리즘을 수행하기 전 패턴을 처리
vector<int> initNext(string p) {
	int m = p.length();

	vector<int>next(m); // 값들을 담을 벡터를 미리 생성
	fill(next.begin(), next.end(), 0); // index 접근 시 오류가 발생하지 않도록 미리 값들을 채워둠

	next[0] = -1; // 패턴이 틀렸을 때를 대비
	for (int i = 0, j = -1; i < m; i++, j++) {
		next[i] = j;
		// 문자열이 일치하지 않을 때
		while ((j >= 0) && (p[i] != p[j])) j = next[j];
	}

	return next;
}

vector<int> kmp(string t, string p) {
	int m = p.length();
	int n = t.length();

	vector<int> pos;

	vector<int> next = initNext(p); // next 배열을 생성

	int i, j;
	for (i = 0, j = 0; j < m && i < n; i++, j++) {
		while ((j >= 0) && (t[i] != p[j])) j = next[j]; // 텍스트와 패턴이 일치하지 않으면 중간 단계를 넘는다
	}

	if (j == m) { // 길이가 같음 -> 일치하는 패턴을 찾았다는 의미
		pos.push_back(i - m);
	}
	else pos.push_back(i); // 패턴을 찾지 못했을 경우

	return pos;
}

void ex1() {
	string t = "ababababcababababcaabbabababcaab";
	string p = "abababca";

	int i = 0;
	int j = 0;
	while (true) {
		vector<int> pos = kmp(t.substr(i), p); // KMP 알고리즘을 수행
		// 그 다음 문자열에 대해서도 kmp를 수행해야 함
		// 문자열 슬라이싱을 위해 인덱스 i를 바꿔주어야 한다.
		pos[0] += j;
		i = pos[0] + p.size();

		// 패턴이 발생한 위치는 pos[0]에 저장됨
		if (i < t.size()) {
			cout << "패턴이 발생한 위치: " << pos[0] << endl;
		}
		else break;

		j = i;
	}
	cout << "탐색 종료" << endl;
}

void ex2() {
	string t = "This class is an algorithm design class. Therefore, students will have time to learn about algorithms and implement each algorithm themselves.";
	string p = "algorithm";

	int i = 0;
	int j = 0;
	while (true) {
		vector<int> pos = kmp(t.substr(i), p);
		pos[0] += j;
		i = pos[0] + p.size();
		if (i < t.size()) {
			cout << "패턴이 발생한 위치: " << pos[0] << endl;
		}
		else break;

		j = i;
	}
	cout << "탐색 종료";
}

int main() {
	// 예제 1
	ex1();

	cout << "--------------------------------------\n\n";

	ex2();

	return 0;
}