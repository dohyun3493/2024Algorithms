#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool visited[1001] = {false, };
vector<vector<int>> v;

void DFS(int idx){
    cout << idx << " ";
    visited[idx] = true;
    for(int i = 0; i < v[idx].size(); i++){
        if(visited[v[idx][i]] == false) {
            DFS(v[idx][i]);
        }
    }
}

int main(){
    int n, m, start_node;

    cin >> n >> m;

    v.resize(n + 1);

    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    
    for(int i = 1; i <= n; i++) sort(v[i].begin(), v[i].end());
    cin >> start_node;

    DFS(start_node);
    cout << endl;

    return 0;
}