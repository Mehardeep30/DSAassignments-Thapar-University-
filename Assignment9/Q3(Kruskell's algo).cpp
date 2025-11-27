#include <bits/stdc++.h>
using namespace std;
class DisjointSet {
    vector<int> parent,rank,size;
public:
    DisjointSet(int n) {
        parent.resize(n+1);
        rank.resize(n+1,0);
        size.resize(n+1,1);
        for (int i=0;i<=n;i++) {
            parent[i]=i;
        }
    }
    int findUParent(int node) {
        if (parent[node]==node) return node;
        return parent[node]=findUParent(parent[node]);
    }
    void unionByRank(int u,int v) {
        int ulp_u=findUParent(u);
        int ulp_v=findUParent(v);
        if (ulp_u==ulp_v) return;
        if (rank[ulp_u]>rank[ulp_v]) {
            parent[ulp_v]=ulp_u;
        }
        else if (rank[ulp_v]<rank[ulp_u]) {
            parent[ulp_v]=ulp_u;
        }
        else {
            parent[ulp_v]=ulp_u;
            rank[ulp_u]++;
        }
    }
    void unionBySize(int u,int v) {
        int ulp_u=findUParent(u);
        int ulp_v=findUParent(v);
        if (ulp_u==ulp_v) return;
        if (size[ulp_u]<size[ulp_v]) {
            parent[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
        }
        else {
            parent[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];
        }
    }
};
int Spanning(int V,vector<vector<int>> adj[]) {
    vector<pair<int,pair<int,int>>> edges;
    for (int i=0;i<V;i++) {
        for (auto it:adj[i]) {
            int node=i;
            int adjNode=it[0];
            int wt=it[1];
            edges.push_back({wt,{node,adjNode}});
        }
    }
    sort(edges.begin(),edges.end());
    DisjointSet ds(V);
    int sum=0;
    for (auto it:edges) {
        int wt=it.first;
        int u=it.second.first;
        int v=it.second.second;
        if (ds.findUParent(u)!=ds.findUParent(v)) {
            ds.unionBySize(u,v);
            sum+=wt;
        }
    }
    return sum;
}
int main() {
    vector<vector<int>> adj[6];

    adj[1] = {{2, 3}, {3, 1}};
    adj[2] = {{1, 3}, {3, 7}, {4, 5}};
    adj[3] = {{1, 1}, {2, 7}, {5, 2}};
    adj[4] = {{2, 5}, {5, 7}};
    adj[5] = {{3, 2}, {4, 7}};
    cout<<Spanning(6,adj);
    return 0;
}
