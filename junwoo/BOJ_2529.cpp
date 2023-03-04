#include<iostream>
using namespace std;

char comprend[9];
bool has_min, used[10];
int k, max_res[10], min_res[10], num[10];
bool check(){
    for(int i = 0; i < k; i++){
        if((comprend[i] == '<' && num[i] > num[i + 1]) ||
           (comprend[i] == '>' && num[i] < num[i + 1])) return false;
    }
    return true;
}
void trace(int cnt){
    if(cnt == (k + 1)){
        if(!check()) return;
        for(int i = 0; i <= k; i++){
            if(!has_min) min_res[i] = num[i];
            max_res[i] = num[i];
        }
        has_min = true;
    }
    else{
        for(int i = 0; i < 10; i++){
            if(used[i]) continue;
            num[cnt] = i;
            used[i] = true;
            trace(cnt + 1);
            used[i] = false;
        }
    }
}
int main(){
    cin >> k;
    for(int i = 0; i < k; i++) cin >> comprend[i];
    trace(0);
    for(int i = 0; i <= k; i++) cout << max_res[i];
    cout << '\n';
    for(int i = 0; i <= k; i++) cout << min_res[i];
    return 0;
}
