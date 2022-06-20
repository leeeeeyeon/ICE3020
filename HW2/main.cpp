#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

string str1, str2;
double dist[1001][1001];

#define ABS(X) ((X) < 0 ? -(X) : (X))
#define EPSILON 0.0000001

void levenshtein(string& str1, string& str2, double ins, double del, double chg) {
    // 초기화
    dist[0][0] = 0;

    for (int i=1; i<=str1.length(); i++) {
        dist[i][0] = dist[i-1][0] + del;
    }

    for (int j=1; j<=str2.length(); j++) {
        dist[0][j] = dist[0][j-1] + ins;
    }

    // DP 진행
    for (int j=1; j<=str2.length(); j++) {
        for (int i=1; i<=str1.length(); i++) {
            if (str1[i-1] == str2[j-1]) {
                dist[i][j] = dist[i-1][j-1];
            }
            else {
                dist[i][j] = min(dist[i-1][j-1] + chg, min(dist[i][j-1]+ins, dist[i-1][j]+del));

            }

        }
    }

    // 출력
    for (int j=0; j<=str2.length(); j++) {
        for (int i=0; i<=str1.length(); i++) {
            cout.width(3);
            cout << dist[i][j] << " ";
        }
        cout << '\n';
    }

}

vector<string> getTrace(double dist[1001][1001], string str1, string str2) {
    vector<string> v;
    cout << str2 << "을(를) " << str1 << "로 바꾸는 과정" << endl;

    int i = int(str2.length() - 1);
    int j = int(str1.length() - 1);


    while (true) {
        
        if((i < 0 || j < 0) || (i == 0 && j == 0)) {
            break;
        }
        
        if(i == 0) {
            string del = " 삽입연산 0.7 ";
            v.push_back(del);
            j--;
            
            continue;
        }
        
        if(j == 0) {
            string ins = " 삭제연산 0.5 ";
            v.push_back(ins);
            i--;
            
            continue;
        }
        
        double s = min(dist[i-1][j-1], min(dist[i][j-1], dist[i-1][j]));
        
        if(ABS(dist[i-1][j-1] - dist[i][j]) < 0.00001) {
            i--;
            j--;
        }

        else {
            if (ABS(s - dist[i-1][j-1]) < 0.00001) {
                string chg = " 교환연산 0.3 ";
                v.push_back(chg);
                i--;
                j--;
            }
            else if (ABS(s - dist[i][j-1]) < 0.00001) {
                string del = " 삽입연산 0.7 ";
                v.push_back(del);
                j--;
            }
            else if (ABS(s - dist[i-1][j]) < 0.00001) {
                string ins = " 삭제연산 0.5 ";
                v.push_back(ins);
                i--;
            }
        }

    }

//    reverse(v.begin(), v.end());

    return v;
}

void prob1() {
    vector<string> v;

    cout << "[ 1번 문제 ]" << endl;

    string str1 = "GUMBO";
    string str2 = "GAMBOL";

    cout << "삽입비용 = 삭제비용 = 1, 교환비용 = 0/1 일 때" << endl;
    levenshtein(str1, str2, 1, 1, 1);
    cout << "편집 거리: " << dist[str1.length()][str2.length()] << endl;
    cout << endl;

    cout << "삽입비용 = 0.7, 삭제비용 = 0.5, 교환비용 = 0/0.3 일 때" << endl;
    levenshtein(str1, str2, 0.7, 0.5, 0.3);
    cout << "편집 거리: " << dist[str1.length()][str2.length()] << endl;
    cout << endl;
    
}

void prob2() {
    // s1(행) -> s2(열)
    cout << "[ 2번 문제 ]" << endl;
    
    string str1 = "Levenshtein";
    string str2 = "Meilenstein";
    
    levenshtein(str1, str2, 0.7, 0.5, 0.3);
    cout << "편집 거리: " << dist[str1.length()-1][str2.length()-1] << endl;
    cout << endl;
    
    vector<string> v1;
    vector<string> v2;
    vector<string> v3;

    v1 = getTrace(dist, str2, str1);
    for(auto i : v1) cout << i;
    cout << endl;
    cout << endl;

    str1 = "TACTG";
    str2 = "CATGACTG";
    levenshtein(str1, str2, 0.7, 0.5, 0.3);
    cout << "편집 거리: " << dist[str1.length()][str2.length()] << endl;
    cout << endl;

    v2 = getTrace(dist, str2, str1);
    for(auto i : v2) cout << i;
    cout << endl;

    cout << endl;

//    str1 = "데이타마이닝";
//    str2 = "데이터베이스설계";
//    levenshtein(str1, str2, 0.7, 0.5, 0.3);
//    cout << "편집 거리: " << dist[str1.length()][str2.length()] << endl;
}

//

//
int main() {
//    https://hsp1116.tistory.com/41
//    string str1 = "Levenshtein";
//    string str2 = "Meilenstein";
//    levenshtein(str1, str2, 0.7, 0.5, 0.3);
//    cout << "편집 거리: " << dist[str1.length()-1][str2.length()-1] << endl;
//
//    vector<string> v = getTrace(dist, str1, str2);
//    for(auto i : v) {
//        cout << i << endl;
//    }
    prob1();
    prob2();

    return 0;
}
