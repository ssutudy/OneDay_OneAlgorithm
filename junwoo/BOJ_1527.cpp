#include<iostream>
#include<queue>
using namespace std;

long long A, B, ans;
queue<long long> que;
int main(){
    cin >> A >> B;
    que.push(4);
    que.push(7);
    while(!que.empty()){
        long long num = que.front();
        
        que.pop();
        if(num >= A && num <= B) ans++;
        num = num * 10 + 4;
        if(num <= B) que.push(num);
        num += 3;
        if(num <= B) que.push(num);
    }
    cout << ans;
    return 0;
}
