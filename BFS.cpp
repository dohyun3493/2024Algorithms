#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

bool visited[1001] = {false, };
vector<vector<int>> v;
queue<int> q;

void BFS(int idx){
    visited[idx] = true;
    q.push(idx);

    while(!q.empty()){
        int u = q.front();
        q.pop();
        cout << u << " ";

        for(int i = 0; i < v[u].size(); i++){
            if(visited[v[u][i]] == false){
                visited[v[u][i]] = true;
                q.push(v[u][i]);
            }
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

    BFS(start_node);
    cout << endl;

    return 0;
}