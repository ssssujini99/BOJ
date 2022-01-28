#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> a;
    vector<int> inc; vector<int> dec; vector<int> res;

    int n, tmp, tmp_max, j;
    cin>>n;
    cin>>tmp; a.push_back(tmp); inc.push_back(1);

    // 증가수열 구하기
    for(int i=1; i<n; i++){
      cin>>tmp; a.push_back(tmp);

      j=i-1;
      tmp_max=0;
      while(j>=0){
        if(a[j]<tmp && inc[j]>tmp_max) tmp_max=inc[j];
        j--;
      }
      inc.push_back(tmp_max+1);
    }

    reverse(a.begin(), a.end());
    // 감소수열 구하기
    dec.push_back(1);
    for(int i=1; i<n; i++){
      j=i-1;
      tmp_max=0;
      while(j>=0){
        if(a[j]<a[i] && dec[j]>tmp_max) tmp_max=dec[j];
        j--;
      }
      dec.push_back(tmp_max+1);
    }
    reverse(dec.begin(), dec.end());

    for(int i=0; i<n; i++) res.push_back(inc[i]+dec[i]-1);
    cout<<*max_element(res.begin(), res.end())<<endl;
    return 0;
}
