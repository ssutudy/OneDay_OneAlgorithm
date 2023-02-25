#include<iostream>
using namespace std;

int N, ans;
long long pos[1500][2];
bool is_right_triangle(int a, int b, int c){
    long long ab, ac, bc;
    
    ab = (pos[a][0] - pos[b][0]) * (pos[a][0] - pos[b][0]) + (pos[a][1] - pos[b][1]) * (pos[a][1] - pos[b][1]);
    ac = (pos[a][0] - pos[c][0]) * (pos[a][0] - pos[c][0]) + (pos[a][1] - pos[c][1]) * (pos[a][1] - pos[c][1]);
    bc = (pos[b][0] - pos[c][0]) * (pos[b][0] - pos[c][0]) + (pos[b][1] - pos[c][1]) * (pos[b][1] - pos[c][1]);
    if(ab > ac && ab > bc) return ab == (ac + bc);
    if(ac > ab && ac > bc) return ac == (ab + bc);
    return bc == (ab + ac);
}
int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> pos[i][0] >> pos[i][1];
    }
    for(int i = 0; i < N; i++){
        for(int j = i + 1; j < N; j++){
            for(int k = j + 1; k < N; k++){
                if(is_right_triangle(i, j, k)) ans++;
            }
        }
    }
    cout << ans;
    return 0;
}
