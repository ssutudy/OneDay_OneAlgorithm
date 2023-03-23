#include <string>
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int N, map[102][102][2];
bool can_build(int y, int x, int type){
    if(type == 1){
        if(x == N) return false;
        if(y > 0 && (map[y - 1][x][0] || map[y - 1][x + 1][0])) return true;
        if(x > 0 && map[y][x - 1][1] && map[y][x + 1][1]) return true;
    }
    else{
        if(y == N) return false;
        if(y == 0 || map[y - 1][x][0]) return true;
        if(map[y][x][1]) return true;
        if(x > 0 && map[y][x - 1][1]) return true;
    }
    return false;
}
vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;
    
    // frame = [x, y, a(0=기둥, 1=보), b(0=삭제, 1=설치)]
    // 기둥 = 위쪽, 보 = 오른쪽
    // 리턴은 [x, y, a(0=기둥, 1=보)] (x, y) 오름차순
    N = n;
    memset(map, 0, sizeof(map));
    for(int i = 0; i < build_frame.size(); i++){
        vector<int> cur = build_frame[i];
        
        // 추가
        if(cur[3] == 1){
            if(can_build(cur[1], cur[0], cur[2])) map[cur[1]][cur[0]][cur[2]] = 1;
        }
        // 삭제
        else{
            bool can_erase = true;
            
            if(map[cur[1]][cur[0]][cur[2]] == 0) continue;
            map[cur[1]][cur[0]][cur[2]] = 0;
            // 보
            if(cur[2] == 1){
                if(cur[0] > 0 && map[cur[1]][cur[0] - 1][1] && !can_build(cur[1], cur[0] - 1, 1)) can_erase = false;
                if(can_erase && map[cur[1]][cur[0] + 1][1] && !can_build(cur[1], cur[0] + 1, 1)) can_erase = false;
                if(can_erase && map[cur[1]][cur[0]][0] && !can_build(cur[1], cur[0], 0)) can_erase = false;
                if(can_erase && map[cur[1]][cur[0] + 1][0] && !can_build(cur[1], cur[0] + 1, 0)) can_erase = false;
            }
            // 기둥
            else{
                if(map[cur[1] + 1][cur[0]][0] && !can_build(cur[1] + 1, cur[0], 0)) can_erase = false;
                if(can_erase && cur[0] > 0 && map[cur[1] + 1][cur[0] - 1][1] && !can_build(cur[1] + 1, cur[0] - 1, 1)) can_erase = false;
                if(can_erase && map[cur[1] + 1][cur[0]][1] && !can_build(cur[1] + 1, cur[0], 1)) can_erase = false;
            }
            if(!can_erase) map[cur[1]][cur[0]][cur[2]] = 1;
        }
    }
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= n; j++){
            // cout << map[i][j][0] << ',' << map[i][j][1] << ' ';
            if(map[j][i][0]) answer.push_back({i, j, 0});
            if(map[j][i][1]) answer.push_back({i, j, 1});
        }
        // cout << '\n';
    }
    return answer;
}
