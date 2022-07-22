#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

int a[2188][2188];
int n;
int res[3] = {0,};

void countFunc(int size, int x, int y){ // x, y : 시작 인덱스

    int start = a[x][y];
    int state = 0;

    if(size == 1){
        res[start+1]++;
        return;
    }

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
        for(int i=x; i<x+size; i += size/3){
            for(int j=y; j<y+size; j += size/3){
                countFunc(size/3, i, j);
            }
        }
    }
    else{
        res[start+1]++;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> a[i][j];
        }
    }

    countFunc(n, 0, 0);

    for(int i=0; i<3; i++) cout << res[i] << "\n";
    return 0;
}
