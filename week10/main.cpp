#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 배열의 값이 주어졌을 때 해당 원소의 인덱스를 찾는 함수
int findIndex(int arr[], int item) {
    for (int j = 0; j < 9; j++) {
        if (arr[j] == item)
            return j;
    }

    return -1;
}

// 배열의 최댓값을 찾는 함수
int findMax(int arr[]) {
    int max = arr[0];
    for (int j = 1; j < 9; j++) {
        if (arr[j] > max) max = arr[j];
    }
    
    return max;
}

int main() {
    int DP[1000][1000] = { 0 }; // 숫자의 누적합을 저장할 배열
    vector<int> route; // 경로를 저장할 벡터
    
    // 숫자판 배열
    int map[8][9] = {
        {3, 4, 9, -2, 2, 51, -23, 2, -1},
        {223, 7,  8, -11, 5, -99, 2, 3, -4},
        {2, 51, -23, -23, 6, 3, 2, 4, 5},
        {5, -99, 2, -1, 32, 2, 5, -99, 2},
        {6, 3, 3, -4, 2, -1, 6, 3, 3},
        {32, 2, 4, 5, 3, -4, 2, -1, 4},
        {4, 4, 23, 6, 2, -1, 3, -4, 34},
        {78, 32, 1, 7, 3, -4, -23, -23, 6}
    };
    
    for(int i=0; i<8; i++) { // 행
        for(int j=0; j<9; j++) { // 열
            if (i == 0) {
                DP[i][j] = map[i][j];
            }
            if (j == 0) {
                DP[i][j] = max(DP[i-1][j], DP[i-1][j+1]) + map[i][j];
            }
            else {
                DP[i][j] = max({DP[i-1][j-1], DP[i-1][j], DP[i-1][j+1]}) + map[i][j];
            }
        }
    }
    
    // 숫자판 출력
    for(int i=0; i<8; i++) {
        for(int j=0; j<9; j++) {
            cout << DP[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;
    
    // 최댓값 출력
    int m = DP[7][0];
    for(int j=1; j<9; j++) {
        if(DP[7][j] > m) m = DP[7][j];
    }
    cout << "max: " << m << endl;
    cout << endl;
    
    // 경로 출력
    int finalMax = 0;
    int maxOfrow = 0;
    int index = 0;
    for(int i=7; i>=0; i--) {
        if (i==7) {
            finalMax = findMax(DP[7]);
            index = findIndex(DP[7], finalMax);
            route.push_back(map[7][index]);
        }
        else {
            if (index==0) {
                maxOfrow = max(DP[i][index], DP[i][index+1]);
                index = findIndex(DP[i], maxOfrow);
                route.push_back(map[i][index]);
            }
            else {
                maxOfrow = max({DP[i][index-1], DP[i][index], DP[i][index+1]});
                index = findIndex(DP[i], maxOfrow);
                route.push_back(map[i][index]);
            }
        }
    }
    
    reverse(route.begin(), route.end());
    cout << "경로: ";
    for(int i=0; i<route.size(); i++) cout << route[i] << ' ';
    cout << endl;
    return 0;
}
