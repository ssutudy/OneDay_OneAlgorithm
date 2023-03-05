#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int N, M, K;
long long ans, DP[21][10000];
const long long MAX_DIST = 10000000001;
vector<pair<int, long long> > edge_list[10000];
priority_queue<pair<long long, pair<int, int> > > pq;
int main(){
    cin >> N >> M >> K;
    while(M--){
        int from, to; 
        long long t;
        
        cin >> from >> to >> t;
        from--, to--;
        edge_list[from].push_back({to, t});
        edge_list[to].push_back({from, t});
    }
    for(int i = 0; i <= K; i++){
        for(int j = 1; j < N; j++) DP[i][j] = MAX_DIST;
    }
    // dist, {k, idx}
    pq.push({0, {0, 0}});
    while(!pq.empty()){
        int next_idx;
        long long next_dist, cur_dist;
        pair<int, int> info;
        
        cur_dist = -pq.top().first;
        info = pq.top().second;
        pq.pop();
        if(DP[info.first][info.second] < cur_dist) continue;
        for(int i = 0; i < edge_list[info.second].size(); i++){
            next_idx = edge_list[info.second][i].first;
            next_dist = cur_dist;
            if(info.first < K && next_dist < DP[info.first + 1][next_idx]){
                DP[info.first + 1][next_idx] = next_dist;
                pq.push({-next_dist, {info.first + 1, next_idx}});
            }
            next_dist += edge_list[info.second][i].second;
            if(next_dist < DP[info.first][next_idx]){
                DP[info.first][next_idx] = next_dist;
                pq.push({-next_dist, {info.first, next_idx}});
            }
        }
    }
    ans = MAX_DIST;
    for(int i = 0; i <= K; i++){
        ans = min(ans, DP[i][N - 1]);
    }
    cout << ans;
    return 0;
}
