#include<iostream>
#include<vector>
using namespace std;

int N, ans;
bool diag[20][2];
vector<pair<int, int> > pos[2];
int solve(int idx, int part){
    int res = 0;

    for(int i = idx; i < pos[part].size(); i++){
        int y, x;

        y = pos[part][i].first;
        x = pos[part][i].second;
        if(diag[(N - y - 1) + x][0] || diag[y + x][1]) continue;
        diag[(N - y - 1) + x][0] = true;
        diag[y + x][1] = true;
        res = max(res, solve(i + 1, part) + 1);
        diag[(N - y - 1) + x][0] = false;
        diag[y + x][1] = false;
    }
    return res;
}
int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            int val;

            cin >> val;
            if(val == 1) pos[(i + j) % 2].push_back({i, j});
        }
    }
    cout << solve(0, 0) + solve(0, 1);
    return 0;
}
