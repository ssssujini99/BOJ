#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long n, k;
long long mod = 1000000007;

long long dmul(long long i, long long j){
    if(j==0) return 1;

    long long k = dmul(i, j/2)%mod;
    k = k*k%mod;
    if(j%2==0) return k;
    else return k*i%mod;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin>>n>>k;
    
    long long a=1, b=1;
    for(int i=n; i>=n-k+1; i--){
        a = (a*i)%mod;
    }
    for(int i=k; i>=1; i--){
        b = (b*i)%mod;
    }
    b = dmul(b, mod-2)%mod;

    cout<<a * b % mod<<endl;
    return 0;
}
