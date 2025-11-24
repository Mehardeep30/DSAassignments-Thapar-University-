#include <bits/stdc++.h>
using namespace std;
void dfs(int node,vector<int> adj[],int vis[],vector<int> &ans) {
    vis[node]=1;
    ans.push_back(node);
    for (auto it:adj[node]) {
        if (!vis[it]) {
            dfs(it,adj,vis,ans);
        }
    }
}
vector<int> dfsOfGraph(int V,vector<int> adj[]) {
    int vis[V]={0};
    int start=0;
    vector<int> ans;
    dfs(start,adj,vis,ans);
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
    vector<int> ans=dfsOfGraph(6,adj);
    for (auto it:ans) {
        cout<<it<<" ";
    }
    return 0;
}
