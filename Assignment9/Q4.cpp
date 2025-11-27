#include <bits/stdc++.h>
using namespace std;
vector<int> dijkstra(int V,vector<vector<int>> adj[],int s) {
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    vector<int> dist(V,INT_MAX);
    dist[s]=0;
    pq.push({0,s});
    while (!pq.empty()) {
        int dis=pq.top().first;
        int node=pq.top().second;
        pq.pop();
        for (auto it:adj[node]) {
            int adjNode=it[0];
            int wt=it[1];
            if (dis+wt<dist[adjNode]) {
                dist[adjNode]=wt+dis;
                pq.push({dist[adjNode],adjNode});
            }
        }
    }
    return dist;
}
int main() {
    vector<vector<int>> adj[7];

    adj[1] = {{2,4}, {3,1}};
    adj[2] = {{1,4}, {3,3}, {4,2}};
    adj[3] = {{1,1}, {2,3}, {5,7}};
    adj[4] = {{2,2}, {5,3}, {6,8}};
    adj[5] = {{3,7}, {4,3}, {6,4}};
    adj[6] = {{4,8}, {5,4}};

    vector<int> ans = dijkstra(7, adj, 1); // ✔ start from node 1

    for (int i = 1; i < 7; i++)
        cout << ans[i] << " ";

    return 0;
}
