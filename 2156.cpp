#include <bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long dp[10001][2]={0, };
    long long a[10001]={0, };
    int n, tmp;
    cin>>n>>tmp;
    a[1]=tmp; dp[1][0]=0; dp[1][1]=tmp;
    cin>>tmp;
    a[2]=tmp; dp[2][0]=a[1]; dp[2][1]=(a[1]+tmp);

    for(int i=3; i<=n; i++){
      cin>>tmp;
      a[i]=tmp;

      dp[i][0]=max(dp[i-1][0], dp[i-1][1]);
      dp[i][1]=max(dp[i-2][0]+a[i-1]+tmp, dp[i-1][0]+tmp);
    }

    long long res = max(dp[n][0], dp[n][1]);
    cout<<res<<"\n";
    return 0;
}
