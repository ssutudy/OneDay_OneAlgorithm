#include<iostream>
#include<queue>
using namespace std;

char map[1000][1000];
bool visited[11][1000][1000];
int N, M, K, ans, dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
queue<pair<pair<int, int>, pair<int, int> > > que;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M >> K;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++) cin >> map[i][j];
    }
    ans = -1;
    que.push({{0, 0}, {1, 0}});
    visited[0][0][0] = true;
    if(N == 1 && M == 1) ans = 1;
    while(!que.empty() && ans == -1){
        pair<int, int> pos = que.front().first;
        pair<int, int> etc = que.front().second;

        que.pop();
        for(int i = 0; i < 4; i++){
            int dy = pos.first + dir[i][0];
            int dx = pos.second + dir[i][1];

            if(dy < 0 || dy >= N || dx < 0 || dx >= M) continue;
            if((etc.second == K && map[dy][dx] == '1') || visited[etc.second + map[dy][dx] - '0'][dy][dx]) continue;
            if(dy == (N - 1) && dx == (M - 1)) ans = etc.first + 1;
            visited[etc.second + map[dy][dx] - '0'][dy][dx] = true;
            que.push({{dy, dx}, {etc.first + 1, map[dy][dx] - '0' + etc.second}});
        }
    }
    cout << ans;
    return 0;
}