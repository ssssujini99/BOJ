#include <bits/stdc++.h>
using namespace std;

int n, m, state=0;
vector<int> v[2001];
int ch[2001]={0, };

void DFS(int k, int cnt){
  if(cnt==5){
    state=1;
    return;
  }
  else{
    for(int i=0; i<v[k].size(); i++){
      if(ch[v[k][i]]==0){
        ch[v[k][i]]=1;
        DFS(v[k][i], cnt+1);
        ch[v[k][i]]=0;
      }
    }
  }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>n>>m;
    for(int i=0; i<m; i++){
      int a, b; cin>>a>>b;
      v[a].emplace_back(b); v[b].emplace_back(a);
    }

    for(int i=0; i<n; i++){
      ch[i]=1;
      DFS(i, 1);
      ch[i]=0;
      if(state) break;
    }

    cout<<state<<"\n";
    return 0;
}
