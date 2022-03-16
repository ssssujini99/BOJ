#include <bits/stdc++.h>
using namespace std;


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  vector<int> v; string str;
  cin>>str;

  for(int i=0; i<str.size(); i++){
    v.push_back(int(str[i]-'0'));
  }

  sort(v.begin(), v.end(), greater<>());

  for(int i=0; i<v.size(); i++) cout<<v[i];

  return 0;
}
