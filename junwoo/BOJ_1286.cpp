#include<iostream>
using namespace std;

char c;
int N, M;
long long r_cnt, c_cnt, cnt[26];
int main(){
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        r_cnt = (i + 1) * (2 * N - i) + (i + N + 1) * (N - i);
        for(int j = 0; j < M; j++){
            cin >> c;
            c_cnt = (j + 1) * (2 * M - j) + (j + M + 1) * (M - j);
            cnt[c - 'A'] += r_cnt * c_cnt;
        }
    }
    for(int i = 0; i < 26; i++) cout << cnt[i] << '\n';
    return 0;
}
