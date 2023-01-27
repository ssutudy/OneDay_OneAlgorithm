#include<iostream>
#include<algorithm>
using namespace std;

int ans, N, A[1000];
int main(){
    cin >> N;
    for(int i = 0; i < N; i++) cin >> A[i];
    ans = 1;
    sort(A, A + N);
    for(int i = 0; i < N; i++){
        if(ans < A[i]) break;
        ans += A[i];
    }
    cout << ans;
    return 0;
}