#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N;
vector<int> num_list;
int calc_dist(int idx){
    int res = 0;
    
    for(int i = 0; i < N; i++){
        res += abs(num_list[i] - num_list[idx]);
    }
    return res;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    cin >> N;
    for(int i = 0; i < N; i++){
        int num;
        
        cin >> num;
        num_list.push_back(num);
    }
    sort(num_list.begin(), num_list.end());
    cout << num_list[((calc_dist(N / 2) < calc_dist((N - 1) / 2))? N / 2 : (N - 1) / 2)];
    return 0;
}
