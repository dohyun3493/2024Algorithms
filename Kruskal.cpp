#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> parent, rankSet;

void makeSet(int n) {
    parent.resize(n + 1);
    rankSet.resize(n + 1, 0);
    for (int i = 1; i <= n; i++) parent[i] = i; 
    
}

int findSet(int v) {
    if (parent[v] != v) parent[v] = findSet(parent[v]); 
    return parent[v];
}

void unionSet(int u, int v) {
    int rootU = findSet(u);
    int rootV = findSet(v);

    if (rootU != rootV) {
        if (rankSet[rootU] < rankSet[rootV]) parent[rootU] = rootV;
        else if (rankSet[rootU] > rankSet[rootV]) parent[rootV] = rootU;
        else {
            parent[rootV] = rootU;
            rankSet[rootU]++;
        }
    }
}

int main() {
    int n, m;
    int total = 0;     
    vector<pair<int, int>> mst; 
    vector<pair<int, pair<int, int>>> edges;    
    vector<int> mstWeights;

    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({w, {u, v}}); 
    }

    makeSet(n); 
    sort(edges.begin(), edges.end()); 

    for (auto edge : edges) {
        int weight = edge.first;
        int u = edge.second.first;
        int v = edge.second.second;

        if (findSet(u) != findSet(v)) {
            total += weight;     
            unionSet(u, v);            
            mst.push_back({u, v});    
            mstWeights.push_back(weight);
        }
    }

    for (int i = 0; i < mstWeights.size(); i++) {
        cout << mstWeights[i] << " ";
    }

    cout << total << endl;

    return 0;
}