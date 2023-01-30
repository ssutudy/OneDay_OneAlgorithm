#include<iostream>
#include<string>
using namespace std;

const int MOD = 1000000000;
int N, ans, DP[10][101][1024];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N;
    for(int i = 0; i < 10; i++) DP[i][1][1 << i] = 1;
    for(int i = 2; i <= N; i++){
        for(int j = 0; j < 10; j++){
            for(int k = 1; k < 1024; k++){
                int bitfield = (k | (1 << j));
                if(j > 0) DP[j][i][bitfield] = (DP[j][i][bitfield] + DP[j - 1][i - 1][k]) % MOD;
                if(j < 9) DP[j][i][bitfield] = (DP[j][i][bitfield] + DP[j + 1][i - 1][k]) % MOD;
            }
        }
    }
    for(int i = 1; i < 10; i++) ans = (ans + DP[i][N][1023]) % MOD;
    cout << ans;
    return 0;
}