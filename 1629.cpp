#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int k;

int fpow(int a, int b){
    if(b==0) return 1;

    long long x = fpow(a, b/2)%k;
    x = x*x%k;
    if(b%2==0) return x;
    else return x*a%k;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int i, j;
    cin>>i>>j>>k;
    long long res = fpow(i, j);
    cout<<res<<endl;

    return 0;
}
