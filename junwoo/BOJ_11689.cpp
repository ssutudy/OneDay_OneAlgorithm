#include<iostream>
#include<cmath>
using namespace std;

long long N, ans;
int main(){
    cin >> N;
    ans = N;
    for(long long i = 2; i <= sqrt(N); i++){
        if(N % i != 0) continue;
        while(N % i == 0){ N /= i; }
        ans *= (double)(i - 1) / i;
    }
    if(N > 1) ans *= (double)(N - 1) / N;
    cout << ans;
    return 0;
}
