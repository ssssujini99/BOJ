#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

int N, r, c;
int cnt = 0;

void findOrder(int size, int x, int y){
    if(size == 2){
        for(int i=x; i<x+2; i++){
            for(int j=y; j<y+2; j++){
                if(i == r && j == c){
                    cout << cnt << "\n";
                    exit(0);
                }
                else cnt++;
            }
        }
    }
    else{
        // 4개 사분면 중 조건을 걸어서 하나로만 탐색하도록 하기
        if(r < x + size/2 && c < y + size/2) findOrder(size/2, x, y); // 1사분면
        else if(r < x + size/2 && c >= y + size/2){
            cnt += (size/2)*(size/2);
            findOrder(size/2, x, y + size/2); // 2사분면
        }
        else if(r >= x + size/2 && c < y + size/2){
            cnt += 2*(size/2)*(size/2);
            findOrder(size/2, x + size/2 , y); // 3사분면
        }
        else{
            cnt += 3*(size/2)*(size/2);
            findOrder(size/2, x + size/2, y + size/2); // 4사분면
        }
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> r >> c;

    findOrder(pow(2, N), 0, 0);

    return 0;
}
