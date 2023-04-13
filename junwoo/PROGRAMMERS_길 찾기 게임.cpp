#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> preorder, postorder;

void travel(vector<queue<pair<int, int> > >& que, int dep, int parent, int x, int prev_x){
    int cur_x, idx;
    
    if(que.size() == dep || que[dep].empty()) cur_x = 1e9;
    else{
        cur_x = que[dep].front().first;
        idx = que[dep].front().second;    
    }
    preorder.push_back(parent + 1);
    if(cur_x < x){
        que[dep].pop();
        travel(que, dep + 1, idx, cur_x, x);
        if(!que[dep].empty()){
            cur_x = que[dep].front().first;
            idx = que[dep].front().second;    
        }
        else cur_x = 1e9;
    }
    if(cur_x < prev_x){
        que[dep].pop();
        travel(que, dep + 1, idx, cur_x, prev_x);
    }
    postorder.push_back(parent + 1);
}
vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    int y, dep;
    vector<vector<int>> answer;
    vector<queue<pair<int, int> > > que;
    vector<pair<pair<int, int>, int> > node_info;
    
    for(int i = 0; i < nodeinfo.size(); i++){
        node_info.push_back({{-nodeinfo[i][1], nodeinfo[i][0]}, i});
    }
    sort(node_info.begin(), node_info.end());
    dep = 0;
    y = node_info[0].first.first;
    que.push_back(queue<pair<int, int> >());
    que[dep].push({node_info[0].first.second, node_info[0].second});
    for(int i = 1; i < node_info.size(); i++){
        if(y != node_info[i].first.first){
            dep++;
            que.push_back(queue<pair<int, int> >());
            y = node_info[i].first.first;
        }
        que[dep].push({node_info[i].first.second, node_info[i].second});
    }
    travel(que, 1, node_info[0].second, node_info[0].first.second, 1e9);
    answer.push_back(preorder);
    answer.push_back(postorder);
    return answer;
}
