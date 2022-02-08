#include <bits/stdc++.h>
using namespace std;

int n, m;
int ch[10001]={0, }; // 중복 여부 확인 배열
int res[9]={0, }; // 결과 배열
vector<int> v;

void DFS(int idx, int cnt){
  if(cnt==m){
    for(int i=0; i<n; i++){
      if(ch[i]) cout<<v[i]<<" ";
    }
    cout<<"\n";
  }
  else if(idx>=n) return;
  else{
    ch[idx]=1;
    DFS(idx+1, cnt+1);
    ch[idx]=0;
    DFS(idx+1, cnt);
  }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>n>>m;
    for(int i=0; i<n; i++){
      int tmp; cin>>tmp;
      v.push_back(tmp);
    }
    sort(v.begin(), v.end());
    DFS(0, 0);

    return 0;
}
