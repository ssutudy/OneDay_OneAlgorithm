#include<iostream>
using namespace std;

int N, DP[100000][2];
const int MOD = 9901;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    cin >> N;
    DP[0][0] = DP[0][1] = 1;
    for(int i = 1; i < N; i++){
        DP[i][1] = (DP[i - 1][0] + DP[i - 1][1]) % MOD;
        DP[i][0] = (DP[i][1] + DP[i - 1][1]) % MOD;
    }
    cout << (DP[N - 1][0] + 2 * DP[N - 1][1]) % MOD;
    return 0;
}