#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <queue>
#include <unordered_map>
#include <cstring>
using namespace std;

struct s{
    int x;
    int y;
    int dis;
    int wall;
};

int a[1001][1001] = {0, };
bool ch[1001][1001][11];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M, K; cin >> N >> M >> K;
    int cnt_wall = 0;

    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    
    for(int i=0; i<N; i++){
        string s; cin >> s;
        for(int j=0; j<s.size(); j++){
            if(s[j]=='0') a[i][j] = 0;
            else a[i][j] = 1;
        }
    }

    for(int i=0; i<1001; i++){
        for(int j=0; j<1001; j++){
            for(int k=0; k<11; k++){
                ch[i][j][k] = 0;
            }
        }
    }
    
    queue<s> q;
    ch[0][0][0] = 1;
    q.push({0, 0, 1, 0});

    while(!q.empty()){
        int x = q.front().x, y = q.front().y, dis = q.front().dis, wall = q.front().wall;
        q.pop();

        if(x==N-1 && y==M-1){
            cout << dis << endl;
            exit(0);
        }

        for(int i=0; i<4; i++){
            int next_x = x + dx[i]; int next_y = y + dy[i];

            if(next_x >= 0 && next_x < N && next_y >= 0 && next_y < M && ch[next_x][next_y][wall]==0){
                if(wall + a[next_x][next_y] <= K){
                    ch[next_x][next_y][wall] = 1;
                    q.push({next_x, next_y, dis+1, wall + a[next_x][next_y]});
                }
            }
        }
    }

    cout << -1 << endl;
    return 0;
}
