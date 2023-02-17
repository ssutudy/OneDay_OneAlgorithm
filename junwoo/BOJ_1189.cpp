#include<iostream>
using namespace std;

char map[5][5];
bool visited[5][5];
int R, C, K, ans, dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
void dfs(int y, int x, int remain){
    if(remain == 0){
        if(y == 0 && x == (C - 1)) ans++;
        return;
    }
    visited[y][x] = true;
    for(int i = 0; i < 4; i++){
        int dy, dx;

        dy = y + dir[i][0];
        dx = x + dir[i][1];
        if(dy < 0 || dy >= R || dx < 0 || dx >= C || 
           map[dy][dx] == 'T' || visited[dy][dx]) continue;
        dfs(dy, dx, remain - 1);
    }
    visited[y][x] = false;
}
int main(){
    cin >> R >> C >> K;
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            cin >> map[i][j];
        }
    }
    dfs(R - 1, 0, K - 1);
    cout << ans;
    return 0;
}
