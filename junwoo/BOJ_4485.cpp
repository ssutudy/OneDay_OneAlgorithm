#include<iostream>
#include<cstring>
#include<queue>
using namespace std;

queue<pair<pair<int, int>, int> > que;
int N, map[125][125], dist[125][125], dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int solve(){
    int dy, dx;
    
    dist[0][0] = map[0][0];
    que.push({{0, 0}, dist[0][0]});
    while(!que.empty()){
        pair<int, int> cur_pos = que.front().first;
        int cur_dist = que.front().second;
        
        que.pop();
        for(int i = 0; i < 4; i++){
            dy = cur_pos.first + dir[i][0];
            dx = cur_pos.second + dir[i][1];
            if(dy < 0 || dy >= N || dx < 0 || dx >= N) continue;
            if(dist[dy][dx] != -1 && dist[dy][dx] <= (cur_dist + map[dy][dx])) continue;
            dist[dy][dx] = cur_dist + map[dy][dx];
            que.push({{dy, dx}, dist[dy][dx]});
        }
    }
    return dist[N - 1][N - 1];
}
int main(){
    for(int k = 1; ; k++){
        cin >> N;
        if(N == 0) break;
        memset(dist, -1, sizeof(dist));
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                cin >> map[i][j];
            }
        }
        cout << "Problem " << k << ": " << solve() << "\n";
    }
    return 0;
}
