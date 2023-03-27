#include<iostream>
#include<string>
using namespace std;

string s;
int ans, a_cnt;
int main(){
    cin >> s;
    ans = 1001;
    for(int i = 0; i < s.size(); i++) if(s[i] == 'a') a_cnt++;
    for(int i = 0; i < s.size(); i++){
        int temp_ans = 0;
        
        for(int j = i; j < a_cnt + i; j++){
            if(s[j % s.size()] == 'b') temp_ans++;
        }
        ans = min(ans, temp_ans);
    }
    cout << ans;
    return 0;
}
