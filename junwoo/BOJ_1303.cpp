#include<iostream>
using namespace std;

char map[100][100];
int N, M, power[2], dir[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
int dfs(int y, int x){
    char c;
    int area = 1, dy, dx;
    
    c = map[y][x];
    map[y][x] = 0;
    for(int i = 0; i < 4; i++){
        dy = y + dir[i][0];
        dx = x + dir[i][1];
        if(dy < 0 || dy >= M || dx < 0 || dx >= N || map[dy][dx] != c) continue;
        area += dfs(dy, dx);
    }
    return area;
}
int main(){
    cin >> N >> M;
    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++) cin >> map[i][j];
    }
    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            int area = 0, idx;
            
            if(map[i][j] == 0) continue;
            idx = (map[i][j] == 'W')? 0 : 1;
            area = dfs(i, j);
            area *= area;
            power[idx] += area;
        }
    }
    cout << power[0] << ' ' << power[1];
    return 0;
}
