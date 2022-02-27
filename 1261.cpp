#include <bits/stdc++.h>
using namespace std;

int a[101][101]={0, }; queue<pair<int, int>> q; int m, n, start=0;
int d[101][101]={0, };

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin>>m>>n;
  for(int i=1; i<=n; i++){
    string str; cin>>str;
    for(int j=0; j<str.size(); j++){
      a[i][j+1]=str[j]-'0';
      d[i][j+1]=INT_MAX;
    }
  }
  
  q.push({1, 1}); d[1][1]=0;
  int dx[4]={-1, 0, 1, 0}; int dy[4]={0, 1, 0, -1};
  int x, y, dis;

  while(!q.empty()){
    x = q.front().first; y = q.front().second; dis = d[x][y]; q.pop();

    for(int i=0; i<4; i++){
        int sx = x + dx[i]; int sy = y + dy[i];

        if(sx>=1 && sx<=n && sy>=1 && sy<=m){ // 범위 만족 시
          if(a[sx][sy]==1){
            if(d[x][y]+1 < d[sx][sy]) { d[sx][sy] = d[x][y]+1; q.push({sx, sy}); }
          }
          else{ // a[sx][sy]==0
            if(d[x][y]<d[sx][sy]) { d[sx][sy]=d[x][y]; q.push({sx, sy}); }
          }
        }
    }
  }

  cout<<d[n][m]<<endl;
  return 0;
}
