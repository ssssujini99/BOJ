#include <iostream>
#include <vector>
using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int dp[41][41];
  dp[0][0]=1; dp[0][1]=0; dp[1][0]=0; dp[1][1]=1;

  for(int i=2; i<=40; i++){
      dp[i][0] = (dp[i-1][0] + dp[i-2][0]);
      dp[i][1] = (dp[i-1][1] + dp[i-2][1]);
  }
  
  int n; vector<int> v;
  cin>>n; 
  for(int i=0; i<n; i++){
      int tmp; cin>>tmp; v.push_back(tmp);
  }
  for(int i=0; i<v.size(); i++){
      cout<<dp[v[i]][0]<<" "<<dp[v[i]][1]<<"\n";
  }
  return 0;
}
