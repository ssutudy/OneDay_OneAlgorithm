#include<iostream>
#include<cstring>
using namespace std;

struct shark{
    bool alive;
    int r, c, speed, direction, size;
};

shark info[10000];
int R, C, M, ans, map[2][100][100];
int dir[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
void calc_dir(int idx){
    int r, c;

    r = info[idx].r;
    c = info[idx].c;
    r += dir[info[idx].direction][0] * (info[idx].speed);
    c += dir[info[idx].direction][1] * (info[idx].speed);
    while(r < 0 || r >= R){
        r = (r < 0)? abs(r) : 2 * (R - 1) - r;
        // 0 <-> 1
        info[idx].direction = 1 - info[idx].direction;
    }
    while(c < 0 || c >= C){
        c = (c < 0)? abs(c) : 2 * (C - 1) - c;
        // 2 <-> 3
        info[idx].direction = 5 - info[idx].direction;
    }
    info[idx].r = r;
    info[idx].c = c;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> R >> C >> M;
    memset(map[0], -1, sizeof(map[0]));
    for(int i = 0; i < M; i++){
        int r, c, s, d, z;

        cin >> r >> c >> s >> d >> z;
        r--, c--, d--;
        map[0][r][c] = i;
        info[i] = {true, r, c, s, d, z};
    }
    for(int i = 0; i < C; i++){
        int j = 0;

        while(j < R && map[0][j][i] == -1) j++;
        if(j != R){
            info[map[0][j][i]].alive = false;
            ans += info[map[0][j][i]].size;
        }
        memset(map[1], -1, sizeof(map[1]));
        for(int k = 0; k < M; k++){
            if(!info[k].alive) continue;
            calc_dir(k);
            if(map[1][info[k].r][info[k].c] == -1) map[1][info[k].r][info[k].c] = k;            
            else{
                int idx;
                
                idx = map[1][info[k].r][info[k].c];
                if(info[k].size < info[idx].size){
                    info[k].alive = false;
                    map[1][info[idx].r][info[idx].c] = idx;
                }
                else{
                    info[idx].alive = false;
                    map[1][info[k].r][info[k].c] = k;
                }
                
            }
        }
        for(j = 0; j < R; j++){
            for(int k = 0; k < C; k++){
                swap(map[0][j][k], map[1][j][k]);
            }
        }
    }
    cout << ans;
    return 0;
}