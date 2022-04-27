#include <iostream>
#include <vector>
using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  long long dp[301]; int a[301]; int n;

  cin>>n;
  for(int i=0; i<n; i++) cin>>a[i+1]; // 계단 idx: 1부터 시작
  
  dp[1]=a[1], dp[2]=a[1]+a[2]; dp[3]=a[3]+max(a[1], a[2]);// 초기 조건 세팅
  for(int i=4; i<=n; i++){
      dp[i] = a[i] + max(a[i-1]+dp[i-3], dp[i-2]);
  }

  cout<<dp[n]<<"\n";
  return 0;
}
