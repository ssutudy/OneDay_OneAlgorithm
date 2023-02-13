#include<iostream>
using namespace std;

int N, ans, power[2000], DP[2000];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N;
    for(int i = 0; i < N; i++) cin >> power[i];
    ans = DP[0] = 1;
    for(int i = 1; i < N; i++){
        DP[i] = 1;
        for(int j = i - 1; j > -1; j--){
            if(power[i] >= power[j]) continue;
            DP[i] = max(DP[i], DP[j] + 1);
        }
        ans = max(ans, DP[i]);
    }
    cout << N - ans;
    return 0;
}