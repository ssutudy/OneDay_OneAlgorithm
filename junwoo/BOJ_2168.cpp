#include<iostream>
using namespace std;

int x, y, g;
int gcd(int a, int b){
    if(b == 0) return a;
    return gcd(b, a % b);
}
int main(){
    cin >> x >> y;
    g = gcd(x, y);
    x /= g;
    y /= g;
    cout << g * (x + y - 1);
    return 0;
}
