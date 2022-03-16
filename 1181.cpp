#include <bits/stdc++.h>
  using namespace std;

  bool compare(string a, string b){
    if(a.size()!=b.size()){ // 정렬조건1: 길이가 짧은 것 부터
      return a.size()<b.size();
    }
    else{ // 정렬조건2: 길이가 같으면 사전순으로
      return a<b;
    }
  };


  int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin>>n;
    vector<string> v;

    for(int i=0; i<n; i++){
      string str; cin>>str;
      v.push_back(str);
    }

    sort(v.begin(), v.end(), compare);
    v.erase(unique(v.begin(), v.end()), v.end()); // 벡터 중복원소 제거

    for(int i=0; i<v.size(); i++) cout<<v[i]<<"\n";

    return 0;
  }
