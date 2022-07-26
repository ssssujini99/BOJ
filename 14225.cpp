#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
using namespace std;

typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int a[21] = {0, };
    vector<int> v;
    int N; cin >> N;
    for(int i=0; i<N; i++) cin >> a[i];

    for(int i=1; i<(1<<N); i++){
        // 한 조합에 대해서

        int tmp_sum = 0;
        for(int j=0; j<N; j++){
            if(i & (1<<j)){
                tmp_sum += a[j];
            }
        }
        v.push_back(tmp_sum);

    }
    
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(),v.end()), v.end()); // 중복 제거

    int i = 1, j = 0;
    while(1){
        if(i == v[j]){
            i++; j++;
        }
        else{
            cout << i << endl;
            exit(0);
        }
    }
    return 0;
}
