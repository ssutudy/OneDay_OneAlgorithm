#include<iostream>
using namespace std;

int N, M, ans, before, DP[41];
int main(){
    cin >> N >> M;
    DP[0] = DP[1] = ans = 1;
    DP[2] = 2;
    for(int i = 3; i <= N; i++){
        DP[i] = DP[i-1] + DP[i-2];
    }
    while(M--){
        int val;
        
        cin >> val;
        ans *= DP[val - before - 1];
        before = val;
    }
    ans *= DP[N - before];
    cout << ans;
    return 0;
}
