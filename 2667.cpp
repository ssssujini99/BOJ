#include <bits/stdc++.h>
using namespace std;

int a[28][28]={0, };
int ch[28][28]={0, };
vector<int> res;
int tmp;

void DFS(int u, int v){
  ch[u][v]=1;
  tmp++;
  // 상,하,좌,우에 대해서 dfs수행
  if(ch[u][v-1]==0 && a[u][v-1]==1) DFS(u, v-1);
  if(ch[u][v+1]==0 && a[u][v+1]==1) DFS(u, v+1);
  if(ch[u-1][v]==0 && a[u-1][v]==1) DFS(u-1, v);
  if(ch[u+1][v]==0 && a[u+1][v]==1) DFS(u+1, v);
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin>>n;
    for(int i=1; i<=n; i++){
      string s;
      cin>>s;
      for(int j=0; j<s.size(); j++){
        if(s[j]=='0') a[i][j+1]=0;
        else a[i][j+1]=1;
      }
    }
    int cnt=0;
    for(int i=1; i<=n; i++){
      for(int j=1; j<=n; j++){
        tmp=0; // 집의 개수
        if(ch[i][j]==0 && a[i][j]==1){
          DFS(i, j);
          cnt++; // 총 단지 수
        }
        if(tmp) res.push_back(tmp);
      }
    }
    sort(res.begin(), res.end());
    cout<<cnt<<"\n";
    for(int i=0; i<res.size(); i++){
      cout<<res[i]<<"\n";
    }
    return 0;
}
