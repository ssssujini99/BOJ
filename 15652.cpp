#include <bits/stdc++.h>
using namespace std;

int n, m;
int ch[9]={0, }; // 중복 여부 확인 배열
int res[9]={0, }; // 결과 배열

void DFS(int idx){
  if(idx==m+1){
    for(int i=1; i<=m; i++) cout<<res[i]<<" ";
    cout<<"\n";
  }
  else{
    for(int i=1; i<=n; i++){
        if(res[idx-1]<=i){ // 오름차순 조건
            res[idx]=i;
            DFS(idx+1);
        }
    }
  }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>n>>m;
    DFS(1);

    return 0;
}
