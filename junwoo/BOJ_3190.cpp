#include<iostream>
#include<deque>
#include<vector>
using namespace std;

struct cur_info{
    int dir, y, x, dur;
};

cur_info cur;
deque<pair<int, int> > snake, chg_dir;
int N, K, L, map[100][100], dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    cin >> N >> K;
    while(K--){
        int y, x;
        
        cin >> y >> x;
        map[y - 1][x - 1] = 1;
    }
    cin >> L;
    while(L--){
        int x;
        char c;
        
        cin >> x >> c;
        chg_dir.push_back({x, (c == 'L')? -1 : 1});
    }
    snake.push_back({0, 0});
    map[0][0] = 2;
    while(1){
        int dy, dx;
        
        cur.dur++;
        dy = cur.y + dir[cur.dir][0];
        dx = cur.x + dir[cur.dir][1];
        if(dy < 0 || dy >= N || dx < 0 || dx >= N || map[dy][dx] == 2) break;
        cur.y = dy;
        cur.x = dx;
        if(map[dy][dx] != 1){
            pair<int, int> tail = snake.front();
            
            snake.pop_front();
            map[tail.first][tail.second] = 0;
        }
        map[dy][dx] = 2;
        snake.push_back({dy, dx});
        if(!chg_dir.empty() && chg_dir.front().first == cur.dur){
            pair<int, int> dir_info = chg_dir.front();
            chg_dir.pop_front();
            cur.dir = (cur.dir + dir_info.second + 4) % 4;
        }
    }
    cout << cur.dur;
}
