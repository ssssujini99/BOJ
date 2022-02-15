#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int a[102][102]={0, };
    int ch[102][102]={0, };
    queue<pair<pair<int, int>, int>> q;
    int n, m, res, tmp;

    cin>>n>>m;
    for(int i=1; i<=n; i++){
      string s;
      cin>>s;
      for(int j=0; j<s.size(); j++){
        if(s[j]=='0') a[i][j+1]=0;
        else a[i][j+1]=1;
      }
    } // 배열 입력 완료

    tmp=1;
    ch[1][1]=1;
    q.push({{1,1}, tmp});
    
    // bfs 수행
    while(!q.empty()){
      pair<pair<int, int>, int> p = q.front(); q.pop();
      int i = p.first.first; int j = p.first.second;
      tmp = p.second;
      if(i==n && j==m){
        res=p.second;
        break;
      }

      if(a[i+1][j]==1 && ch[i+1][j]==0){
        ch[i+1][j]=1;
        q.push({{i+1, j}, tmp+1});
      }
      if(a[i-1][j]==1 && ch[i-1][j]==0){
        ch[i-1][j]=1;
        q.push({{i-1, j}, tmp+1});
      }
      if(a[i][j+1]==1 && ch[i][j+1]==0){
        ch[i][j+1]=1;
        q.push({{i, j+1}, tmp+1});
      }
      if(a[i][j-1]==1 && ch[i][j-1]==0){
        ch[i][j-1]=1;
        q.push({{i, j-1}, tmp+1});
      }
    }

    cout<<res<<endl;
    return 0;
}
