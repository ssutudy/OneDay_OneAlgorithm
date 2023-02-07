#include<iostream>
using namespace std;

int N, c, COUNT[400], DP[300001];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N;
    COUNT[0] = 1;
    COUNT[1] = 4;
    for(c = 2; c < 400; c++){
        COUNT[c] = 2 * COUNT[c - 1] - COUNT[c - 2] + c + 1;
        if(COUNT[c] > N) break;
    }
    for(int i = 0; i < c; i++){
        for(int j = COUNT[i]; j <= N; j++){
            int val = DP[j - COUNT[i]] + 1;

            DP[j] = (DP[j] > 0)? min(val, DP[j]) : val;
        }
    }
    cout << DP[N];
    return 0;
}