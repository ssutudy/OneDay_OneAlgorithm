#include<iostream>
#include<string>
using namespace std;

string a, b;
int DP[1001][1001];
int main(){
    cin >> a >> b;
    for(int i = 0; i <= max(a.size(), b.size()); i++) DP[0][i] = DP[i][0] = i;
    for(int i = 0; i < a.size(); i++){
        for(int j = 0; j < b.size(); j++){
            if(a[i] == b[j]) DP[i + 1][j + 1] = DP[i][j];
            else DP[i + 1][j + 1] = min(DP[i][j], min(DP[i][j + 1], DP[i + 1][j])) + 1;
        }
    }
    cout << DP[a.size()][b.size()];
    return 0;
}
