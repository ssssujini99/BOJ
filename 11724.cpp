#include <bits/stdc++.h>
using namespace std;

int n, m, res=0;
vector<int> v[1001];
int ch[1001]={0, };

void DFS(int k){
  for(int i=0; i<v[k].size(); i++){
    if(ch[v[k][i]]==0){
      ch[v[k][i]]=1;
      DFS(v[k][i]);
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

    ch[1]=0; DFS(1); res+=1;
    for(int i=2; i<=n; i++){
      if(ch[i]==0){
        ch[i]=1;
        DFS(i);
        res++;
      }
    }

    cout<<res<<"\n";
    return 0;
}
