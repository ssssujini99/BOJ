#include <bits/stdc++.h>
using namespace std;

long long dp[100001][4]={0, };
long long MOD = 1000000009;

void func(void){
  dp[1][1]=dp[2][2]=dp[3][1]=dp[3][2]=dp[3][3]=1;

  for(int i=4; i<=100000; i++){
    dp[i][1]=(dp[i-1][2]+dp[i-1][3]) % MOD;
    dp[i][2]=(dp[i-2][1]+dp[i-2][3]) % MOD;
    dp[i][3]=(dp[i-3][2]+dp[i-3][1]) % MOD;
  }

}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, tmp;
    long long res;
    func();
    cin>>n;
    for(int i=0; i<n; i++){
      cin>>tmp;
      res=(dp[tmp][1]+dp[tmp][2]+dp[tmp][3])%MOD;
      cout<<res<<endl;
    }
    
    return 0;
}
