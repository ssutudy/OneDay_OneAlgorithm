#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct point{
    int num, x, y, z;
};
struct edge{
    int dist, dst[2];
};

long long ans;
vector<point> pos;
vector<edge> edges;
int N, A, B, C, cnt, parent[100000];
int get_dist(int i, int j){
    return min(abs(pos[i].x - pos[j].x), min(abs(pos[i].y - pos[j].y), 
                                             abs(pos[i].z - pos[j].z)));
}
int get_parent(int idx){
    if(parent[idx] == idx) return idx;
    return parent[idx] = get_parent(parent[idx]);
}
bool union_parent(int left, int right){
    left = get_parent(left);
    right = get_parent(right);
    
    if(left == right) return false;
    if(left < right) parent[right] = left;
    else parent[left] = right;
    return true;
}
bool cmpx(const point& left, const point& right){
    return left.x < right.x;
}
bool cmpy(const point& left, const point& right){
    return left.y < right.y;
}
bool cmpz(const point& left, const point& right){
    return left.z < right.z;
}
bool cmp_edge(const edge& left, const edge& right){
    return left.dist < right.dist;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    bool (*sort_func[3])(const point&, const point&) = {cmpx, cmpy, cmpz}; 
    cin >> N;
    for(int i = 0; i < N; i++){
        parent[i] = i;
        cin >> A >> B >> C;
        pos.push_back({i, A, B, C});
    }
    for(int i = 0; i < 3; i++){
        sort(pos.begin(), pos.end(), sort_func[i]);
        for(int j = 0; j < (pos.size() - 1); j++){
            edges.push_back({get_dist(j, j + 1), pos[j].num, pos[j + 1].num});
        }
    }
    sort(edges.begin(), edges.end(), cmp_edge);
    for(int i = 0; i < edges.size(); i++){
        if(union_parent(edges[i].dst[0], edges[i].dst[1])){
            ans += edges[i].dist;
            cnt++;
        }
        if(cnt == (N - 1)) break;
    }
    cout << ans;
    return 0;
}
