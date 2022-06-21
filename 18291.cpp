#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

long long mod = 1000000000+7;

long long func(int k){
    if(k<=0) return 1;

    long long x = func(k/2)%mod;
    x = x*x%mod;
    if(k%2==0) return x;
    else return x*2%mod;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, tmp; cin>>n;
    for(int i=0; i<n; i++){
        cin>>tmp;
        cout<<func(tmp-2)<<"\n";
    }

    return 0;
}
