#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

int N, d, idx, ans;
priority_queue<int> que;
vector<pair<int, int> > roads;
int main(){
    cin >> N;
    while(N--){
        int from, to;
        cin >> from >> to;
        if(from > to) swap(from, to);
        roads.push_back({to, from});
    }
    cin >> d;
    sort(roads.begin(), roads.end());
    while(idx < roads.size()){
        int et = roads[idx].first;
        que.push(-roads[idx].second);
        while(!que.empty() && -que.top() < (et - d)) que.pop();
        ans = max(ans, (int)que.size());
        idx++;
    }
    cout << ans;
    return 0;
}
