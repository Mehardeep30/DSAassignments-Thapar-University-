#include <bits/stdc++.h>
using namespace std;
void bfs(vector<int> adj[],int s,vector<int> &vis) {
    queue<int> q;
    vector<int> ans;
    q.push(s);
    vis[s]=1;
    while (!q.empty()) {
        int node=q.front(); q.pop();
        for (auto it:adj[node]) {
            if (!vis[it]) {
                q.push(it);
                vis[it]=1;
            }
        }
    }
}
int connectedComponents(int V,vector<vector<int>> edges) {
    int cnt=0;
    vector<int> adj[V];
    for (auto it:edges) {
        int u=it[0];
        int v=it[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> vis(V,0);
    for (int i=0;i<V;i++) {
        if (!vis[i]) {
            cnt++;
            bfs(adj,i,vis);
        }
    }
    return cnt;
}
int main() {
    vector<vector<int>> Edges = {
        {0, 1},
        {1, 2},
        {3, 4},
        {5, 6},
        {6, 7},
        {8, 9}
    };
    cout<<connectedComponents(10,Edges);
    return 0;
}
