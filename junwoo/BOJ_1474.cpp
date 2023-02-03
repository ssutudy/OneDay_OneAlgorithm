#include<iostream>
#include<vector>
#include<string>
using namespace std;

vector<string> words;
int N, M, cnt, letter_cnt;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
  
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        string word;
        
        cin >> word;
        letter_cnt += word.size();
        words.push_back(word);
    }
    cnt = (M - letter_cnt) / (N - 1);
    M -= letter_cnt + cnt * (N - 1);
    for(int i = 0; i < N - 1; i++){
        cout << words[i];
        if(M > 0 && ((words[i + 1][0] >= 'a' && words[i + 1][0] <= 'z') || N - i - 1 <= M)) M--, cout << '_';
        for(int j = 0; j < cnt; j++) cout << '_';
    }
    cout << words[N - 1];
    return 0;
}
