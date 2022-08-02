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
    int time; // 낮(1)/밤(0)
};

int a[1001][1001] = {0, };
bool ch[1001][1001][11][2]; // x, y, 해당 좌표에 오기 전까지(과거) 부신 벽의 수-과거, (현재좌표에 도달했을 때 시간) 낮(1)/밤(0)-현재

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
                for(int l=0; l<2; l++){
                    ch[i][j][k][l] = 0;
                }
            }
        }
    }
    
    queue<s> q;
    ch[0][0][0][1] = 1; // 가장 처음 이동할때 = 낮
    q.push({0, 0, 1, 0, 1});

    while(!q.empty()){
        int x = q.front().x, y = q.front().y, dis = q.front().dis, wall = q.front().wall, time = q.front().time;
        q.pop();

        if(x==N-1 && y==M-1){
            cout << dis << endl;
            exit(0);
        }

        for(int i=0; i<4; i++){
            int next_x = x + dx[i]; int next_y = y + dy[i]; int next_t = (!time);

            if(next_x >= 0 && next_x < N && next_y >= 0 && next_y < M && ch[next_x][next_y][wall][next_t]==0){
                if(time == 1){
                    // 바로 이전이 낮인 경우 -> next 좌표가 "빈 칸" 이든 "벽"이든 상관 없음 (빈칸 - O, 벽 - O)
                    if(wall + a[next_x][next_y] <= K){
                        ch[next_x][next_y][wall][0] = 1; // (next -> 밤)
                        q.push({next_x, next_y, dis+1, wall + a[next_x][next_y], 0});
                    }
                }
                else{
                    // 바로 이전이 밤인 경우 -> (벽 못 부심) "빈 칸"만 이동가능! (빈칸 - O, 벽 - X)
                    if(a[next_x][next_y]==0){ // 빈 칸인 경우에만 이동 가능
                        ch[next_x][next_y][wall][1] = 1; // (next -> 낮)
                        q.push({next_x, next_y, dis+1, wall, 1});
                    }
                }
            }

        }

        // 이동하지 않고 같은 칸에 머무르는 경우 ("밤"인 경우에만 처리해 주면 됨 -> 따로 처리 해줘야함)
        if(time == 0){ // 밤 일때에만
            // 바로 이전이 밤인 경우 -> 동일 자리에서 기다릴 수 있음
            ch[x][y][wall][1] = 1; // 현재 시간대는 낮이므로 -> 1
            q.push({x, y, dis+1, wall, 1});
        }
    }
    // bfs 종료

    cout << -1 << endl;
    return 0;
}
