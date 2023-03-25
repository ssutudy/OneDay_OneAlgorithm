#include<iostream>
#include<vector>
using namespace std;

vector<pair<int, int> > edge[40001];
int N, M, parent[40001][2], depth[40001];
void dfs(int cur, int d){
    depth[cur] = d;
    for(int i = 0; i < edge[cur].size(); i++){
        pair<int, int> n_info = edge[cur][i];

        if(parent[n_info.first][0] != 0) continue;
        parent[n_info.first][0] = cur;
        parent[n_info.first][1] = n_info.second;
        dfs(n_info.first, d + 1);
    }
}
int get_dist(int a, int b){
    int diff, ans = 0;

    if(depth[a] > depth[b]) swap(a, b);
    diff = depth[b] - depth[a];
    while(diff > 0){
        ans += parent[b][1];
        b = parent[b][0];
        diff--;
    }
    if(a != b){
        while(1){
            ans += parent[a][1] + parent[b][1];
            a = parent[a][0];
            b = parent[b][0];
            if(a == b) break;
        }
    }
    return ans;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    cin >> N;
    for(int i = 0; i < (N - 1); i++){
        int from, to, dist;

        cin >> from >> to >> dist;
        edge[from].push_back({to, dist});
        edge[to].push_back({from, dist});

    }
    dfs(1, 0);
    cin >> M;
    while(M--){
        int a, b;

        cin >> a >> b;
        cout << get_dist(a, b) << '\n';
    }
    return 0;
}
