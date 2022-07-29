#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <queue>
using namespace std;

struct s{
    int x, y, d;
};


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int dx[6] = {-2, -2, 0, 0, 2, 2};
    int dy[6] = {-1, 1, -2, 2, -1, 1};
    int ch[201][201] = {0, };

    int N, s_x, s_y, f_x, f_y;
    cin >> N;
    cin >> s_x >> s_y >> f_x >> f_y;

    ch[s_x][s_y] = 1;
    queue<s> q;
    q.push({s_x, s_y, 0});

    while(!q.empty()){
        int x = q.front().x, y = q.front().y, d = q.front().d;
        q.pop();

        for(int i=0; i<6; i++){
            int n_x = x + dx[i]; int n_y = y + dy[i];
            if(n_x == f_x && n_y == f_y){
                cout << d+1 << endl;
                exit(0);
            }

            if(n_x >=0 && n_x < N && n_y >=0 && n_y < N && ch[n_x][n_y]==0){
                // 범위를 만족하고 && 방문하지 않았더라면
                ch[n_x][n_y] = 1;
                q.push({n_x, n_y, d+1});
            }
        }
    }

    cout << -1 << endl;
    return 0;
}
