#include<iostream>
#include<vector>
using namespace std;

vector<int> edge[1000001];
int N, a, b, DP[1000001][2];
void solve(int cur){
    DP[cur][0] = 1;
    for(int i = 0; i < edge[cur].size(); i++){
        int nxt = edge[cur][i];
        
        if(DP[nxt][0] > 0) continue;
        solve(nxt);
        DP[cur][0] += min(DP[nxt][0], DP[nxt][1]);
        DP[cur][1] += DP[nxt][0];
    }
}
int main(){
    cin >> N;
    for(int i = 0; i < (N - 1); i++){
        cin >> a >> b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    solve(1);
    cout << min(DP[1][0], DP[1][1]);
    return 0;
}
