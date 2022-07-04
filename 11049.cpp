#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int matrix[501][501], dp[501][501];

int main(){
    int n, t1, t2; cin>>n;
    for(int i=1; i<=n; i++){
        cin>>t1>>t2;

        matrix[i][0] = t1;
        matrix[i][1] = t2;
    }

    for(int i=1; i<n; i++){
        for(int j=1; j+i<=n; j++){
            dp[j][j+i] = 2147483647;

            for(int k=j; k<=j+i; k++){
                dp[j][j+i] = min(dp[j][j+i], dp[j][k]+dp[k+1][j+i] + matrix[j][0]*matrix[k][1]*matrix[j+i][1]);
            }
        }
    }

    cout << dp[1][n] << endl;
    return 0;
}
