#include<iostream>
#include<stack>
using namespace std;

int N, num;
long long ans;
stack<pair<int, long long> > stk;
int main(){
    cin >> N;
    while(N--){
        long long cnt = 1;
        
        cin >> num;
        if(!stk.empty()){
            while(!stk.empty() && stk.top().first <= num){
                ans += stk.top().second;
                if(stk.top().first == num) cnt += stk.top().second;
                stk.pop();
            }
            if(!stk.empty()) ans++;
        }
        stk.push({num, cnt});
    }
    cout << ans;
    return 0;
}
