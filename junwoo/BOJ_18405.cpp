#include<iostream>
#include<queue>
using namespace std;

typedef pair<pair<int, int>, pair<int, int> > node;

int N, K, S, X, Y, map[200][200], dir[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
priority_queue<node> que;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    cin >> N >> K;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> map[i][j];
            if(map[i][j] != 0) que.push({{-0, -map[i][j]}, {i, j}});
        }
    }
    cin >> S >> X >> Y;
    X--, Y--;
    while(map[X][Y] == 0 && !que.empty()){
        node cur = que.top();
        int dy, dx;
        
        que.pop();
        if(-cur.first.first >= S) continue;
        for(int i = 0; i < 4; i++){
            dy = cur.second.first + dir[i][0];
            dx = cur.second.second + dir[i][1];
            if(dx < 0 || dx >= N || dy < 0 || dy >= N || map[dy][dx] != 0) continue;
            map[dy][dx] = -cur.first.second;
            que.push({{cur.first.first - 1, -map[dy][dx]}, {dy, dx}});
        }
    }
    cout << map[X][Y];
    return 0;
}
