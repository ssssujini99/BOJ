#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int a[1000]={0, };
    vector<int> s;
    int n, tmp, j, t_max;
    cin>>n;
    cin>>tmp;
    a[0]=tmp; s.push_back(tmp);

    for(int i=1; i<n; i++){
      cin>>tmp; a[i]=tmp;

      j=i-1;
      t_max=0;
      while(j>=0){
        if(a[j]<tmp && s[j]>t_max) t_max=s[j];
        j--;
      }
      s.push_back(t_max + tmp);
    }
    
    cout<<*max_element(s.begin(), s.end())<<endl;
    return 0;
}
