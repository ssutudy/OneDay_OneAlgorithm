#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> card_num;
int N, M, K, num, parent[4000000];
int find_parent(int n){
    if(parent[n] == n) return n;
    return parent[n] = find_parent(parent[n]);
}
void union_parent(int a, int b){
    int p_a, p_b;
    
    p_a = find_parent(a);
    p_b = find_parent(b);
    parent[p_a] = p_b;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
  
    cin >> N >> M >> K;
    for(int i = 0; i < M; i++){
        cin >> num;
        card_num.push_back(num);
        parent[i] = i;
    }
    sort(card_num.begin(), card_num.end());
    while(K--){
        int idx;
        
        cin >> num;
        idx = upper_bound(card_num.begin(), card_num.end(), num) - card_num.begin();
        cout << card_num[find_parent(idx)] << '\n';
        union_parent(idx, parent[idx] + 1);
    }
    return 0;
}
