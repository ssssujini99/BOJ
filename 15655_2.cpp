#include <bits/stdc++.h>
using namespace std;

vector<int> v;
int res[9]={0, };
int ch[10001]={0, };
int n, m, s=0;

void DFS(int cnt){
  if(cnt==m+1){
    for(int i=1; i<=m; i++){
      cout<<res[i]<<" ";
    }
    cout<<"\n";
  }
  else{
    for(int i=0; i<n; i++){
      if(!ch[v[i]] && res[cnt-1]<v[i]){
        res[cnt]=v[i];
        ch[v[i]]=1;
        DFS(cnt+1);
        ch[v[i]]=0;
      }
    }
  }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>n>>m;
    int tmp;
    for(int i=1; i<=n; i++){
      cin>>tmp; v.push_back(tmp);
    }
    sort(v.begin(), v.end());
    DFS(1);
    return 0;
}
