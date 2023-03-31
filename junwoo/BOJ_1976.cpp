#include<iostream>
using namespace std;

bool can_travel;
int N, M, c, tgt, parent[201];
int find_parent(int i){
    if(i == parent[i]) return i;
    return parent[i] = find_parent(parent[i]);
}
bool union_parent(int a, int b){
    a = find_parent(a);
    b = find_parent(b);
    if(a == b) return false;
    if(a > b) parent[a] = b;
    else parent[b] = a;
    return true;
}
int main(){
    cin >> N >> M;
    for(int i = 1; i <= N; i++) parent[i] = i;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> c;
            if(c == 1) union_parent(i + 1, j + 1);
        }
    }
    can_travel = true;s
    while(M--){
        cin >> c;
        if(tgt == 0) tgt = find_parent(c);
        else if(tgt != find_parent(c)) can_travel = false;
    }
    cout << ((can_travel)? "YES" : "NO");
    return 0;
}
