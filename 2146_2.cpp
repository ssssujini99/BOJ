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
  int d[101][101]; memset(d, -1, sizeof(d)); // d 배열: 거리 배열이자 체크 배열
  queue<pair<int, int>> q;
    
  for(int i=1; i<=n; i++){
    for(int j=1; j<=n; j++){
      if(ch[i][j]!=0){ // 모든 섬들에 대해서
        d[i][j]=0; q.push({i, j});
      }
    }
  }

  while(!q.empty()){
    int x = q.front().first; int y = q.front().second; q.pop();
      
    if(x+1<=n && d[x+1][y]==-1) { ch[x+1][y]=ch[x][y]; d[x+1][y]=d[x][y]+1; q.push({x+1, y}); }
    if(y+1<=n && d[x][y+1]==-1) { ch[x][y+1]=ch[x][y]; d[x][y+1]=d[x][y]+1; q.push({x, y+1}); }
    if(x-1>=1 && d[x-1][y]==-1) { ch[x-1][y]=ch[x][y]; d[x-1][y]=d[x][y]+1; q.push({x-1, y}); }
    if(y-1>=1 && d[x][y-1]==-1) { ch[x][y-1]=ch[x][y]; d[x][y-1]=d[x][y]+1; q.push({x, y-1}); }
  } // bfs 끝

  int ans = 100000; int dx[4] = {-1, 0, 1, 0}; int dy[4] = {0, 1, 0, -1};
  for(int i=1; i<=n; i++){
    for(int j=1; j<=n; j++){
      int dis = d[i][j]; int col = ch[i][j];

      // 상, 하, 좌, 우 를 검토 시 서로 다른 섬이면 다리를 놓을 수 있음
      for(int k=0; k<4; k++){
        int x = i+dx[k]; int y = j+dy[k];
        if(x>=1 && x<=n && y>=1 && y<=n && ch[x][y]!=col){
          int tmp_dis = dis + d[x][y];
          if(tmp_dis < ans) ans=tmp_dis;
        }
      }
    }
  }
  
  cout<<ans<<endl;
  return 0;
}
