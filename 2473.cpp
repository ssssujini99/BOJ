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

    int n, tmp; vector<ll> v; cin >> n;
    for(int i=0; i<n; i++){
        cin >> tmp; v.push_back(tmp);
    }

    sort(v.begin(), v.end());

    int i, j, k; ll res = 3000000000;
    int res_i, res_j, res_k;


    for(i=0; i<n-2; i++){
        j = i + 1; k = n-1; // i, j, k 는 세 포인터 (인덱스값 나타냄)

        while(j < k){
            ll tmp = v[i] + v[j] + v[k];

            if(tmp == 0){
                cout << v[i] << " " << v[j] << " " << v[k] << endl;
                exit(0);
            }

            if(abs(tmp) < abs(res)){ // 갱신
                res = tmp;
                res_i = i, res_j = j, res_k = k;
            }

            if(tmp > 0) k--;
            else j++;
        }
    }

    cout << v[res_i] << " " << v[res_j] << " " << v[res_k] << endl;
    return 0;
}
