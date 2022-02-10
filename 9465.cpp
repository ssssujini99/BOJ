#include <bits/stdc++.h>
using namespace std;

int a[2][100001]={0, };

void func(int l){
  long long dp[100001][3]={0, };
  dp[0][0]=0; dp[0][1]=a[0][0]; dp[0][2]=a[1][0];

  for(int i=1; i<l; i++){
    dp[i][0] = max(dp[i-1][0],dp[i-1][1]);
    dp[i][0] = max(dp[i][0], dp[i-1][2]);
    dp[i][1] = (a[0][i]) + max(dp[i-1][0],dp[i-1][2]);
    dp[i][2] = (a[1][i]) + max(dp[i-1][0],dp[i-1][1]);
  }

  long long max_el = max(dp[l-1][0], dp[l-1][1]);
  max_el = max(max_el, dp[l-1][2]);
  cout<<max_el<<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, tmp; cin>>n;
    for(int i=0; i<n; i++){
      cin>>tmp; int len=tmp;
      for(int j=0; j<2; j++){
        for(int k=0; k<len; k++){
          cin>>tmp; a[j][k]=tmp;
        }
      }
      func(len);
    }
    return 0;
}
