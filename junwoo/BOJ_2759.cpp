#include<iostream>
#include<vector>
using namespace std;

int T, N, bottom, sze, pancake[30];
void flip_cake(int s, int e){
    for(int i = 0; i < (e - s + 1) / 2; i++){
        swap(pancake[s + i], pancake[e - i]);
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> T;
    while(T--){
        vector<int> ans;
        cin >> N;
        bottom = N - 1;
        for(int i = 0; i < N; i++) cin >> pancake[i];
        while(1){
            int max_idx = 0;

            while(bottom > -1 && pancake[bottom] == (bottom + 1)) bottom--;
            if(bottom == -1) break;
            for(int i = 1; i < bottom; i++){
                if(pancake[max_idx] < pancake[i]) max_idx = i;
            }
            if(max_idx == 0) flip_cake(0, bottom), ans.push_back(bottom);
            else flip_cake(0, max_idx), ans.push_back(max_idx);
        }
        cout << ans.size() << ' ';
        for(int i = 0; i < ans.size(); i++) cout << ans[i] + 1 << ' ';
        cout << '\n';
    }
    return 0;
}
