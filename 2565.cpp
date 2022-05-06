#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vector<pair<int, int> > v; int N, p1, p2; int dp[100];
    cin>>N;
    for(int i=0; i<N; i++){
        cin>>p1>>p2;
        v.push_back(make_pair(p1, p2));
    }
    sort(v.begin(), v.end());

    dp[0]=1; int res = INT_MIN;
    for(int i=1; i<v.size(); i++){
        dp[i]=1;
        for(int j=i-1; j>=0; j--){
            if(v[j].second < v[i].second && dp[j]>=dp[i]) dp[i]=dp[j]+1;
        }
        res = max(res, dp[i]);
    }
    
    cout<<v.size()-res<<endl;
    return 0;
}
