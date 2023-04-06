#include<iostream>
using namespace std;

int N, M, A[100001], tree[400000];
int get_min_idx(int a, int b){
    if(A[a] > A[b]) return b;
    return a;
}
int init(int s, int e, int idx){
    int mid;
    
    if(s == e) return tree[idx] = s;
    mid = (s + e) / 2;
    return tree[idx] = get_min_idx(init(s, mid, idx * 2), init(mid + 1, e, idx * 2 + 1));
}
int update(int s, int e, int idx, int target){
    int mid;
    
    if(s > target || e < target) return tree[idx];
    if(s == e) return tree[idx];
    mid = (s + e) / 2;
    return tree[idx] = get_min_idx(update(s, mid, idx * 2, target), update(mid + 1, e, idx * 2 + 1, target));
}
int get_min(int s, int e, int idx, int f, int t){
    int mid;
    
    if(s > t || e < f) return N;
    if(f <= s && e <= t) return tree[idx];
    mid = (s + e) / 2;
    return get_min_idx(get_min(s, mid, idx * 2, f, t), get_min(mid + 1, e, idx * 2 + 1, f, t));
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    cin >> N;
    for(int i = 0; i < N; i++) cin >> A[i];
    A[N] = 2e9;
    init(0, N - 1, 1);
    cin >> M;
    while(M--){
        int m, i, j;
        
        cin >> m >> i >> j;
        i--;
        if(m == 1){
            A[i] = j;
            update(0, N - 1, 1, i);
        }
        else{
            j--;
            cout << get_min(0, N - 1, 1, i, j) + 1 << '\n';
        }
    }
}
