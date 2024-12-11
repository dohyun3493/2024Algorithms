#include<iostream>
#include<vector>
#include<utility>
using namespace std;

int n, m;

int MST_PRIM(vector<vector<pair<int, int>>>& G, int r){
    int sum = 0;
    vector<int> d(n + 1, INT16_MAX);
    vector<int> tree(n + 1, - 1);
    vector<bool> inMST(n + 1, false);

    d[r] = 0;

    for(int i = 0; i < n; i++){
        int u = -1;
        int min = INT16_MAX;

        for(int j = 1; j <= n; j++){
            if(inMST[j] == false && d[j] < min){
                min = d[j];
                u = j;
            }
        }

        cout << u << " ";

        inMST[u] = true;

        for(pair<int, int> edge : G[u]) {
            int v = edge.first;
            int weight = edge.second;

            if(inMST[v] == false && weight < d[v]) {
                d[v] = weight;
                tree[v] = u;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        if (tree[i] != -1) {
            sum += d[i];
        }
    }

    return sum;
}

int main(){
    cin >> n >> m;
    vector<vector<pair<int, int>>> graph(n + 1);

    for(int i = 0; i < m; i++){
        int x, y, w;
        cin >> x >> y >> w;

        graph[x].push_back(make_pair(y, w));
        graph[y].push_back(make_pair(x, w));
    }

    cout << MST_PRIM(graph, 1) << endl;

    return 0;
}