#include<iostream>
using namespace std;

int N, t, idx[1000001], arr[500000];
long long ans, tree[4000001];
long long get_sum(int start, int end, int idx, int from, int to){
    int mid;
    
    if(from > end || to < start) return 0;
    if(from <= start && end <= to) return tree[idx];
    mid = (start + end) / 2;
    return get_sum(start, mid, idx * 2, from, to) + get_sum(mid + 1, end, idx * 2 + 1, from, to);
}
void change(int start, int end, int idx, int target, long long diff){
    int mid;
    
    if(start > target || target > end) return;
    tree[idx] += diff;
    if(start == end) return;
    mid = (start + end) / 2;
    change(start, mid, idx * 2, target, diff);
    change(mid + 1, end, idx * 2 + 1, target, diff);
}
int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> t;
        idx[t] = i;
    }
    for(int i = 0; i < N; i++){
        cin >> t;
        arr[i] = idx[t];
    }
    for(int i = 0; i < N; i++){
        ans += get_sum(0, N - 1, 1, arr[i] + 1, N - 1);
        change(0, N - 1, 1, arr[i], 1);
    }
    cout << ans;
    return 0;
}
