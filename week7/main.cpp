#include <iostream>
#include <string>
#include <vector>

using namespace std;

// KMP �˰����� �����ϱ� �� ������ ó��
vector<int> initNext(string p) {
	int m = p.length();

	vector<int>next(m); // ������ ���� ���͸� �̸� ����
	fill(next.begin(), next.end(), 0); // index ���� �� ������ �߻����� �ʵ��� �̸� ������ ä����

	next[0] = -1; // ������ Ʋ���� ���� ���
	for (int i = 0, j = -1; i < m; i++, j++) {
		next[i] = j;
		// ���ڿ��� ��ġ���� ���� ��
		while ((j >= 0) && (p[i] != p[j])) j = next[j];
	}

	return next;
}

vector<int> kmp(string t, string p) {
	int m = p.length();
	int n = t.length();

	vector<int> pos;

	vector<int> next = initNext(p); // next �迭�� ����

	int i, j;
	for (i = 0, j = 0; j < m && i < n; i++, j++) {
		while ((j >= 0) && (t[i] != p[j])) j = next[j]; // �ؽ�Ʈ�� ������ ��ġ���� ������ �߰� �ܰ踦 �Ѵ´�
	}

	if (j == m) { // ���̰� ���� -> ��ġ�ϴ� ������ ã�Ҵٴ� �ǹ�
		pos.push_back(i - m);
	}
	else pos.push_back(i); // ������ ã�� ������ ���

	return pos;
}

void ex1() {
	string t = "ababababcababababcaabbabababcaab";
	string p = "abababca";

	int i = 0;
	int j = 0;
	while (true) {
		vector<int> pos = kmp(t.substr(i), p); // KMP �˰����� ����
		// �� ���� ���ڿ��� ���ؼ��� kmp�� �����ؾ� ��
		// ���ڿ� �����̽��� ���� �ε��� i�� �ٲ��־�� �Ѵ�.
		pos[0] += j;
		i = pos[0] + p.size();

		// ������ �߻��� ��ġ�� pos[0]�� �����
		if (i < t.size()) {
			cout << "������ �߻��� ��ġ: " << pos[0] << endl;
		}
		else break;

		j = i;
	}
	cout << "Ž�� ����" << endl;
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
			cout << "������ �߻��� ��ġ: " << pos[0] << endl;
		}
		else break;

		j = i;
	}
	cout << "Ž�� ����";
}

int main() {
	// ���� 1
	ex1();

	cout << "--------------------------------------\n\n";

	ex2();

	return 0;
}