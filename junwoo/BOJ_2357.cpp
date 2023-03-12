#include<iostream>
#include<utility>
using namespace std;

int N, M, a, b, num[100000];
pair<int, int> res, tree[400000];
pair<int, int> init(int start, int end, int idx){
    int mid;
    pair<int, int> left, right;

    if(start == end) return tree[idx] = {num[start], num[start]};
    mid = (start + end) / 2;
    left = init(start, mid, idx * 2);
    right = init(mid + 1, end, idx * 2 + 1);
    return tree[idx] = {min(left.first, right.first), max(left.second, right.second)};
}
pair<int, int> get_minmax(int start, int end, int idx, int from, int to){
    int mid;
    pair<int, int> left, right;

    if(from > end || to < start) return {1000000000, 1};
    if(from <= start && end <= to) return tree[idx];
    mid = (start + end) / 2;
    left = get_minmax(start, mid, idx * 2, from, to);
    right = get_minmax(mid + 1, end, idx * 2 + 1, from, to);
    return {min(left.first, right.first), max(left.second, right.second)};
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    cin >> N >> M;
    for(int i = 0; i < N; i++) cin >> num[i];
    init(0, N - 1, 1);
    while(M--){
        cin >> a >> b;
        res = get_minmax(0, N - 1, 1, a - 1, b - 1);
        cout << res.first << ' ' << res.second << '\n';
    }
    return 0;
}
