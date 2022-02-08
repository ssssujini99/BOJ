#include <bits/stdc++.h>
using namespace std;

int n, m;
int ch[9]={0, };
int res[9]={0, };

void DFS(int k){
  if(k==m+1){
    for(int i=1; i<=m; i++) cout<<res[i]<<" ";
    cout<<"\n";
  }
  else{
    for(int i=1; i<=n; i++){
      if(!ch[i]){
        ch[i]=1;
        res[k]=i;
        DFS(k+1);
        ch[i]=0;
      }
    }
  }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>n>>m;
    DFS(1);

    return 0;
}
