#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool unused[100000];
vector<int> line_list, ans;
int N, last, idx, idx_list[100000];
pair<int, int> line_info[100000];
int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        int from, to;
        cin >> line_info[i].first >> line_info[i].second;
    }
    sort(line_info, line_info + N);
    for(int i = 0; i < N; i++){
        if(line_list.size() == 0 || line_list[line_list.size() - 1] < line_info[i].second){
            idx = line_list.size();
            line_list.push_back(line_info[i].second);
        }
        else{
            idx = lower_bound(line_list.begin(), line_list.end(), line_info[i].second) - line_list.begin();
            line_list[idx] = line_info[i].second;
        }
        idx_list[i] = idx;
    }
    
    int last = line_list.size() - 1;
    for(int i = N - 1; i > - 1; i--){
        if(last == idx_list[i]) last--;
        else ans.push_back(i);
    }
    cout << ans.size() << '\n';
    for(int i = ans.size() - 1; i > -1; i--){
        cout << line_info[ans[i]].first << '\n';
    }
    return 0;
}
