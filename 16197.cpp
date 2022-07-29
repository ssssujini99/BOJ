#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <queue>
using namespace std;

typedef long long ll;
char c[21][21]; int N, M; 

struct s{
    int x1;
    int y1;
    int x2;
    int y2;
    int d;
};

int caseFunc(int x, int y){
    if(x<0 || x>=N || y<0 || y>=M) return 3; // 범위 밖
    else if(c[x][y]=='.' || c[x][y]=='o') return 1; // 빈칸 or 동전
    else return 2; // 벽
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};

    cin >> N >> M;
    vector<pair<int, int> > coin; // 두 개 동전 좌표들
    
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> c[i][j];

            if(c[i][j] == 'o'){
                coin.push_back(make_pair(i, j));
            }
        }
    }
    // 입력 끝

    queue<s> q;
    q.push({coin[0].first, coin[0].second, coin[1].first, coin[1].second, 0});

    while(!q.empty()){
        int x1 = q.front().x1;
        int y1 = q.front().y1;
        int x2 = q.front().x2;
        int y2 = q.front().y2;
        int d = q.front().d;

        q.pop();
        
        if(d>=10){
            cout << -1 << endl;
            exit(0);
        }

        int new_x1, new_y1, new_x2, new_y2;
        int r1, r2;

        for(int i=0; i<4; i++){
            new_x1 = x1 + dx[i];
            new_y1 = y1 + dy[i];
            new_x2 = x2 + dx[i];
            new_y2 = y2 + dy[i];

            r1 = caseFunc(new_x1, new_y1);
            r2 = caseFunc(new_x2, new_y2);

            if(r1 == 3 && r2 == 3) continue; // 모두 범위 밖인 경우
            else if(r1 == 3 || r2 == 3){ // 하나만 범위 밖인 경우 -> 정답
                cout << d+1 << endl;
                exit(0);
            }
            else if(r1 == 2 && r2 == 2) continue; // 모두 벽인 경우 -> 다시 넣을 필요 x
            else if(r1 == 1 && r2 == 1){
                q.push({new_x1, new_y1, new_x2, new_y2, d+1});
            }
            else if(r1 == 1 && r2 == 2){
                q.push({new_x1, new_y1, x2, y2, d+1});
            }
            else if(r1 == 2 && r2 == 1){
                q.push({x1, y1, new_x2, new_y2, d+1});
            }
            else{};
        }
    }
    
    cout << -1 << endl; // 두 동전을 떨어뜨릴 수 없는 상황
    return 0;
}
