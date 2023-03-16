#include<iostream>
#include<queue>
using namespace std;

int m, n, x, y, z, ans, parent[200000];
priority_queue<pair<int, pair<int, int> > > edges;
int get_parent(int i){
    if(i == parent[i]) return i;
    return parent[i] = get_parent(parent[i]);
}
bool union_parent(int a, int b){
    a = get_parent(a);
    b = get_parent(b);
    
    if(a == b) return false;
    if(a > b) parent[a] = b;
    else parent[b] = a;
    return true;
}
int main(){
    while(1){
        cin >> m >> n;
        if(m == 0 && n == 0) break;
        ans = 0;
        for(int i = 0; i < m; i++) parent[i] = i;
        while(n--){
            cin >> x >> y >> z;
            edges.push({-z, {x, y}});
        }
        while(!edges.empty()){
            int dist = -edges.top().first;
            pair<int, int> pos = edges.top().second;
            
            edges.pop();
            if(!union_parent(pos.first, pos.second)){
                ans += dist;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
