#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <queue>
#include <unordered_map>
#include <cstring>
#include <sstream>
using namespace std;

typedef long long ll;

int tree[10001];

void postOrder(int start, int end){
    if(start > end) return;
    if(start == end){
        cout << tree[start] << "\n";
        return;
    }

    int p = start + 1;
    while(p <= end){
        if(tree[p] > tree[start]) break;
        p++;
    }

    postOrder(start+1, p-1);
    postOrder(p, end);
    cout << tree[start] << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int num;
    int inputIdx = 0;
    while(cin >> num){
        tree[inputIdx++] = num;
    }

    postOrder(0, inputIdx-1);
    
    return 0;
}
