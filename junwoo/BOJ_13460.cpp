#include<iostream>
#include<utility>
#include<queue>
using namespace std;

typedef struct{
    pair<int, int> r_pos, b_pos;
    int move_cnt;
} cur_info;

char map[10][10];
queue<cur_info> que;
pair<int, int> pos[2], goal;
int N, M, ans, dir[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> map[i][j];
            if(map[i][j] == 'R') pos[0] = {i, j}, map[i][j] = '.';
            if(map[i][j] == 'B') pos[1] = {i, j}, map[i][j] = '.';
            if(map[i][j] == 'O') goal = {i, j};
        }
    }
    ans = -1;
    que.push({pos[0], pos[1], 0});
    while(!que.empty() && ans == -1){
        cur_info cur = que.front();
        que.pop();

        for(int i = 0; i < 4; i++){
            int dy, dx;
            bool changed;
            pair<int, int> prev[2];

            prev[0] = cur.r_pos;
            prev[1] = cur.b_pos;
            map[prev[0].first][prev[0].second] = 'R';
            map[prev[1].first][prev[1].second] = 'B';
            while(1){
                changed = false;
                if(prev[0] != goal){
                    dy = prev[0].first + dir[i][0];
                    dx = prev[0].second + dir[i][1];
                    if(map[dy][dx] == 'O' || map[dy][dx] == '.'){
                        changed = true;
                        if(map[dy][dx] != 'O') swap(map[dy][dx], map[prev[0].first][prev[0].second]);
                        map[prev[0].first][prev[0].second] = '.';
                        prev[0].first = dy;
                        prev[0].second = dx;
                    }
                }
                dy = prev[1].first + dir[i][0];
                dx = prev[1].second + dir[i][1];
                if(map[dy][dx] == 'O' || map[dy][dx] == '.'){
                    changed = true;
                    if(map[dy][dx] != 'O') swap(map[dy][dx], map[prev[1].first][prev[1].second]);
                    map[prev[1].first][prev[1].second] = '.';
                    prev[1].first = dy;
                    prev[1].second = dx;
                }
                if(!changed || prev[1] == goal) break;
            }
            if(prev[0] != goal) map[prev[0].first][prev[0].second] = '.';
            if(prev[1] != goal){
                map[prev[1].first][prev[1].second] = '.';
                if(cur.move_cnt < 9) que.push({prev[0], prev[1], cur.move_cnt + 1});
                if(prev[0] == goal){
                    ans = cur.move_cnt + 1;
                    break;
                }
            }
        }
    }
    cout << ans;
    return 0;
}