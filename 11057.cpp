#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long dp[1001][10]={0, };
    long long mod = 10007;
    int n; cin>>n;

    for(int i=0; i<=9; i++) dp[1][i]=1;

    for(int i=1; i<=n; i++){
      for(int j=0; j<=9; j++){
        for(int k=0; k<=j; k++){
          dp[i][j] += dp[i-1][k];
        }
        dp[i][j]%=mod;
      }
    }

    long long res = 0;
    for(int i=0; i<=9; i++) res+=dp[n][i];
    cout<<res%mod<<"\n";
    return 0;
}
