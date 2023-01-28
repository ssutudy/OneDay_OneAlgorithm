#include<iostream>
#include<string>
#include<cstring>
using namespace std;

struct Trie{
    bool is_terminated;
    Trie* next[10];
    
    Trie(){
        is_terminated = false;
        memset(next, 0, sizeof(next));
    }
    
    ~Trie(){
        for(int i = 0; i < 10; i++){
            if(!next[i]) continue;
            delete next[i];
        }
    }
    
    bool insert(const string& word, int idx){
        int i;
        
        if(idx == word.size()){
            is_terminated = true;
            for(int i = 0; i < 10; i++){
                if(next[i]) return false;
            }
            return true;
        }
        if(is_terminated) return false;
        i = word[idx] - '0';
        if(!next[i]) next[i] = new Trie();
        return next[i]->insert(word, idx + 1);
    }
};

int T, N;
string word;
bool is_right;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> T;
    while(T--){
        Trie* trie = new Trie();
        cin >> N;
        is_right = true;
        while(N--){
            cin >> word;
            if(is_right) is_right = trie->insert(word, 0);
        }
        cout << ((is_right)? "YES" : "NO") << '\n';
        delete trie;
    }
    return 0;
}