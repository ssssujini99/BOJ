#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n; cin>>n;
  queue<int> q;
  for(int i=1; i<=n; i++) q.push(i);

  while(q.size()!=1){
    q.pop();
    int tmp = q.front(); q.pop();
    q.push(tmp);
  }
  cout<<q.front();
  return 0;
}
