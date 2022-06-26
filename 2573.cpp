#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cstring>
using namespace std;

int a[300][300] = {0, }; // 땅
int ch[300][300] = {0, };
int n, m;

// 동, 서, 남, 북 좌표
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void melting(){
    int tmp[300][300]={0, };

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            int cnt_zero = 0;
            if(a[i][j]){ // 빙하에 한해서만

                for(int k=0; k<4; k++){ // 주변 바다 개수 count 해주기
                    int xx = i + dx[k];
                    int yy = j + dy[k];
                    if(xx>=0 && xx<n && yy>=0 && yy<m && a[xx][yy]==0){ // 범위 만족 & 바다일 시에
                        cnt_zero++;
                    }
                }

                tmp[i][j] = a[i][j] - cnt_zero; // 빙하 갱신
                if(tmp[i][j]<0) tmp[i][j] = 0;
            }
        }
    }

    copy(&tmp[0][0], &tmp[0][0]+90000, &a[0][0]); // 배열 복사
}

void DFS(int x, int y){ // 빙하 덩어리 count 해주는 dfs
    for(int k=0; k<4; k++){
        int xx = x + dx[k];
        int yy = y + dy[k];

        if(xx>=0 && xx<n && yy>=0 && yy<m && !ch[xx][yy] && a[xx][yy]){
            ch[xx][yy] = 1;
            DFS(xx, yy);
        }
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin>>n>>m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>a[i][j];
        }
    }


    for(int year=1; ; year++){
        melting();
        int cnt_iceberg = 0;
        int cnt_sea = 0;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!ch[i][j] && a[i][j]){
                    ch[i][j]=1;
                    DFS(i, j);
                    cnt_iceberg++;

                    if(cnt_iceberg >= 2){
                        cout<<year<<endl;
                        exit(0);
                    }
                }
                else if(a[i][j]==0) cnt_sea++;

                if(cnt_sea == n*m){ // 두 덩어리로 분리되지 않은 채 모두 바다가 된 경우
                    cout<<0<<endl;
                    exit(0);
                }
            }
        }
        memset(ch, 0, sizeof(ch));
    }


    return 0;
}
