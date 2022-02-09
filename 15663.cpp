#include <bits/stdc++.h>
using namespace std;

int n, m;
string str="";
int ch[9]={0, }; // 중복 여부 확인 배열
int res[9]={0, }; // 결과 배열
unordered_map<string, int> um;
vector<int> v;

void DFS(int idx){
  if(idx==m){
    if(um[str]==0){
      um[str]=1;
      for(int i=0; i<m; i++) cout<<res[i]<<" ";
      cout<<"\n";
    }
  }
  else{
    for(int i=0; i<n; i++){
      if(!ch[i]){
        ch[i]=1;
        res[idx]=v[i];
        string tmp_str = str;
        str += to_string(v[i]);
        DFS(idx+1);
        ch[i]=0;
        str = tmp_str;
      }
    }
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
    DFS(0);

    return 0;
}
