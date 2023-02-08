#include<iostream>
#include<utility>
using namespace std;

bool map[2][10][10];
int ans, dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
void swap_arr(){
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            map[1][i][j] = map[0][i][j];
        }
    }
}
void flip(int y, int x){
    int dy, dx;
    
    map[1][y][x] = !map[1][y][x];
    for(int i = 0; i < 4; i++){
        dy = y + dir[i][0];
        dx = x + dir[i][1];
        if(dy < 0 || dy >= 10 || dx < 0 || dx >= 10) continue;
        map[1][dy][dx] = !map[1][dy][dx];
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    ans = -1;
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            char c;
            
            cin >> c;
            map[0][i][j] = ('#' != c);
        }
    }
    for(int i = 0; i < (1 << 10); i++){
        int press_cnt = 0;
        bool not_off = false;
      
        swap_arr();
        for(int j = 0; j < 10; j++){
            if(i & (1 << j)) flip(0, j), press_cnt++;
        }
        for(int j = 1; j < 10; j++){
            for(int k = 0; k < 10; k++){
                if(map[1][j - 1][k]) flip(j, k), press_cnt++;
            }
        }
        for(int j = 0; j < 10; j++){
            if(map[1][9][j]) not_off = true;
        }
        if(not_off) continue;
        ans = press_cnt;
        break;
    }
    cout << ans;
    return 0;
}
