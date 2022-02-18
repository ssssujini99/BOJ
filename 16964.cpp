#include <bits/stdc++.h>
using namespace std;

vector<int> v[100001]; int ch[100001]={0, }; int a[100001]={0, };
vector<int> res; vector<int> cp;

bool cmp(int t1, int t2){
  return a[t1]<a[t2];
}

void DFS(int n){
  res.emplace_back(n);

  for(int i=0; i<v[n].size(); i++){
    if(ch[v[n][i]]==0){
      ch[v[n][i]]=1;
      DFS(v[n][i]);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n; cin>>n;
  for(int i=0; i<n-1; i++){
    int t1, t2; cin>>t1>>t2;
    v[t1].emplace_back(t2); v[t2].emplace_back(t1);
  }
  for(int i=1; i<=n; i++){
    int tmp; cin>>tmp; a[tmp]=i;
    cp.emplace_back(tmp);
  }
  if(a[1]!=1) { cout<<"0"; return 0; } // 예외처리

  for(int i=1; i<=n; i++) sort(v[i].begin(), v[i].end(), cmp);
  ch[1]=1;
  DFS(1);

  if(cp==res) cout<<"1";
  else cout<<"0";
  return 0;
}
