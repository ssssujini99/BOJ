#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;

int m, n;
char a[100][100]; // 입력받는 배열
int ch[100][100]; // 거울의 최소 개수
vector <pair<int, int> > v; // C 좌표값을 저장하는 벡터
queue <pair<pair<int, int>, pair<int, int> > > q; // x, y, dir, n_mirror

// 방향 좌표 : 동, 남, 서, 북 순으로
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin>>m>>n;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>a[i][j];

            if(a[i][j] == 'C'){
                a[i][j] = '.';
                v.push_back(make_pair(i, j));
            }
            ch[i][j] = 1000000000;
        }
    }


    int s_x = v[0].first; int s_y = v[0].second, s_d, s_m; // 레이저 출발 지점
    int xx, yy;

    q.push(make_pair(make_pair(s_x, s_y), make_pair(-1, 0))); // (x좌표, y좌표), (방향, 거울 개수)

    while(!q.empty()){
        pair <pair<int, int>, pair<int, int> > p = q.front(); q.pop();
        s_x = p.first.first; s_y = p.first.second; s_d = p.second.first; s_m = p.second.second;
        int tmp_mirror;

        // cout << s_x << " " << s_y << " " << s_m << "\n";
        
        for(int i=0; i<4; i++){
            xx = s_x + dx[i]; // 이동 할 좌표들
            yy = s_y + dy[i]; // 이동 할 좌표들
            
            if(!(xx>=0 && xx<n && yy>=0 && yy<m && a[xx][yy]=='.')) continue;
            
            tmp_mirror = s_m;
            if(i != s_d) tmp_mirror++; // 방향이 다르면 -> 거울 개수 + 1 해주기
            if(ch[xx][yy] >= tmp_mirror){ // 거울 개수 갱신할 경우
                ch[xx][yy] = tmp_mirror; // 거울 개수 갱신
                q.push(make_pair(make_pair(xx, yy), make_pair(i, tmp_mirror))); // 큐에 넣기
            }

        }
    }
    
    cout << ch[v[1].first][v[1].second] - 1 << endl;

    return 0;
}
