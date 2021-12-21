#include <iostream>
#include <stack>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int test_case;
    char arr[1001];
    stack<char> s;

    cin>>test_case;
    cin.ignore();

    for(int i=0; i<test_case; i++){
        cin.getline(arr, 1001, '\n');
        
        for(int j=0; j<1001; j++){
            while(arr[j]!=' ' && arr[j]!='\0'){
                s.push(arr[j++]);
            }
            while(!s.empty()){
                cout<<s.top();
                s.pop();
            }
            cout<<" ";
            if(arr[j]=='\0') break;
        }
        cout<<"\n";
    }
}