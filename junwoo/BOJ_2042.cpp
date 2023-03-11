#include<iostream>
#include<vector>
using namespace std;

int N, M, K, a, b;
long long c, tree[4000001], num[1000000];
long long init(int start, int end, int idx){
    int mid;
    
    if(start == end) return tree[idx] = num[start];
    mid = (start + end) / 2;
    return tree[idx] = init(start, mid, idx * 2) + init(mid + 1, end, idx * 2 + 1);
}
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
    cin >> N >> M >> K;
    for(int i = 0; i < N; i++) cin >> num[i];
    init(0, N - 1, 1);
    while(M + K){
        cin >> a >> b >> c;
        b--;
        if(a == 1){
            M--;
            change(0, N - 1, 1, b, c - num[b]);
            num[b] = c;
        }
        else{
            c--, K--;
            cout << get_sum(0, N - 1, 1, b, c) << '\n';
        } 
    }
    return 0;
}
