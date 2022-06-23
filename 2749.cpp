#include <iostream>
#include <algorithm>
using namespace std;

long long n, period = 1500000, mod=1000000;
long long dp[1500001]={0, };

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin>>n;
    
    dp[0]=0, dp[1]=1;
    for(int i=2; i<=n%period; i++){
        dp[i] = dp[i-1] + dp[i-2];
        dp[i] %= mod;
    }

    cout<<dp[n%period]<<endl;
    return 0;
}
