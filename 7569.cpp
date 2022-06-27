#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

// 방향 좌표 : 동, 서, 남, 북, 위, 아래
int dx[6] = {0, 0, 1, -1, 0, 0};
int dy[6] = {1, -1, 0, 0, 0, 0};
int dh[6] = {0, 0, 0, 0, -1, 1};


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int m, n, h, tot=0; cin>>m>>n>>h;
    int a[100][100][100]={0, };
    int ch[100][100][100] = {0, };
    queue<pair<pair<int, int>, pair<int, int> > > q; // 순서대로 x, y, h, date 저장

    for(int i=0; i<h; i++){
        for(int x=0; x<n; x++){
            for(int y=0; y<m; y++){
                cin>>a[x][y][i];

                if(a[x][y][i]==1){
                    ch[x][y][i] = 1;
                    q.push(make_pair(make_pair(x, y), make_pair(i, 0))); // 현재 익은 토마토만 큐에 넣기
                }
                if(a[x][y][i]==1) tot++;
            }
        }
    }

    if(tot==m*n*h){ // 예외처리 : 저장될 때부터 모든 토마토가 익어있는 상태
        cout<<0<<endl;
        exit(0);
    }

    // bfs 수행 시작
    int xx, yy, hh, dd;
    while(!q.empty()){
        pair<pair<int, int>, pair<int, int> > p = q.front();
        xx = p.first.first; yy = p.first.second; hh = p.second.first; dd = p.second.second;
        q.pop();

        for(int i=0; i<6; i++){
            int xxx = xx + dx[i]; int yyy = yy + dy[i]; int hhh = hh + dh[i];
            if(xxx>=0 && xxx<n && yyy>=0 && yyy<m && hhh>=0 && hhh<h && 
            !ch[xxx][yyy][hhh] && a[xxx][yyy][hhh]==0){
                ch[xxx][yyy][hhh] = 1;
                q.push(make_pair(make_pair(xxx, yyy), make_pair(hhh, dd+1)));
            }
        }

    }

    for(int i=0; i<h; i++){
        for(int x=0; x<n; x++){
            for(int y=0; y<m; y++){

                if(a[x][y][i] == 0 && ch[x][y][i]==0){ // 익어야 하는데 익지 못한 토마토가 있는 경우
                    cout<<-1<<endl;
                    exit(0);
                }

            }
        }
    }

    cout<<dd<<endl;
    return 0;
}
