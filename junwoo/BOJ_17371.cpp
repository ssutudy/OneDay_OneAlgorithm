#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int N, ans;
double min_dist, max_dist;
vector<pair<int, int> > pos_list;
double get_dist(pair<int, int> left, pair<int, int> right){
    return pow(left.first - right.first, 2) + pow(left.second - right.second, 2);
}
int main(){
    cin >> N;
    pos_list.resize(N);
    for(int i = 0; i < N; i++){
        cin >> pos_list[i].first >> pos_list[i].second;
    }
    max_dist = 1e9 + 1;
    for(int i = 0; i < N; i++){
        double cur_dist = 0;
        for(int j = 0; j < N; j++){
            double dist = get_dist(pos_list[i], pos_list[j]);
            
            cur_dist = max(cur_dist, dist);
        }
        if(cur_dist < max_dist){
            ans = i;
            max_dist = cur_dist;
        }
    }
    cout << pos_list[ans].first << ' ' << pos_list[ans].second;
    return 0;
}
