#include <bits/stdc++.h>
 using namespace std;

 char a[52][52]={0, };
 int ch[52][52]={0, };
 int n, m; bool state=0;

 bool DFS(int i1, int i2, int o1, int o2, char c){
   if(ch[i1][i2]) return true;

   ch[i1][i2]=1;

   if(a[i1+1][i2]==c && i1+1<=n && !(i1+1==o1 && i2==o2)){
     bool res = DFS(i1+1, i2, i1, i2, c);
     if(res) return true;
   }
   if(a[i1][i2+1]==c && i2+1<=m && !(i1==o1 && i2+1==o2)){
     bool res = DFS(i1, i2+1, i1, i2, c);
     if(res) return true;
   }
   if(a[i1-1][i2]==c && i1-1>=0 && !(i1-1==o1 && i2==o2)){
     bool res = DFS(i1-1, i2, i1, i2, c);
     if(res) return true;
   }
   if(a[i1][i2-1]==c && i2-1>=0 && !(i1==o1 && i2-1==o2)){
     bool res = DFS(i1, i2-1, i1, i2, c);
     if(res) return true;
   }

   return false;
 }




 int main() {
     ios_base::sync_with_stdio(false);
     cin.tie(nullptr);

     cin>>n>>m;
     for(int i=1; i<=n; i++){
       string str; cin>>str;
       for(int j=0; j<str.size(); j++){
         a[i][j+1]=str[j];
       }
     } // 입력 끝

     for(int i=1; i<=n; i++){
       for(int j=1; j<=m; j++){

         if(ch[i][j]==0){
           state = DFS(i, j, 0, 0, a[i][j]);
           if(state){
             cout<<"Yes";
             return 0;
           }
         }

       }
     }
     cout<<"No";
     return 0;
 }
