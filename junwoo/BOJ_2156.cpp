#include<iostream>
using namespace std;

int n, q[10000], DP[10000];
int main(){
    cin >> n;
    for(int i = 0; i < n; i++) cin >> q[i];
    DP[0] = q[0];
    DP[1] = q[0] + q[1];
    DP[2] = max(DP[1], max(q[0] + q[2], q[1] + q[2]));
    for(int i = 3; i < n; i++){
        DP[i] = max(DP[i - 1], max(DP[i - 2] + q[i], DP[i - 3] + q[i - 1] + q[i]));
    }
    cout << DP[n - 1];
    return 0;
}
