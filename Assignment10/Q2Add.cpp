#include<bits/stdc++.h>
using namespace std;
int shortestPath(int n,int m,vector<vector<int>> &mat) {
    vector<vector<int>> dist(n,vector<int>(m));
    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++){
            dist[i][j]=INT_MAX;
        }
    }
    int dr[4]={-1,0,1,0};
    int dc[4]={0,1,0,-1};
    dist[0][0]=mat[0][0];
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
    pq.push({dist[0][0],{0,0}});
    while (!pq.empty()) {
        auto top=pq.top(); pq.pop();
        int wt=top.first;
        int r=top.second.first;
        int c=top.second.second;
        for (int i=0;i<4;i++) {
            int newR=r+dr[i];
            int newC=c+dc[i];
            if (newR>=0 && newR<n && newC>=0 && newC<m) {
                int edw=mat[newR][newC];
                if (wt+edw<dist[newR][newC]) {
                    dist[newR][newC]=edw+wt;
                    pq.push({dist[newR][newC],{newR,newC}});
                }
            }
        }
    }
    return dist[n-1][m-1];
}
int main() {
    vector<vector<int>> grid = {
        {1,2,3},{4,5,6},{7,8,9}
    };
    cout<<shortestPath(3,3,grid);
    return 0;
}
