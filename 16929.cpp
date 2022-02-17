#include <bits/stdc++.h>
 using namespace std;

 char a[52][52]={0, };
 int ch[52][52]={0, };
 int n, m, k1, k2, depth, state;

bool DFS(int t1, int t2, int ex1, int ex2, char col){

  if(ch[t1][t2]==1){
    return true;
  }
  ch[t1][t2]=1;

  if(a[t1+1][t2]==col && t1+1<=n && !(t1+1 == ex1 && t2 == ex2)){
    if(DFS(t1+1, t2, t1, t2, col)) return true;
  }
  if(a[t1][t2+1]==col && t2+1<=m && !(t1 == ex1 && t2+1 == ex2)){
    if(DFS(t1, t2+1, t1, t2, col)) return true;
  }
  if(a[t1-1][t2]==col && t1-1>=0 && !(t1-1 == ex1 && t2 == ex2)){
    if(DFS(t1-1, t2, t1, t2, col)) return true;
  }
  if(a[t1][t2-1]==col && t2-1>=0 && !(t1 == ex1 && t2-1 == ex2)){
    if(DFS(t1, t2-1, t1, t2, col)) return true;
  }

  return false;
}

 int main() {
     ios_base::sync_with_stdio(false);
     cin.tie(nullptr);

     int state=0; cin>>n>>m;
     for(int i=1; i<=n; i++){
       string str; cin>>str;
       for(int j=0; j<str.size(); j++){
         a[i][j+1]=str[j];
       }
     }

     for(int i=1; i<=n; i++){
       for(int j=1; j<=m; j++){
         state=0;
         // 모든 점에 대해서 사이클 찾기(dfs수행)
         if(ch[i][j]==0){
           bool state=DFS(i, j, 0, 0, a[i][j]);

           if(state){
             cout<<"Yes"<<endl;
             return 0;
           }
         }
       }
     } // 전체 for문 끝

     
     cout<<"No";
     return 0;
 }
