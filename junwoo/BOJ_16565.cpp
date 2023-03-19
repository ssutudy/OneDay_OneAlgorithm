#include<iostream>
using namespace std;

const int MOD = 10007;
int N, c, ans, DP[53][53];
int main(){
    cin >> N;
    DP[0][0] = 1;
    for(int i = 1; i < 53; i++){
        DP[i][0] = 1;
        for(int j = 1; j < 53; j++){
            DP[i][j] = (DP[i - 1][j] + DP[i - 1][j - 1]) % MOD;
        }
    }
    c = 1;
    while(c * 4 <= N){
        int val = (DP[52 - 4 * c][N - 4 * c] * DP[13][c]) % MOD;
        
        if(c % 2 == 1) ans = (ans + val) % MOD;
        else ans = (ans - val + MOD) % MOD;
        c++;
    }
    cout << ans;
    return 0;
}
