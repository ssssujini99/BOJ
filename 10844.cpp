#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long dp[102][10]={0, };
    long long mod=1000000000;
    int n; cin>>n;

    for(int i=1; i<=9; i++) dp[1][i]=1;

    for(int i=2; i<=n; i++){
      for(int j=0; j<=9; j++){
        if(j==0) dp[i][j]+=dp[i-1][1];
        else if(j==9) dp[i][j]+=dp[i-1][8];
        else{ // j가 1~8일때
          dp[i][j]+=(dp[i-1][j-1]+dp[i-1][j+1]);
        }
          dp[i][j]%=mod;
      }
    }

    long long res=0;
    for(int i=0; i<=9; i++) res+=dp[n][i];
    cout<<res%mod<<"\n";

    return 0;
}
