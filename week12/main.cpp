#include <iostream>

using namespace std;

#define N 5 // 정점 수
#define INF 1000

void floyd2(int n, const int(*W)[N+1], int(*D)[N+1], int(*P)[N+1]);
void path(int(*P)[N+1], int q, int r);

int main() {
    // weight 행렬
    int W[N+1][N+1] = {
        {0, 0, 0, 0, 0, 0},
        {0, 0, 1, INF, 1, 5},
        {0, 9, 0, 3, 2, INF},
        {0, INF, INF, 0, 4, INF},
        {0, INF, INF, 2, 0, 3},
        {0, 3, INF, INF, INF, 0}
    };
    
    int D[N+1][N+1];
    int P[N+1][N+1]; // 최종 경로를 저장
    
    floyd2(N, W, D, P);
    
    cout << "D[i][j] is" << endl;
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=N; j++) {
            cout << D[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
    
    cout << "P[i][j] is" << endl;
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=N; j++) {
            cout << P[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
    
    int start, end;
    start = 5;
    end = 3;
    cout << "The shortest path(" << start << ", " << end << ") is ";
    cout << "v" << start << " -> ";
    path(P, start, end);
    cout << "v" << end << endl;
    cout << "shortest distance: " << D[start][end] << endl;
    cout << endl;
    
    cout << "D[i][j] is" << endl;
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=N; j++) {
            cout << D[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
    
    cout << "P[i][j] is" << endl;
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=N; j++) {
            cout << P[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';

    start = 1;
    end = 3;
    cout << "The shortest path(" << start << ", " << end << ") is ";
    cout << "v" << start << " -> ";
    path(P, start, end);
    cout << "v" << end << endl;
    cout << "shortest distance: " << D[start][end] << endl;
    cout << endl;
    
    cout << "D[i][j] is" << endl;
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=N; j++) {
            cout << D[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
    
    cout << "P[i][j] is" << endl;
    for (int i=1; i<=N; i++) {
        for (int j=1; j<=N; j++) {
            cout << P[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
    
    start = 2;
    end = 5;
    cout << "The shortest path(" << start << ", " << end << ") is ";
    cout << "v" << start << " -> ";
    path(P, start, end);
    cout << "v" << end << endl;
    cout << "shortest distance: " << D[start][end] << endl;
    cout << endl;
    return 0;
}

void floyd2(int n, const int(*W)[N+1], int(*D)[N+1], int(*P)[N+1]) {
    // P 배열 초기화
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            P[i][j] = 0;
        }
    }
    
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            D[i][j] = W[i][j];
        }
    }
    
    for (int k=1; k<=n; k++) {
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=n; j++) {
                // 새로운 정점 k를 추가하여 k를 거치는 것이 더 빠르다면
                if(D[i][k] + D[k][j] < D[i][j]) {
                    P[i][j] = k;
                    D[i][j] = D[i][k] + D[k][j];
                }
            }
        }
    }
}

// P 배열을 이용하여 경로를 출력
void path(int(*P)[N+1], int q, int r) {
    if (P[q][r] != 0) {
        path(P, q, P[q][r]);
        cout << "v" << P[q][r] << " -> ";
        path(P, P[q][r], r);
    }
}
