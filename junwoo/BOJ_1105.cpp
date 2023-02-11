#include<iostream>
#include<string>
using namespace std;

int ans;
string L, R;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    cin >> L >> R;
    if(L.size() == R.size()){
        for(int i = 0; i < L.size(); i++){
            if(L[i] != R[i]) break;
            if(L[i] == '8') ans++;
        }
    }
    cout << ans;
    return 0;
}
