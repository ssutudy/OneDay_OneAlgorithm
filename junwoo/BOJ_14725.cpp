#include<iostream>
#include<map>
#include<string>
using namespace std;

struct Trie{
    int depth;
    map<string, Trie*> child;
    
    Trie(int depth){
        this->depth = depth;
    }
    
    ~Trie(){
        for(auto trie : child) delete trie.second;
    }

    void insert(const vector<string>& word, int idx){
        Trie *next = child[word[idx]];
        
        if(!next){
            next = new Trie(idx + 1);
            child[word[idx]] = next;
        }
        if((idx + 1) < word.size()) next->insert(word, idx + 1);
    }
    
    void show(){
        for(auto trie : child){
            for(int i = 0; i < depth; i++) cout << "--";
            cout << trie.first << '\n';
            trie.second->show();
        }
    }
};

string t;
int N, K;
Trie head(0);
int main(){
    cin >> N;
    while(N--){
        vector<string> words;
        
        cin >> K;
        while(K--){
            cin >> t;
            words.push_back(t);
        }
        head.insert(words, 0);
    }
    head.show();
    return 0;
}
