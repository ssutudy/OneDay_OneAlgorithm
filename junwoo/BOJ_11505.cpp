#include<iostream>
using namespace std;

const long long MOD = 1000000007;
long long N, M, K, a, b, c, num[1000000], tree[4000000];
long long init(int start, int end, int idx){
    int mid;

    if(start == end) return tree[idx] = num[start];
    mid = (start + end) / 2;
    return tree[idx] = ((long long)init(start, mid, idx * 2) * init(mid + 1, end, idx * 2 + 1)) % MOD;
}
long long get_res(int start, int end, int idx, int from, int to){
    int mid;

    if(from > end || to < start) return 1;
    if(from <= start && end <= to) return tree[idx];
    mid = (start + end) / 2;
    return (get_res(start, mid, idx * 2, from, to) * get_res(mid + 1, end, idx * 2 + 1, from, to)) % MOD;
}
long long change(int start, int end, int idx, int target){
    int mid;

    if(start > target || target > end) return tree[idx];
    if(start == end) return tree[idx] = num[start];
    mid = (start + end) / 2;
    return tree[idx] = (change(start, mid, idx * 2, target) * change(mid + 1, end, idx * 2 + 1, target)) % MOD;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N >> M >> K;
    for(int i = 0; i < N; i++) cin >> num[i];
    init(0, N - 1, 1);
    M += K;
    while(M--){
        cin >> a >> b >> c;
        if(a != 1) cout << get_res(0, N - 1, 1, b - 1, c - 1) << '\n';
        else{
            num[b - 1] = c;
            change(0, N - 1, 1, b - 1);
        }
    }
    return 0;
}
