#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int c, l; cin>>c;

    while(c--){
      cin>>l; // 체스판 한한 변의 길이
      
      int ch[302][302]={0, };
      queue<pair<pair<int, int>, int>> q;
      int s1, s2, f1, f2; cin>>s1>>s2>>f1>>f2;
      s1++; s2++; f1++; f2++; // 양변 테두리 맞추기

      int res=0;
      ch[s1][s2]=1;
      q.push({{s1, s2}, res});

      // bfs 수행
      while(!q.empty()){
        pair<pair<int, int>, int> p = q.front(); q.pop();
        int i = p.first.first; int j = p.first.second;
        res = p.second;
        if(i==f1 && j==f2) break;

        if(ch[i-1][j-2]==0 && i-1>=1 && j-2>=1){
          ch[i-1][j-2]=1; q.push({{i-1, j-2}, res+1});
        }
        if(ch[i-2][j-1]==0 && i-2>=1 && j-1>=1){
          ch[i-2][j-1]=1; q.push({{i-2, j-1}, res+1});
        }

        if(ch[i-2][j+1]==0 && i-2>=1 && j+1<=l){
          ch[i-2][j+1]=1; q.push({{i-2, j+1}, res+1});
        }
        if(ch[i-1][j+2]==0 && i-1>=1 && j+2<=l){
          ch[i-1][j+2]=1; q.push({{i-1, j+2}, res+1});
        }

        if(ch[i+1][j+2]==0 && i+1<=l && j+2<=l){
          ch[i+1][j+2]=1; q.push({{i+1, j+2}, res+1});
        }
        if(ch[i+2][j+1]==0 && i+2<=l && j+1<=l){
          ch[i+2][j+1]=1; q.push({{i+2, j+1}, res+1});
        }

        if(ch[i+2][j-1]==0 && i+2<=l && j-1>=1){
          ch[i+2][j-1]=1; q.push({{i+2, j-1}, res+1});
        }
        if(ch[i+1][j-2]==0 && i+1<=l && j-2>=1){
          ch[i+1][j-2]=1; q.push({{i+1, j-2}, res+1});
        }
      } // bfs 끝

      cout<<res<<"\n";
    } // while문 끝

    return 0;
}
