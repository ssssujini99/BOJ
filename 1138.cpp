#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N; cin >> N; int rec[11] = {0, };

    for(int i=0; i<N; i++) cin >> rec[i+1];

    vector<int> order;
    for(int i=0; i<N; i++) order.push_back(i+1);

    do{
        // 줄을 선 게 rec의 정보와 맞는지 확인하기
        int res = 0;

        // cout << order[0] << " " << order[1] << " " << order[2] << " " << order[3] << "\n";

        for(int i=N-1; i>=0; i--){
            int cnt = 0;
            for(int j=i-1; j>=0; j--){
                if(order[j] > order[i]) cnt++;
            }
            if(cnt != rec[order[i]]) break;
            else res++;
        }

        if(res == N){
            for(int i=0; i<N; i++){
                cout << order[i] << " ";
            }
            exit(0);
        }
    }while(next_permutation(order.begin(), order.end()));


    return 0;
}
