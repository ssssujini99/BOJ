#include <bits/stdc++.h>
using namespace std;

const int INF = 987654321;
int n; int a[16][16]={0, };
int dp[16][(1 << 16)];

int TSP(int current, int visited){
    if(visited == (1<<n) -1) return a[current][0] ? a[current][0] : INF;
    
    if(dp[current][visited] != -1) return dp[current][visited];
    
    dp[current][visited] = INF;
    
    for(int i=0; i<n; i++){
        if(a[current][i] == 0) continue; // 길이 없는 경우
        if(visited & (1 << i)) continue; // 이미 방문한 적이 있는 경우

        dp[current][visited] = min(dp[current][visited], a[current][i] + TSP(i, visited | (1<<i)));
    }
    return dp[current][visited];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> a[i][j];
        }
    } // 입력 끝

    memset(dp, -1, sizeof(dp));

    cout << TSP(0, 1); // 0번에서 시작해서 0번으로 돌아오기
    return 0;
}
