#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  vector<int> v[100001]; int n;
  int ch[100001]={0, }; int a[100001]={0, };
  cin>>n;
  for(int i=0; i<n-1; i++){
    int t1, t2; cin>>t1>>t2;
    v[t1].emplace_back(t2); v[t2].emplace_back(t1);
  }
  for(int i=1; i<=n; i++) cin>>a[i];
  if(a[1]!=1) { cout<<"0"; return 0;}

  queue<int> q;
  ch[1]=1; q.push(1);
  int idx=2;

  while(!q.empty()){
    int p = q.front(); q.pop();

    int cnt=0;
    for(int i=0; i<v[p].size(); i++){
      if(ch[v[p][i]]==0){
        ch[v[p][i]]=1;
        cnt++;
      }
    }

    for(int i=idx; i<idx+cnt; i++){
      if(!ch[a[i]]){ cout<<"0"; return 0;}
      q.push(a[i]);
    }
    idx+=cnt;
  } // while문 끝

  cout<<"1";
  return 0;
}
