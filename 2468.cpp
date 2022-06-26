#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cstring>
using namespace std;

int a[101][101];
int ch[101][101]={0, };
int n;

// 동, 서, 남, 북 좌표
int dx[4] = {0, 0, 1, -1}; 
int dy[4] = {1, -1, 0, 0}; 

void DFS(int x, int y, int h){
    // 해당 (x, y)의 좌표에 대해서 동, 서, 남, 북 으로 dfs 수행
    for(int i=0; i<4; i++){
        int xx = x + dx[i];
        int yy = y + dy[i];

        if(xx>=1 && xx<=n && yy>=1 && yy<=n && a[xx][yy]>h && !ch[xx][yy]){
            ch[xx][yy]=1; // 방문처리
            DFS(xx, yy, h); // 해당 좌표에 대해서 dfs 수행
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin>>n;
    int max_rain=0;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin>>a[i][j];
            max_rain = max(max_rain, a[i][j]);
        }
    }

    int res = 0; // 최종 답 -> 안전 영역의 최대 개수

    for(int h=max_rain; h>=0; h--){
        int cnt = 0;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(!ch[i][j] && a[i][j]>h){
                    ch[i][j]=1;
                    DFS(i, j, h);
                    cnt++;
                }
            }
        } // 한 사이클 마무리
        res = max(res, cnt); // 결과 값 갱신
        memset(ch, 0, sizeof(ch)); // ch 배열 0으로 다시 세팅
    }

    cout<<res<<endl; // 결과 출력
    return 0;
}
