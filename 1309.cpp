#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long dp[100001][3]={0, };
    long long mod = 9901;
    int n; cin>>n;

    for(int i=0; i<=2; i++) dp[0][i]=1;

    for(int i=1; i<n; i++){
      dp[i][0] = (dp[i-1][0]+dp[i-1][1]+dp[i-1][2])%mod;
      dp[i][1] = (dp[i-1][0]+dp[i-1][2])%mod;
      dp[i][2] = (dp[i-1][0]+dp[i-1][1])%mod;
    }

    long long res = 0;
    for(int i=0; i<=2; i++) res+=dp[n-1][i];
    cout<<res%mod<<"\n";
    return 0;
}
