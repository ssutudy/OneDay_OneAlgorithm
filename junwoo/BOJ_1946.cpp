#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int T, N, ans, prev_min;
vector<pair<int, int> > arr;
int main(){
    cin >> T;
    while(T--){
        cin >> N;
        ans = 1;
        arr.resize(N);
        for(int i = 0; i < N; i++) cin >> arr[i].first >> arr[i].second;
        sort(arr.begin(), arr.end());
        prev_min = arr[0].second;
        for(int i = 1; i < N; i++){
            if(prev_min < arr[i].second) continue;
            ans++;
            prev_min = arr[i].second;
        }
        cout << ans << '\n';
    }
    return 0;
}
