#include <bits/stdc++.h>
  using namespace std;

  bool compare(pair<pair<int, string>, int> a, pair<pair<int, string>, int> b){
    if(a.first.first!=b.first.first){
      return a.first.first < b.first.first; // 나이가 다르면 나이가 증가하는 순으로
    }
    else{
      return a.second < b.second; // 나이가 같으면 가입 순으로
    }
  };


  int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin>>n;
    vector<pair<pair<int, string>, int>> v;

    for(int i=0; i<n; i++){
      int age; string str; cin>>age>>str;
      v.push_back({{age, str}, i});
    }

    sort(v.begin(), v.end(), compare);

    for(int i=0; i<v.size(); i++){
      cout<<v[i].first.first<<" "<<v[i].first.second<<"\n";
    }

    return 0;
  }
