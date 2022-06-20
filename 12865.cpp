#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int dp[101][100001]={0, };
int weight[101]={0,}; int value[101]={0,};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, k, w, v;
    cin>>n>>k; // n: 물품의 수, k: 버틸 수 있는 무게

    for(int i=1; i<=n; i++){
        cin>>w>>v; // 무게, 가치 입력받기
        weight[i]=w; value[i]=v;
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=k; j++){
            if(weight[i]<=j) dp[i][j]=max(value[i]+dp[i-1][j-weight[i]], dp[i-1][j]);
            else dp[i][j]=dp[i-1][j];
        }
    }

    cout<<dp[n][k]<<endl;
    return 0;
}
