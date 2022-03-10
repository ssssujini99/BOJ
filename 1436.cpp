#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int i, n; cin>>n;
  int num=0;
  
  for(i=1; ; i++){
    string str = to_string(i);
    int cnt=0;
    int m=0;
    for(int j=0; j<str.size(); j++){
      if(str[j]=='6') cnt++;
      else cnt=0;

      if(m<cnt) m=cnt;
    }
    if(m>=3) num++;

    if(num==n) break;
  }

  cout<<i<<endl;
  return 0;
}
