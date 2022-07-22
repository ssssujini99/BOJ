#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

int a[128][128] = {0, }; int N;
int res[2] = {0, };

void countFunc(int size, int x, int y){
    if(size == 1){ // 단위사이즈: 1
        res[a[x][y]]++; // 개수 추가
        return;
    }

    int start = a[x][y];
    int state = 0;
    for(int i=x; i<x+size; i++){
        for(int j=y; j<y+size; j++){
            if(start != a[i][j]){
                state = 1;
                break;
            }
        }
        if(state) break;
    }

    if(state){
        for(int i=x; i<x+size; i+=size/2){
            for(int j=y; j<y+size; j+=size/2){
                countFunc(size/2, i, j);
            }
        }
    }
    else{
        res[start]++; // 개수 추가
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> a[i][j];
        }
    }

    countFunc(N, 0, 0);
    cout << res[0] << "\n" << res[1];
    return 0;
}
