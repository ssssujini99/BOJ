#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int a[100001]={0, }; int ch[100001]={0, };
  int res[100001]={0, };
  int n, k, dis, w; queue<pair<int, int>> q;
  cin>>n>>k;
  ch[n]=1; res[n]=-1; q.push({n, 0});

  while(!q.empty()){
    pair<int, int> p = q.front(); q.pop();
    dis = p.second; w = p.first;
    if(p.first == k) break;

    if(2*w<=100000 && ch[2*w]==0){
      ch[2*w]=1; res[2*w]=w; q.push({2*w, dis+1});
    }
    if(w-1>=0 && ch[w-1]==0){
      ch[w-1]=1; res[w-1]=w; q.push({w-1, dis+1});
    }
    if(w+1<=100000 && ch[w+1]==0){
      ch[w+1]=1; res[w+1]=w; q.push({w+1, dis+1});
    }
  }

  cout<<dis<<endl;
  vector<int> v;
  while(1){
    v.emplace_back(w);
    w = res[w];
    if(w==-1) break;
  }
  for(int i=v.size()-1; i>=0; i--) cout<<v[i]<<" ";
  return 0;
}
