#include<iostream>
using namespace std;

bool DP[51][1001];
int N, S, M, ans, vol[50];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    cin >> N >> S >> M;
    for(int i = 0; i < N; i++) cin >> vol[i];
    DP[0][S] = true;
    for(int i = 0; i < N; i++){
        for(int j = 0; j <= M; j++){
            if(!DP[i][j]) continue;
            if(j + vol[i] <= M) DP[i + 1][j + vol[i]] = true;
            if(j - vol[i] > -1) DP[i + 1][j - vol[i]] = true;
        }
    }
    ans = -1;
    for(int i = M; i > -1; i--){
        if(!DP[N][i]) continue;
        ans = i;
        break;
    }
    cout << ans;
    return 0;
}
