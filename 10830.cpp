#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

long long a[5][5]={0, }; long long tmp[5][5]={0,}; long long res[5][5]={0,};
long long n, b;

void matrixmul(long long res[5][5], long long a[5][5]){ // res: 결과벡터, a: 곱할벡터

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            tmp[i][j] = 0;

            for(int k=0; k<n; k++){
                tmp[i][j] += res[i][k]*a[k][j];
            }
            tmp[i][j] %= 1000;
        }
    }
    copy(&tmp[0][0], &tmp[0][0]+25, &res[0][0]);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin>>n>>b;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>a[i][j];
        }
        res[i][i]=1;
    }

    while(b>0){
        if(b%2 == 1){
            matrixmul(res, a);
        }
        matrixmul(a, a);
        b /= 2;
    }


    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<res[i][j]<<" ";
        }
        cout<<"\n";
    }

    return 0;
}
