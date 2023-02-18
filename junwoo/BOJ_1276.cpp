#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int N, ans, h, s, e, hei[10001];
vector<pair<int, pair<int, int> > > coord;
int main(){
    cin >> N;
    while(N--){
        cin >> h >> s >> e;
        coord.push_back({h, {s, e}});
    }
    sort(coord.begin(), coord.end());
    for(int i = 0; i < coord.size(); i++){
        h = coord[i].first;
        s = coord[i].second.first;
        e = coord[i].second.second;
        ans += 2 * h - (hei[s] + hei[e - 1]);
        for(int j = s; j < e; j++) hei[j] = h;
    }
    cout << ans;
    return 0;
}
