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
    for(int i=idx; i<=n; i++){
      if(!ch[i] && res[idx-1]<i){ // 같은 수 중복 제거 + 마지막 원소시작 제거
        ch[i]=1;
        res[idx]=i;
        DFS(idx+1);
        ch[i]=0;
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
