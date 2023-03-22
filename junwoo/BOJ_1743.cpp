#include<iostream>
using namespace std;

int N, M, K, ans, map[100][100], dir[4][2] = {{0, 1}, {-1, 0}, {1, 0}, {0, -1}};
int dfs(int y, int x){
    int res, dy, dx;
    
    res = 1;
    map[y][x] = 0;
    for(int i = 0; i < 4; i++){
        dy = y + dir[i][0];
        dx = x + dir[i][1];
        if(dy < 0 || dy >= N || dx < 0 || dx >= M || map[dy][dx] == 0) continue;
        res += dfs(dy, dx);
    }
    return res;
}
int main(){
    cin >> N >> M >> K;
    while(K--){
        int r, c;
        
        cin >> r >> c;
        map[r - 1][c - 1] = 1;
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(map[i][j] == 0) continue;
            ans = max(ans, dfs(i, j));
        }
    }
    cout << ans;
    return 0;
}
