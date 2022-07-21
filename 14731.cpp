#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

typedef long long ll;
#define MOD 1000000007

ll squareFunc(ll x, ll n){
    if(n == 0) return 1;
    // x의 n승을 구하는 함수
    ll half = squareFunc(x, n/2) % MOD;
    half = (half % MOD) * (half % MOD);

    if(n%2) half = (half * x) % MOD;

    return half % MOD;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N; ll c, k, sum = 0;
    cin >> N;

    for(int i=0; i<N; i++){
        cin >> c >> k;
        c = (c*k)%MOD; k -= 1;
        sum += (c * squareFunc(2, k)) % MOD;
        sum %= MOD;
    }

    cout << sum << endl;
    return 0;
}
