#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int N, C;
vector<int> x;
int solve(){
    int left, right, mid;
    
    left = 0;
    right = x[N - 1];
    while(left <= right){
        int above, prev;
        
        above = 1;
        prev = x[0];
        mid = (left + right) / 2;
        for(int i = 1; i < N; i++){
            if((x[i] - prev) < mid) continue;
            above++;
            prev = x[i];
        }
        if(above < C) right = mid - 1;
        else left = mid + 1;
    }
    return right;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
   
    cin >> N >> C;
    for(int i = 0; i < N; i++){
        int temp;

        cin >> temp;
        x.push_back(temp);
    }
    sort(x.begin(), x.end());
    cout << solve();
    return 0;
}
