#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string a, b, c, d;
    cin>>a>>b>>c>>d;

    a += b; c += d;

    long long res = stoll(a)+stoll(c);
    cout<<res<<endl;
    return 0;
}