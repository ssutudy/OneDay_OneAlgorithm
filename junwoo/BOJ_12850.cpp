#include<iostream>
#include<vector>
using namespace std;
typedef vector<vector<long long> > matrix;

int D;
const long long MOD = 1000000007;
matrix ans, graph = {
    {0, 1, 1, 0, 0, 0, 0, 0},
    {1, 0, 1, 1, 0, 0, 0, 0},
    {1, 1, 0, 1, 1, 0, 0, 0},
    {0, 1, 1, 0, 1, 1, 0, 0},
    {0, 0, 1, 1, 0, 1, 0, 1},
    {0, 0, 0, 1, 1, 0, 1, 0},
    {0, 0, 0, 0, 0, 1, 0, 1},
    {0, 0, 0, 0, 1, 0, 1, 0}
};
matrix matrix_multiply(matrix left, matrix right){
    matrix ret;
    
    ret.resize(8, vector<long long>(8));
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            long long val = 0;
            for(int k = 0; k < 8; k++){
                val = (val + left[i][k] * right[k][j]) % MOD;
            }
            ret[i][j] = val;
        }
    }
    return ret;
}
int main(){
    cin >> D;
    ans.resize(8, vector<long long>(8, 0));
    for(int i = 0; i < 8; i++) ans[i][i] = 1;
    while(D > 0){
        if(D % 2 == 1){
            ans = matrix_multiply(ans, graph);
            D--;
        }
        graph = matrix_multiply(graph, graph);
        D /= 2;
    }
    cout << ans[0][0];
    return 0;
}
