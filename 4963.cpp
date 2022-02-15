#include <bits/stdc++.h>
using namespace std;

int a[52][52]={0, };
int ch[52][52]={0, };
vector<int> res;
int tmp;

void DFS(int u, int v){
  ch[u][v]=1;

  // 상,하,좌,우,대각선에 대해서 dfs수행
  if(ch[u][v-1]==0 && a[u][v-1]==1) DFS(u, v-1);
  if(ch[u][v+1]==0 && a[u][v+1]==1) DFS(u, v+1);
  if(ch[u-1][v]==0 && a[u-1][v]==1) DFS(u-1, v);
  if(ch[u+1][v]==0 && a[u+1][v]==1) DFS(u+1, v);

  if(ch[u+1][v+1]==0 && a[u+1][v+1]==1) DFS(u+1, v+1);
  if(ch[u+1][v-1]==0 && a[u+1][v-1]==1) DFS(u+1, v-1);
  if(ch[u-1][v+1]==0 && a[u-1][v+1]==1) DFS(u-1, v+1);
  if(ch[u-1][v-1]==0 && a[u-1][v-1]==1) DFS(u-1, v-1);
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    while(1){
      int w, h; cin>>h>>w;
      if(w==0 && h==0) break;
      
      for(int i=1; i<=w; i++){
        for(int j=1; j<=h; j++){
          int tmp; cin>>tmp;
          a[i][j]=tmp;
        }
      } // 입력받기 끝

      int tmp=0;
      for(int i=1; i<=w; i++){
        for(int j=1; j<=h; j++){
          if(ch[i][j]==0 && a[i][j]==1){
            DFS(i, j);
            tmp++;
          }
        }
      }
      cout<<tmp<<"\n"; // 섬의 개수 출력

      for(int i=1; i<=w; i++){
        for(int j=1; j<=h; j++){
          ch[i][j]=0;
          a[i][j]=0;
        }
      } // a배열, ch배열 초기화

    } // while문 끝
    return 0;
}
