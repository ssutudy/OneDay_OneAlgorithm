#include<iostream>
#include<queue>
#include<vector>
using namespace std;

char map[1000][1000];
queue<pair<int, int> > fire_que, temp_que;
queue<pair<int, pair<int, int> > > que;
int R, C, cur, ans, dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int main(){
    cin >> R >> C;
    ans = cur = 0;
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            cin >> map[i][j];
            if(map[i][j] == 'J'){
                que.push({0, {i, j}});
                map[i][j] == 'c';
                if(i == 0 || i == (R - 1) || j == 0 || j == (C - 1)) ans = 1;
            }
            if(map[i][j] == 'F') fire_que.push({i, j});
        }
    }
    while(ans == 0 && !que.empty()){
        int dy, dx, t = que.front().first;
        pair<int, int> pos = que.front().second;
        
        que.pop();
        if(cur == t){
            while(!fire_que.empty()){
                pair<int, int> f_pos = fire_que.front();
                
                fire_que.pop();
                for(int i = 0; i < 4; i++){
                    dy = f_pos.first + dir[i][0];
                    dx = f_pos.second + dir[i][1];
                    if(dy < 0 || dy >= R || dx < 0 || dx >= C || map[dy][dx] == '#' || map[dy][dx] == 'F') continue;
                    map[dy][dx] = 'F';
                    temp_que.push({dy, dx});
                }
            }
            cur++;
        }
        while(!temp_que.empty()){
            fire_que.push(temp_que.front());
            temp_que.pop();
        }
        for(int i = 0 ; i < 4; i++){
            dy = pos.first + dir[i][0];
            dx = pos.second + dir[i][1];
            if(map[dy][dx] != '.') continue;
            if(dy == 0 || dy == (R - 1) || dx == 0 || dx == (C - 1)) ans = cur + 1; 
            que.push({t + 1, {dy, dx}});
            map[dy][dx] = 'c';
        }
    }
    if(ans == 0) cout << "IMPOSSIBLE";
    else cout << ans;
    return 0;
}
