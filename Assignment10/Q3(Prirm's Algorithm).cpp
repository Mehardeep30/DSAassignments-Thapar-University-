#include <bits/stdc++.h>
using namespace std;
int spanningTree(int V,vector<vector<int>> adj[]) {
    vector<int> vis(V,0);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,0}); //{edw,node}
    int sum=0;
    while (!pq.empty()) {
        auto front=pq.top(); pq.pop();
        int node=front.second;
        int wt=front.first;
        if (vis[node]) continue;
        vis[node]=1;
        sum+=wt;
        for (auto it:adj[node]) {
            int adjNode=it[0];
            int wt=it[1];
            if (!vis[adjNode]) {
                pq.push({wt,adjNode});
            }
        }
    }
    return sum;
}
int main() {
    vector<vector<int>> adj[6] = {
        { {1, 4}, {2, 2} },        // 0
        { {0, 4}, {2, 1}, {3, 5} },// 1
        { {0, 2}, {1, 1}, {3, 8}, {4, 10} }, // 2
        { {1, 5}, {2, 8}, {4, 2}, {5, 6} },  // 3
        { {2, 10}, {3, 2}, {5, 3} },         // 4
        { {3, 6}, {4, 3} }                   // 5
    };
    cout<<spanningTree(6,adj);
    return 0;
}
