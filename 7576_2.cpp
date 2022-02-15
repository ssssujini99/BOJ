#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int a[1002][1002]={0, };
    int ch[1002][1002]={0, };
    queue<pair<pair<int, int>, int>> q;
    int n, m, res;

    cin>>n>>m;
    for(int i=1; i<=m; i++){
      for(int j=1; j<=n; j++){
        int tmp; cin>>tmp;
        a[i][j]=tmp;
      }
    } // 배열 입력 완료

    for(int i=1; i<=m; i++){
      for(int j=1; j<=n; j++){
        if(a[i][j]==1){
          res=0;
          ch[i][j]=1;
          q.push({{i, j}, res});
        }
      }
    }
    
    // bfs 수행
    while(!q.empty()){
      pair<pair<int, int>, int> p = q.front(); q.pop();
      int i = p.first.first; int j = p.first.second; res=p.second;
      

      if(a[i+1][j]==0 && ch[i+1][j]==0 && i+1<=m){
        ch[i+1][j]=1;
        q.push({{i+1, j}, res+1});
      }
      if(a[i-1][j]==0 && ch[i-1][j]==0 && i-1>=1){
        ch[i-1][j]=1;
        q.push({{i-1, j}, res+1});
      }
      if(a[i][j+1]==0 && ch[i][j+1]==0 && j+1<=n){
        ch[i][j+1]=1;
        q.push({{i, j+1}, res+1});
      }
      if(a[i][j-1]==0 && ch[i][j-1]==0 && j-1>=1){
        ch[i][j-1]=1;
        q.push({{i, j-1}, res+1});
      }
    } // bfs 끝
    
    for(int i=1; i<=m; i++){
      for(int j=1; j<=n; j++){
        if(a[i][j]==0 && ch[i][j]==0){
          cout<<"-1\n";
          return 0;
        }
      }
    }

    cout<<res<<endl;
    return 0;
}
