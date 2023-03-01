#include<iostream>
#include<utility>
using namespace std;

typedef pair<int, int> point;

pair<point, point> pos[3000];
int N, ans, all_grp, max_cnt, parent[3000], grp_cnt[3000];
int find(int a){
    if(a == parent[a]) return a;
    return parent[a] = find(parent[a]);
}
void union_parent(int a, int b){
    a = find(a);
    b = find(b);
    if(a > b) parent[a] = b;
    else parent[b] = a;
}
int ccw(point a, point b, point c){
    int val;
    val = a.first * b.second + b.first * c.second + c.first * a.second;
    val = val - a.second * b.first - b.second * c.first - c.second * a.first;

    if(val > 0) return 1;
    else if(val == 0) return 0;
    else return -1;
}
bool check(int i, int j){
    int abc, abd, cda, cdb;

    abc = ccw(pos[i].first, pos[i].second, pos[j].first);
    abd = ccw(pos[i].first, pos[i].second, pos[j].second);
    cda = ccw(pos[j].first, pos[j].second, pos[i].first);
    cdb = ccw(pos[j].first, pos[j].second, pos[i].second);
    if(abc * abd == 0 && cda * cdb == 0){
        return pos[i].first <= pos[j].second && pos[j].first <= pos[i].second;
    }
    return abc * abd <= 0 && cda * cdb <= 0;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> N;
    for(int i = 0; i < N; i++){
        parent[i] = i;
        cin >> pos[i].first.first >> pos[i].first.second >> pos[i].second.first >> pos[i].second.second;
        if(pos[i].first > pos[i].second) swap(pos[i].first, pos[i].second);
    }
    for(int i = 0; i < N; i++){
        for(int j = i + 1; j < N; j++){
            if(check(i, j)){
                union_parent(i, j);
            }
        }
    }
    for(int i = 0; i < N; i++){
        grp_cnt[find(i)]++;
    }
    for(int i = 0; i < N; i++){
        if(grp_cnt[i] == 0) continue;
        all_grp++;
        max_cnt = max(max_cnt, grp_cnt[i]);
    }
    cout << all_grp << '\n' << max_cnt;
    return 0;
}
