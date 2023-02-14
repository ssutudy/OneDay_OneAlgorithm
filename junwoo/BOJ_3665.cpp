#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

vector<int> graph[501], result;
int T, grade[500], order[501], rnk[501];
int main(){
    cin >> T;
    while(T--){
        int n, m;

        cin >> n;
        result.clear();
        memset(order, 0, sizeof(order));
        for(int i = 0; i < n; i++){
            cin >> grade[i];
            order[grade[i]] = rnk[grade[i]] = i;
            graph[grade[i]].clear();
        }
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++) graph[grade[i]].push_back(grade[j]);
        }
        cin >> m;
        for(int i = 0; i < m; i++){
            int a, b;

            cin >> a >> b;
            if(rnk[a] < rnk[b]) swap(a, b);
            order[a]--;
            order[b]++;
            graph[a].push_back(b);
        }
        while(1){
            int i;
            for(i = 0; i < n; i++){
                if(order[grade[i]] == 0) break;
            }
            if(i == n) break;
            order[grade[i]]--;
            result.push_back(grade[i]);
            for(int j = 0; j < graph[grade[i]].size(); j++){
                if(order[graph[grade[i]][j]] > 0) order[graph[grade[i]][j]]--;
            }
        }
        if(result.size() != n) cout << "IMPOSSIBLE";
        else for(int i = 0; i < n; i++) cout << result[i] << ' ';
        cout << '\n';
    }
    return 0;
}