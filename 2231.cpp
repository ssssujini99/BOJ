#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, res=0; cin>>n;

  for(int i=1; i<=n; i++){
    queue<int> q; int t = 10; int tmp = i;

    while(tmp){
      q.push(tmp%t);
      tmp/=t;
    }

    int sum=0;
    while(!q.empty()){
      sum+=q.front(); q.pop();
    }
    if(i+sum==n) { res=i; break; } // 가장 작은 생성자 찾기
  }
  cout<<res<<endl;
  return 0;
}
