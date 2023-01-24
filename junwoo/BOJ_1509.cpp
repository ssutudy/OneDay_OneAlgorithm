#include<iostream>
#include<string>
using namespace std;

string str;
int part[2501];
bool check[2500][2500];
int solve(){
    part[0] = 0;
    for(int i = 0; i < str.size(); i++){
        part[i + 1] = 2501;
        for(int j = 0; j <= i; j++){
            if(!check[j][i]) continue;
            part[i + 1] = min(part[i + 1], part[j] + 1);
        }
    }
    return part[str.size()];
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    cin >> str;
    for(int i = 0; i < str.size(); i++){
        for(int j = 0; i + j < str.size(); j++){
            if(i == 0) check[j][j + i] = true;
            else if(i == 1) check[j][j + i] = str[j] == str[j + i];
            else check[j][j + i] = str[j] == str[j + i] && check[j + 1][j + i -1];
        }
    }
    cout << solve();
    return 0;
}