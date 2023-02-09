#include<iostream>
using namespace std;

int N, ans;
char map[3][100000];
const int MAX = 100001;
void reset_arr(){
    for(int i = 0; i < N; i++) map[0][i] = map[2][i];
}
void flip(int idx){
    idx--;
    for(int i = 0; i < 3; i++){
        if(idx >= 0 && idx < N) map[0][idx] = (map[0][idx] == '0')? '1' : '0';
        idx++;
    }
}
int greedy_solve(){
    int press_cnt = 0;
    
    for(int i = 1; i < N; i++){
        if(map[0][i - 1] == map[1][i - 1]) continue; 
        flip(i), press_cnt++;
    }
    return (map[0][N - 1] != map[1][N - 1])? MAX : press_cnt;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N;
    for(int i = 0; i < N; i++) cin >> map[2][i];
    for(int i = 0; i < N; i++) cin >> map[1][i];
    reset_arr();
    ans = greedy_solve();
    reset_arr();
    flip(0);
    ans = min(ans, greedy_solve() + 1);
    cout << ((ans == MAX)? -1 : ans);
    return 0;
}
