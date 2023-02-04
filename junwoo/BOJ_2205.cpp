#include<iostream>
using namespace std;

int N, tin[11001];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    cin >> N;
    for(int i = N; i > 0; i--){
        int least = 2;
        if(tin[i]) continue;
        while(1){
            if(least > i && tin[least - i] == 0){
                tin[least - i] = i;
                tin[i] = least - i;
                break;
            }
            least *= 2;
        }
    }
    for(int i = 1; i <= N; i++) cout << tin[i] << '\n';
    return 0;
}
