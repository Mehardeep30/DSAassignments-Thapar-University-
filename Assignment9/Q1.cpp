#include <bits/stdc++.h>
using namespace std;
vector<int> bfsOfGraph(int V,vector<int> adj[]) {
    queue<int> q;
    q.push(0);
    int vis[V]={0};
    vis[0]=1;
    vector<int> ans;
    while (!q.empty()) {
        int node=q.front();
        q.pop();
        ans.push_back(node);
        for (auto it:adj[node]) {
            if (!vis[it]) {
                q.push(it);
                vis[it]=1;
            }
        }
    }
    return ans;
}
int main() {
    vector<int> adj[6] = {
        {1, 2},        // 0
        {0, 3, 4},     // 1
        {0, 4},        // 2
        {1},           // 3
        {1, 2, 5},     // 4
        {4}            // 5
    };
    vector<int> ans=bfsOfGraph(6,adj);
    for (auto it:ans) {
        cout<<it<<" ";
    }
    return 0;
}
