#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k; long long dp[201][201]={0, };
    cin>>n>>k;

    dp[0][0]=1;

    for(int i=0; i<=n; i++){
      for(int j=1; j<=k; j++){
        for(int t=0; t<=i; t++){ // 마지막 수가 t로 끝났을 때
          dp[i][j]+=dp[i-t][j-1]; // 0~i까지의 수 j개를 더하여 합이 i가 되는 경우
          dp[i][j]%=1000000000;
        }
      }
    }
    
    cout<<dp[n][k]<<endl;
    return 0;
}
