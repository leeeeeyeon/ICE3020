#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int knapsack(const vector<int>& weights, const vector<int>& values, const int W){
    const int N = (int)weights.size(); // 보석의 개수
    vector<vector<int>> P(W + 1, vector<int>(N+1, 0)); // 최고의 이익을 담을 벡터
    
    for (int i = 1; i <= N; i++) {
        for (int w = 1; w <= W; w++) {
            // i번째 항목을 포함하지 않았을 경우 배낭에 여유가 있음
            if (weights[i - 1] <= w) {
                // i번째 항목을 넣었을 때와 안 넣었을 때를 비교하여 더 큰 값을 선택
                P[w][i] = max(P[w][i - 1], P[w - weights[i - 1]][i - 1] + values[i - 1]);
                
            }
            // i번째 항목을 포함하지 않았을 경우 배낭이 가득참
            else {
                P[w][i] = P[w][i - 1];
                
            }
            
        }
        
    }
    return P[W][N]; // 무게가 W를 넘지 않고 N번째 까지의 항목 중에서 얻어진 최대 이익
    
}

void prob1() {
    const int W = 15;
    vector<int> w{ 5, 10, 7, 3, 4, 11 };
    vector<int> value{ 5, 7, 10, 6, 8, 20 };
    cout << "입력 1에 대하여 가방에 담을 보석의 최대 가치: " << knapsack(w, value, W) << "\n";
}

void prob2() {
    const int W = 30;
    vector<int> w{ 3, 7, 8, 5, 6, 13, 11, 2 };
    vector<int> value{ 5, 7, 10, 6, 8, 20, 18, 5 };
    cout << "입력 2에 대하여 가방에 담을 보석의 최대 가치: " << knapsack(w, value, W) << "\n";
}

int main(){
    prob1();
    prob2();
    
    return 0;
}
