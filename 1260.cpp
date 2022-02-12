#include <bits/stdc++.h>
using namespace std;

int n, m, start;
int v[1001][1001]={0, };
int ch1[1001]={0, };
int ch2[1001]={0, };
queue<int> q;

void DFS(int k){
  cout<<k<<" ";

  for(int i=1; i<=n; i++){
    if(v[k][i]==1 && ch1[i]==0){
      ch1[i]=1;
      DFS(i);
    }
  }
}

void BFS(int k){
  while(!q.empty()){
    cout<<q.front()<<" ";
    int tmp = q.front();
    q.pop();

    for(int i=1; i<=n; i++){
      if(v[tmp][i]==1 && ch2[i]==0){
        ch2[i]=1;
        q.push(i);
      }
    } // for문 끝

  } // while문 끝
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>n>>m>>start;

    for(int i=0; i<m; i++){
      int a, b; cin>>a>>b;
      v[a][b]=1; v[b][a]=1;
    }

    ch1[start]=1;
    DFS(start);
    cout<<endl;

    ch2[start]=1;
    q.push(start);
    BFS(start);

    return 0;
}
