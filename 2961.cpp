#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

typedef long long ll;

struct Ingredient {
    ll s;
    ll b;

    Ingredient(){ // 생성자
        s = 0;
        b = 0;
    }
};


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, i; Ingredient ing[10]; ll t1, t2, res = 987654321;
    cin >> N;
    for(i=0; i<N; i++){
        cin >> ing[i].s >> ing[i].b; // 차례로 신맛, 쓴맛 입력받기
    }
    for(; i<N; i++){
        ing[i].s = 0; ing[i].b = 0;
    }

    for(i=1; i<=pow(2, N)-1; i++){ // 가능한 모든 조합에 대해서
        ll prod = 1; ll sum = 0;
        
        for(int j=0; j<N; j++){ // 위치에 대해서
            if(i & (1 << j)){
                prod *= ing[j].s;
                sum += ing[j].b;
            }
        }
        res = min(abs(res), abs(prod-sum));
    }

    cout << res << endl;
    return 0;
}
