#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int ch[100001]={0, };
  int n, s=1, t=0, c=0; queue<pair<pair<int, int>, int>> q; // s:화면, c:클립보드, t:시간
  cin>>n;
  ch[1]=1; q.push({{s, t}, c});

  while(!q.empty()){
    s = q.front().first.first; c = q.front().first.second; t = q.front().second; q.pop();
    if(s==n) break;

    if(1){
      q.push({{s, s+c}, t+1});
    }
    if(c!=0 && ch[s+c]==0){
      ch[s+c]=1; q.push({{s+c, 0}, t+1});
    }
    if(s-1>=0 && ch[s-1]==0){
      ch[s-1]=1; q.push({{s-1, c}, t+1});
    }
  }

  cout<<t<<endl;
  return 0;
}
