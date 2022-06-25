#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int a[9][9]={0, };
vector<pair<int, int> > v;

bool check(int num, int x, int y){
    // 가로 줄 확인
    for(int i=0; i<9; i++){
        if(a[x][i]==num) return false;
    }

    // 세로 줄 확인
    for(int i=0; i<9; i++){
        if(a[i][y]==num) return false;
    }

    // 3*3 정사각형 확인
    int xx, yy;
    if(x%3==0) xx = x;
    else if(x%3==1) xx = x-1;
    else xx = x-2;

    if(y%3==0) yy = y;
    else if(y%3==1) yy = y-1;
    else yy = y-2;

    for(int i=xx; i<xx+3; i++){
        for(int j=yy; j<yy+3; j++){
            if(a[i][j]==num) return false;
        }
    }

    // 다 통과한 경우
    return true;
}

void DFS(int idx){
    if(idx==v.size()){
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                cout<<a[i][j]<<" ";
            }
            cout<<"\n";
        }
        exit(0);
    }
    else{
        for(int i=1; i<=9; i++){
            if(check(i, v[idx].first, v[idx].second)){
                a[v[idx].first][v[idx].second] = i;
                DFS(idx+1);
                a[v[idx].first][v[idx].second] = 0;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            cin>>a[i][j];
            if(a[i][j]==0) v.push_back(make_pair(i, j));
        }
    }

    DFS(0);

    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            cout<<a[i][j]<<" ";
        }
        cout<<"\n";
    }

    return 0;
}
