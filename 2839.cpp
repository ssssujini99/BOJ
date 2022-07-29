#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
using namespace std;

vector<int> v;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N; cin >> N;
    int res = 0;
    int a[5001] = {0, };
    for(int i=1; i<=5; i++) a[i] = 987654321;
    a[3] = 1; a[5] = 1;

    for(int i=6; i<=N; i++){
        a[i] = min(a[i-3]+1, a[i-5]+1);
    }

    if(a[N] >= 987654321) cout << -1 << endl;
    else cout << a[N] << endl;
    return 0;
}
