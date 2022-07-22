#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll T, cnt = 0; cin >> T; int n, m, tmp;
    int a[1001]={0, }; int b[1001]={0, };
    vector<ll> sum_a; vector<ll> sum_b; // 각각의 부분합 저장

    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> a[i];
        a[i] += a[i-1]; // 누적합에 대해서 저장
        for(int j=0; j<i; j++){
            sum_a.push_back(a[i]-a[j]); // 가능한 모든 누적합에 대해서 저장
        }
    }

    cin >> m;
    for(int i=1; i<=m; i++){
        cin >> b[i];
        b[i] += b[i-1]; // 누적합에 대해서 저장

        for(int j=0; j<i; j++){
            sum_b.push_back(b[i]-b[j]); // 가능한 모든 누적합에 대해서 저장
        }
    }

    sort(sum_b.begin(), sum_b.end());

    for(int i=0; i<sum_a.size(); i++){
        ll res = sum_a[i];
        cnt += upper_bound(sum_b.begin(), sum_b.end(), T-res) - lower_bound(sum_b.begin(), sum_b.end(), T-res);
    }

    cout << cnt << endl;
    return 0;
}
