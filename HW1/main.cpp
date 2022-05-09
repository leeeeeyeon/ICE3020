#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

// skip 배열을 만드는 함수
void initSkip(string p, int skip[256]) {
    int m = (int)p.size();
    
    for(int i=0; i<256; i++) skip[i] = m; // 모든 원소를 m으로 채운다
    for(int i=0; i<m; i++) skip[(int)p[i]] = m - i - 1; // 뒤에서 몇 번째인지를 값으로 저장
    // 아스키 코드를 사용하기 때문에 알파벳 외에도 숫자와 특수기호에 대해서도 검색이 가능
}

int misChar(string p, string t) {
    int m = (int)p.size(); // 패턴의 길이
    int n = (int)t.size(); // 텍스트의 길이
    
    int skip[256]; // skip 배열을 담을 공간을 생성
    initSkip(p, skip); // skip 배열을 만든다
    
    int i, j;
    // 반복문을 돌며 불일치 문자 방책 알고리즘 수행
    for(i = m-1, j = m-1; j>=0; i--, j--) {
        while (t[i] != p[j]) { // 불일치가 발생할 경우 while문 내의 코드가 실행됨
            int k = skip[(int)t[i]]; // k는 불일치가 일어난 위치
            if(m - j > k) i += (m - j);
            else i += k;
            
            if(i >= n) return n;
            j = m - 1;
        }
    }
    
    return i + 1;
}

// 찾고자 하는 패턴을 2번째 인자로 받아 텍스트에서 패턴 탐색을 진행
void findPattern(string text, string pattern) {
    int skip[256];
    initSkip(pattern, skip);

    int i = 0;
    int j = 0;

    // misChar() 함수를 한 번만 호출하면 최초로 탐색된 스트링의 위치만 나오기 때문에
    // 반복문을 돌며 text 전체에 대해 스트링 탐색이 되도록 함
    while (true) {
        int pos = misChar(pattern, text.substr(i));
        pos += j;
        i = pos + (int)pattern.size();
        if (i < text.size()) {
            cout << pos << "번째 인덱스에서 발견!" << endl;
        }
        else break;

        j = i;
    }
    cout << "탐색 완료" << endl;
}

int main() {
    string text = ""; // 텍스트 파일의 내용을 담을 변수
    
    // 텍스트 파일의 내용을 읽어와 text 변수에 저장하는 과정
    string str;
    ifstream file("RFC2616_modified.txt");
    
    while (getline(file, str)) {
        text.append(str);
    }
    
    // 보이어-무어 알고리즘을 이용하여 주어진 패턴들에 대해 탐색을 진행
    cout << "similar 탐색 과정\n";
    findPattern(text, "similar");
    
    cout << "\nUA -----v 탐색 과정\n";
    findPattern(text, "UA -----v");
    
    cout << "\nHTTP/1.1 탐색 과정\n";
    findPattern(text, "HTTP/1.1");
    
    cout << "\nletter \"A\"..\"Z\" 탐색 과정\n";
    findPattern(text, "letter \"A\"..\"Z\"");
    
    cout << "\n.[50] 탐색 과정\n";
    findPattern(text, "[50]");
    return 0;
}
