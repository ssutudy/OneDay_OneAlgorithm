#include<iostream>
#include<cstring>
using namespace std;

pair<int, int> smell_map[20][20];
int shark_dir[401], shark_priority[401][4][4];
int N, M, K, map[20][20], dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int solve(){
    int remain_scnt, dy, dx, t = 0;
    int temp_map[20][20];
    
    remain_scnt = M;
    while(t < 1000){
        memset(temp_map, 0, sizeof(temp_map));
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                bool moved = false;
                int cur_dir = shark_dir[map[i][j]];
                
                if(map[i][j] == 0) continue;
                for(int k = 0; k < 4; k++){
                    int to_d = shark_priority[map[i][j]][cur_dir][k];
                    
                    dy = i + dir[to_d][0];
                    dx = j + dir[to_d][1];
                    if(dy < 0 || dy >= N || dx < 0 || dx >= N || smell_map[dy][dx].first != 0) continue;
                    if(temp_map[dy][dx] != 0 && temp_map[dy][dx] < map[i][j]){
                        remain_scnt--;
                    }
                    else{
                        if(temp_map[dy][dx] != 0) remain_scnt--;
                        temp_map[dy][dx] = map[i][j];
                        shark_dir[map[i][j]] = to_d;
                        
                    }
                    moved = true;
                    break;
                }
                for(int k = 0; k < 4 && !moved; k++){
                    int to_d = shark_priority[map[i][j]][cur_dir][k];
                    
                    dy = i + dir[to_d][0];
                    dx = j + dir[to_d][1];
                    if(dy < 0 || dy >= N || dx < 0 || dx >= N || smell_map[dy][dx].first != map[i][j]) continue;
                    temp_map[dy][dx] = map[i][j];
                    shark_dir[map[i][j]] = to_d;
                    moved = true;
                }
            }
        }
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                swap(map[i][j], temp_map[i][j]);
                if(map[i][j] != 0) smell_map[i][j] = {map[i][j], K};
                else if(smell_map[i][j].first != 0) smell_map[i][j].second--;
                if(smell_map[i][j].second == 0) smell_map[i][j].first = 0;
            }
        }
        t++;
        if(remain_scnt == 1) return t;
    }
    return -1;
}
int main(){
    cin >> N >> M >> K;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> map[i][j];
            if(map[i][j] != 0) smell_map[i][j] = {map[i][j], K};
        }
    }
    for(int i = 0; i < M; i++){
        cin >> shark_dir[i + 1];
        shark_dir[i + 1]--;
    }
    for(int i = 0; i < M; i++){
        for(int j = 0; j < 4; j++){
            for(int k = 0; k < 4; k++){
                cin >> shark_priority[i + 1][j][k];
                shark_priority[i + 1][j][k]--;
            }
        }
    }
    cout << solve();
    return 0;
}
