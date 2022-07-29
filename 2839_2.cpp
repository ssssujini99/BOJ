#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
using namespace std;

vector<int> v;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N; cin >> N;

    if(N%5==0){
        cout << N/5 << endl;
        exit(0);
    }
    else{
        int f = 0, t = 0;
        while(N>0){
            N-=3; t++;
            if(N%5==0){
                f = N/5;
                break;
            }
        }

        if(f || N==0){
            cout << f+t << endl;
        }
        else{
            cout << -1 << endl;
        }
    }
    return 0;
}
