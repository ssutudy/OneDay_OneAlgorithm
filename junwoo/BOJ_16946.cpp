#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

int N, M;
char map[1000][1000];
bool visited[1000][1000];
vector<pair<int, int> > in_group;
int ans[1000][1000], dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int dfs(int y, int x){
    int dy, dx, cnt = 1;
    
    visited[y][x] = true;
    for(int i = 0; i < 4; i++){
        dy = y + dir[i][0];
        dx = x + dir[i][1];
        if(dy < 0 || dy >= N || dx < 0 || dx >= M || visited[dy][dx]) continue;
        if(map[dy][dx] == '0') cnt = (cnt + dfs(dy, dx)) % 10;
        else{
            visited[dy][dx] = true;
            in_group.push_back({dy, dx});
        }
    }
    return cnt;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++) cin >> map[i][j];
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            int dy, dx, ret = 0;
            
            if(visited[i][j]) continue;
            if(map[i][j] == '1'){
                ans[i][j] = (ans[i][j] + 1) % 10;
                continue;
            }
            ret = dfs(i, j);
            for(int k = 0; k < in_group.size(); k++){
                dy = in_group[k].first;
                dx = in_group[k].second;
                ans[dy][dx] = (ans[dy][dx] + ret) % 10;
                visited[dy][dx] = false;
            }
            in_group.clear();
        }
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cout << ans[i][j];
        }
        cout << '\n';
    }
    return 0;
}
