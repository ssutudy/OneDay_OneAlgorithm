#include<iostream>
using namespace std;

int N, K;
int solve(){
    int cur, bottle_cnt, ans = 0;
    
    if(N <= K) return 0;
    while(1){
        cur = N + ans;
        bottle_cnt = 0;
        while(cur > 0){
            bottle_cnt += (cur % 2);
            cur /= 2;
        }
        if(bottle_cnt <= K) break;
        ans++;
    }
    return ans;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    cin >> N >> K;
    cout << solve();
    return 0;
}
