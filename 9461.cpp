#include <iostream>
#include <vector>
using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  long long dp[101];
  dp[1]=1; dp[2]=1; dp[3]=1; dp[4]=2; dp[5]=2;

  for(int i=6; i<=100; i++){
      dp[i] = dp[i-1] + dp[i-5];
  }

  int n; vector<int> v;
  cin>>n;
  for(int i=0; i<n; i++){
      int tmp; cin>>tmp; v.push_back(tmp);
  }
  for(int i=0; i<v.size(); i++){
      cout<<dp[v[i]]<<"\n";
  }
  return 0;
}
