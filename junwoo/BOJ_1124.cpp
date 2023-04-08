#include<iostream>
using namespace std;

int A, B, ans, DP[100001];
bool not_prime[100001];
int main(){
    cin >> A >> B;
    not_prime[0] = not_prime[1] = true;
    for(int i = 2; i <= B; i++){
        if(not_prime[i]) continue;
        DP[i] = 1;
        for(int j = 2 * i; j <= B; j += i){
            not_prime[j] = true;
        }
    }
    for(int i = 2; i <= B; i++){
        int j = 2;
        
        if(DP[i] != 0) continue;
        while(1){
            if(i % j == 0){
                DP[i] = DP[i / j] + 1;
                break;
            }
            j++;
            while(not_prime[j]){ j++; }
        }
    }
    for(int i = A; i <= B; i++){
        if(!not_prime[DP[i]]) ans++;
    }
    cout << ans;
    return 0;
}
