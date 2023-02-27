#include<iostream>
#include<vector>
#include<queue>
using namespace std;

queue<int> que;
vector<pair<int, int> > edge[10001];
int N, D, s_point, e_point, dst, dist[10001];
int main(){
    cin >> N >> D;
    for(int i = 0; i < D; i++){
        dist[i] = 10001;
        edge[i].push_back({i + 1, 1});
    }
    for(int i = 0; i < N; i++){
        cin >> s_point >> e_point >> dst;
        edge[s_point].push_back({e_point, dst});
    }
    que.push(0);
    dist[0] = 0;
    dist[D] = D;
    while(!que.empty()){
        int cur = que.front();
        
        que.pop();
        for(int i = 0; i < edge[cur].size(); i++){
            e_point = edge[cur][i].first;
            dst = edge[cur][i].second;
            if(dist[e_point] > dist[cur] + dst){
                que.push(e_point);
                dist[e_point] = dist[cur] + dst;
            }
        }
    }
    cout << dist[D];
    return 0;
}
