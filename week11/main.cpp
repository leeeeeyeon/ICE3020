#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int DP[9][9] = { 0 };
    int map[9][9] = {
            {-1, -1, 1, -1, -1, -1, -1, -1, -1},
            {-1, -1,  -1, -1, -1, 1, -1, 2, -1},
            {1, -1, 2, -1, -1, -1, -1, 1, -1},
            {-1, -1, -1, -1, 1, 2, -1, -1, -1},
            {-1, 1, -1, 1, -1, -1, -1, -1, -1},
            {-1, -1, -1, -1, -1, 2, 1, 2, -1},
            {-1, 1, -1, -1, 1, -1, -1, -1, -1},
            {-1, -1, -1, -1, -1, 1, -1, -1, -1},
            {-1, -1, -1, -1, -1, -1, -1, -1, -1}
    };
    
    for(int i=8; i>=0; i--) { // 행
        for(int j=0; j<9; j++) { // 열
            if (i == 8) { // 가장 아래 행, [i, j-1] -> [i, j]로 오는 것만 가능
                DP[i][j] = 0;
            }
            else if (j == 0) { // 가장 왼쪽 열, [i+1, j] -> [i, j]로 오는 것만 가능
                DP[i][j] = max(DP[i+1][j], DP[i+1][j] + map[i][j]);
            }
            else { // [i+1, j] -> [i, j]와 [i, j-1] -> [i, j] 둘 다 가능
                // max(DP[i+1][j], DP[i][j-1])은 이제까지 먹은 치즈의 개수
                // 지금 자리에 치즈가 없다면 max(DP[i+1][j], DP[i][j-1]) + map[i][j] 값은 (이제까지 먹은 치즈 - 1)개
                // 지금 자리에 치즈가 있다면 (이제까지 먹은 치즈 + 1)개가 됨
                
                // 덫을 만나면 DP 배열의 원소 값을 -1로 함
                // max 연산에서 선택되지 않기 위함
                if (map[i][j] == 2) DP[i][j] = -1;
                
                else DP[i][j] = max(max(DP[i+1][j], DP[i][j-1]), max(DP[i+1][j], DP[i][j-1]) + map[i][j]);

            }
        }
    }
    
    // 결과 출력
    for(int i=0; i<9; i++) {
        for(int j=0; j<9; j++) {
            if(DP[i][j] == -1) cout << "덫" << ' ';
            else cout << DP[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;
    
    cout << "이 쥐는 최대 " << DP[0][8] << "개의 치즈를 먹을 수 있습니다." << endl;
    return 0;
}
