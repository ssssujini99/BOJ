#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

bool Check(int num){
    if(num<=99) return true;
    else if(100<=num && num<=999){
        int n1 = num%10; num/=10;
        int n2 = num%10; num/=10;
        int n3 = num%10;

        if(n1-n2 == n2-n3) return true;
        else return false;
    }
    else return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, res = 0;
    cin >> N;

    for(int i=1; i<=N; i++){
        if(Check(i)) res++;
    }

    cout << res << endl;
    return 0;
}
