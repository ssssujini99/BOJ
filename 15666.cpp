#include <bits/stdc++.h>
using namespace std;

int n, m;
int ch[9]={0, }; // 중복 여부 확인 배열
int res[9]={0, }; // 결과 배열
vector<int> v;

void DFS(int idx){
  if(idx==m){
    for(int i=1; i<=m; i++) cout<<res[i]<<" ";
    cout<<"\n";
  }
  else{
    for(int i=0; i<n; i++){
      if(res[idx]<=v[i]){
        res[idx+1]=v[i];
        DFS(idx+1);
      }
    }
  }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>n>>m;
    for(int i=0; i<n; i++){
      int tmp; cin>>tmp;
      v.push_back(tmp);
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    n=v.size();
    DFS(0);

    return 0;
}
