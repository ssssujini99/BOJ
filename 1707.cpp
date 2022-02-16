#include <bits/stdc++.h>
using namespace std;

vector<int> vec[20001]; int ch[20001]={0, };

void DFS(int num, int col){
  for(int i=0; i<vec[num].size(); i++){
    if(ch[vec[num][i]]==0){ // 방문하지 않았던 지점인 경우에만
      ch[vec[num][i]]=3-col;
      DFS(vec[num][i], 3-col);
    }
  }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int c, v, e; cin>>c;

    while(c--){
      int state=1;
      cin>>v>>e; // 정점: 1~v 까지
      for(int i=0; i<e; i++){
        int t1, t2; cin>>t1>>t2;
        vec[t1].emplace_back(t2); vec[t2].emplace_back(t1);
      }
      for(int i=1; i<=v; i++){
        if(ch[i]==0){ // 아직 방문하지 않은 정점에 대해서만
          ch[i]=1;
          DFS(i, 1); // (시작점, 시작점색깔)
        }
      }

      for(int i=1; i<=v; i++){
        for(int j=0; j<vec[i].size(); j++){
          if(ch[i]==ch[vec[i][j]]){
            cout<<"N0\n";
            state=0;
            break;
          }
        }
        if(!state) break;
      }
      if(state) cout<<"Yes\n";

      for(int i=1; i<=v; i++){
        vec[i].clear();
        ch[i]=0;
      } // 초기화세팅

    } // while문 끝

    return 0;
}
