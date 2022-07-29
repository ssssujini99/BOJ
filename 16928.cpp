#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <queue>
#include <unordered_map>
using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M, t1, t2; cin >> N >> M;
    unordered_map<int, int> um;
    for(int i=0; i<N+M; i++){
        cin >> t1 >> t2;
        um[t1] = t2;
    }
    // 입력 끝

    queue<pair<int, int> > q; int ch[101] = {0, };
    ch[1] = 1; q.push({1, 0});

    while(!q.empty()){
        int n = q.front().first; int d = q.front().second;
        q.pop();

        for(int i=1; i<=6; i++){
            int next_n = n + i;
            if(next_n == 100){
                cout << d + 1 << endl;
                exit(0);
            }

            if(um.find(next_n) != um.end()){
                next_n = um[next_n]; // 갱신
            }

            if(next_n >=1 && next_n <= 100 && ch[next_n]==0){
                ch[next_n] = 1;
                q.push(make_pair(next_n, d+1));
            }
        }
    }

    return 0;
}
