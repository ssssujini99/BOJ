#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int a[1000]={0, };
    vector<int> cnt;
    int n, tmp, j, cnt_max;
    cin>>n;
    cin>>tmp;
    a[0]=tmp; cnt.push_back(1);

    for(int i=1; i<n; i++){
      cin>>tmp; a[i]=tmp;

      j=i-1;
      cnt_max=0;
      while(j>=0){
        if(a[j]>tmp && cnt[j]>cnt_max) cnt_max=cnt[j];
        j--;
      }
      cnt.push_back(cnt_max + 1);
    }
    
    cout<<*max_element(cnt.begin(), cnt.end())<<endl;
    return 0;
}
