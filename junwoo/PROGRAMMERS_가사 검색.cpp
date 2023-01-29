#include<string>
#include<vector>
#include<cstring>
#include<map>
using namespace std;

struct Trie{
    map<int, int> count;
    Trie* next[26];
    
    Trie(){
        memset(next, 0, sizeof(next));
    }
    
    ~Trie(){
        for(int i = 0; i < 26; i++){
            if(!next[i]) continue;
            delete next[i];
        }
    }
    
    void insert(const string& word, int idx, bool reversed){
        int i;
        
        count[word.size() - idx]++;
        if(idx == word.size()) return;
        
        if(reversed) i = word[word.size() - idx - 1] - 'a';
        else i = word[idx] - 'a';
        if(!next[i]) next[i] = new Trie();
        next[i]->insert(word, idx + 1, reversed);
    }
    
    int find(const string& word, int idx, bool reversed){
        int i;
        char c;
        
        if(reversed) c = word[word.size() - idx - 1];
        else c = word[idx];
        
        if(c == '?') return count[word.size() - idx];
        i = c - 'a';
        if(!next[i]) return 0;
        return next[i]->find(word, idx + 1, reversed);
    }
};
vector<int> solution(vector<string> words, vector<string> queries) {
    vector<int> answer;
    Trie head, reverse_head;
    for(int i = 0; i < words.size(); i++){
        head.insert(words[i], 0 , false);
        reverse_head.insert(words[i], 0 , true);
    }
    for(int i = 0; i < queries.size(); i++){
        int res;

        if(queries[i][0] == '?') res = reverse_head.find(queries[i], 0, true);
        else res = head.find(queries[i], 0, false);
        answer.push_back(res);
    }
    return answer;
}