#include<iostream>
#include<queue>
using namespace std;

int N, ans, num[2];
priority_queue<int> que;
int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> num[0];
        que.push(-num[0]);
    }
    while(N > 1){
        num[0] = que.top();
        que.pop();
        num[1] = que.top();
        que.pop();
        ans -= (num[0] + num[1]);
        que.push(num[0] + num[1]);
        N--;
    }
    cout << ans;
    return 0;
}
