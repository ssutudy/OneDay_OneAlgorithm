#include <string>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

struct state{
    int y, x, dir, cnt;
};

int solution(vector<vector<int>> board) {
    int answer;
    queue<state> que;
    bool visited[2][101][101];
    
    memset(visited, 0, sizeof(visited));
    que.push({0, 1, 0, 0});
    visited[0][0][1] = true;
    while(!que.empty()){
        int y, x;
        state cur = que.front();
        
        que.pop();
        if(cur.y == (board.size() - 1) && cur.x == (board[0].size() - 1)){
            answer = cur.cnt;
            break;
        }
        if(cur.dir == 0){
            // 회전 상단
            y = cur.y;
            x = cur.x;
            if(y > 0 && board[y - 1][x - 1] != 1 && board[y - 1][x] != 1){
                if(!visited[1][y][x - 1]){
                    visited[1][y][x - 1]  = true;
                    que.push({y, x - 1, 1, cur.cnt + 1});
                }
                if(!visited[1][y][x]){
                    visited[1][y][x] = true;
                    que.push({y, x, 1, cur.cnt + 1});
                }
            }
            // 회전 하단
            y = cur.y + 1;
            x = cur.x;
            if(y < board.size() && board[y][x - 1] != 1 && board[y][x] != 1){
                if(!visited[1][y][x - 1]){
                    visited[1][y][x - 1] = true;
                    que.push({y, x - 1, 1, cur.cnt + 1});
                }
                if(!visited[1][y][x]){
                    visited[1][y][x] = true;
                    que.push({y, x, 1, cur.cnt + 1});
                }
            }
            // 이동 상
            y = cur.y - 1;
            x = cur.x;
            if(y > -1 && board[y][x - 1] != 1 && board[y][x] != 1 && !visited[0][y][x]){
                visited[0][y][x] = true;
                que.push({y, x, 0, cur.cnt + 1});
            }
            // 이동 하
            y = cur.y + 1;
            x = cur.x;
            if(y < board.size() && board[y][x - 1] != 1 && board[y][x] != 1 && !visited[0][y][x]){
                visited[0][y][x] = true;
                que.push({y, x, 0, cur.cnt + 1});
            }
            // 이동 좌
            y = cur.y;
            x = cur.x - 1;
            if(x > 0 && board[y][x - 1] != 1 && !visited[0][y][x]){
                visited[0][y][x] = true;
                que.push({y, x, 0, cur.cnt + 1});
            }
            // 이동 우
            y = cur.y;
            x = cur.x + 1;
            if(x < board[0].size() && board[y][x] != 1 && !visited[0][y][x]){
                visited[0][y][x] = true;
                que.push({y, x, 0, cur.cnt + 1});
            }
        }
        else{
            // 회전 좌측
            y = cur.y;
            x = cur.x;
            if(x > 0 && board[y - 1][x - 1] != 1 && board[y][x - 1] != 1){
                if(!visited[0][y - 1][x]){
                    visited[0][y - 1][x] = true;
                    que.push({y - 1, x, 0, cur.cnt + 1});
                }
                if(!visited[0][y][x]){
                    visited[0][y][x] = true;
                    que.push({y, x, 0, cur.cnt + 1});
                }
            }
            // 회전 우측
            y = cur.y;
            x = cur.x + 1;
            if(x < board[0].size() && board[y - 1][x] != 1 && board[y][x] != 1){
                if(!visited[0][y - 1][x]){
                    visited[0][y - 1][x] = true;
                    que.push({y - 1, x, 0, cur.cnt + 1});
                }
                if(!visited[0][y][x]){
                    visited[0][y][x] = true;
                    que.push({y, x, 0, cur.cnt + 1});
                }
            }
            // 이동 상측
            y = cur.y - 1;
            x = cur.x;
            if(y > 0 && board[y - 1][x] != 1 && !visited[1][y][x]){
                visited[1][y][x] = true;
                que.push({y, x, 1, cur.cnt + 1});
            }
            // 이동 하측
            y = cur.y + 1;
            x = cur.x;
            if(y < board.size() && board[y][x] != 1 && !visited[1][y][x]){
                visited[1][y][x] = true;
                que.push({y, x, 1, cur.cnt + 1});
            }
            // 이동 좌측
            y = cur.y;
            x = cur.x - 1;
            if(x > -1 && board[y - 1][x] != 1 && board[y][x] != 1 && !visited[1][y][x]){
                visited[1][y][x] = true;
                que.push({y, x, 1, cur.cnt + 1});
            }
            // 이동 우측
            y = cur.y;
            x = cur.x + 1;
            if(x < board[0].size() && board[y - 1][x] != 1 && board[y][x] != 1 && !visited[1][y][x]){
                visited[1][y][x] = true;
                que.push({y, x, 1, cur.cnt + 1});
            }
        }
    }
    return answer;
}
