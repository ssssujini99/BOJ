#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int k, tmp, res=0;
    stack<int> s;
    cin>>k;

    for(int i=0; i<k; i++){
      cin>>tmp;
      if(tmp!=0) s.push(tmp);
      else s.pop();
    }

    while(!s.empty()){
      res+=s.top();
      s.pop();
    }
    
    cout<<res<<endl;
    return 0;
}
