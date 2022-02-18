#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m; cin>>n>>m;
  queue<int> q; vector<int> res;
  for(int i=1; i<=n; i++) q.push(i);

  while(!q.empty()){
    for(int i=0; i<m-1; i++){
      int tmp = q.front(); q.pop();
      q.push(tmp);
    }
    res.push_back(q.front()); q.pop();
  }

  cout<<"<";
  for(int i=0; i<res.size()-1; i++) cout<<res[i]<<", ";
  cout<<res[res.size()-1]<<">";
  return 0;
}
