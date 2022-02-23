#include <bits/stdc++.h>
using namespace std;

int a[101][101]={0, }; int ch[101][101]={0, }; int n;

void DFS(int t1, int t2, int col){
  if(t1+1<=n && a[t1+1][t2]==1 && ch[t1+1][t2]==0){
    ch[t1+1][t2]=col; DFS(t1+1, t2, col);
  }
  if(t2+1<=n && a[t1][t2+1]==1 && ch[t1][t2+1]==0){
    ch[t1][t2+1]=col; DFS(t1, t2+1, col);
  }
  if(t1-1>=1 && a[t1-1][t2]==1 && ch[t1-1][t2]==0){
    ch[t1-1][t2]=col; DFS(t1-1, t2, col);
  }
  if(t2-1>=1 && a[t1][t2-1]==1 && ch[t1][t2-1]==0){
    ch[t1][t2-1]=col; DFS(t1, t2-1, col);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin>>n;
  for(int i=1; i<=n; i++){
    for(int j=1; j<=n; j++){
      cin>>a[i][j];
    }
  }

  int color = 1;
  for(int i=1; i<=n; i++){
    for(int j=1; j<=n; j++){
      if(ch[i][j]==0 && a[i][j]){
        ch[i][j] = color;
        DFS(i, j, color);
        color++;
      }
    }
  } // 섬마다 구획나누기

  // bfs 시작
  vector<int> res;
// < color
  for(int i=1; i<color; i++){
    int d[101][101]={0, };
    queue<pair<pair<int, int>, int>> q; int col = i;
    
    for(int i=1; i<=n; i++){
      for(int j=1; j<=n; j++){
        if(ch[i][j]==col){
          d[i][j]=1; q.push({{i, j}, 0});
        }
      }
    }

    while(!q.empty()){
      int x = q.front().first.first; int y = q.front().first.second; int dis = q.front().second; q.pop();

      if(ch[x][y]!=0 && ch[x][y]!=col){ res.push_back(dis-1); break; }

      if(x+1<=n && d[x+1][y]==0) { d[x+1][y]=1; q.push({{x+1, y}, dis+1}); }
      if(y+1<=n && d[x][y+1]==0) { d[x][y+1]=1; q.push({{x, y+1}, dis+1}); }
      if(x-1>=1 && d[x-1][y]==0) { d[x-1][y]=1; q.push({{x-1, y}, dis+1}); }
      if(y-1>=1 && d[x][y-1]==0) { d[x][y-1]=1; q.push({{x, y-1}, dis+1}); }
    }
    
  }
  
  sort(res.begin(), res.end());
  cout<<res[0]<<endl;
  return 0;
}
