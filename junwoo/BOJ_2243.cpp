#include<iostream>
using namespace std;

int N, a, b, c, cnt, tree[4000000];
int get_res(int start, int end, int idx, int rank){
    int mid;

    if(start == end) return start;
    mid = (start + end) / 2;
    if(tree[idx * 2] < rank) return get_res(mid + 1, end, idx * 2 + 1, rank - tree[idx * 2]);
    else return get_res(start, mid, idx * 2, rank);
}
void change(int start, int end, int idx, int target, int diff){
    int mid;

    if(start > target || target > end) return;
    tree[idx] += diff;
    if(start == end) return;
    mid = (start + end) / 2;
    change(start, mid, idx * 2, target, diff);
    change(mid + 1, end, idx * 2 + 1, target, diff);
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N;
    while(N--){
        cin >> a >> b;
        if(a == 1){
            c = get_res(0, 999999, 1, b);
            cout << c + 1 << '\n';
            change(0, 999999, 1, c, -1);
        }
        else{
            cin >> c;
            change(0, 999999, 1, b - 1, c);
        }
    }
    return 0;
}
