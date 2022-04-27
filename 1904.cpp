#include <iostream>
#include <vector>
#define MOD 15746
using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int dp[1000000]; int n; cin>>n;
  dp[1]=1; dp[2]=2;

  for(int i=3; i<=n; i++){
      dp[i] = dp[i-1] + dp[i-2];
      dp[i] = dp[i]%MOD;
  }

  cout<<dp[n]<<"\n";
  return 0;
}
