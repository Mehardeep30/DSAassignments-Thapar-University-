#include<bits/stdc++.h>
using namespace std;
void dfs(int r,int c,int n,int m,vector<vector<int>> &mat,vector<vector<int>> &vis,int dr[],int dc[]) {
    vis[r][c]=1;
    for (int i=0;i<4;i++) {
        int newR=r+dr[i];
        int newC=c+dc[i];
        if (newR>=0 && newR<n && newC>=0 && newC<m && mat[newR][newC]) {
            if (!vis[newR][newC])dfs(newR,newC,n,m,mat,vis,dr,dc);
        }
    }
}
int numberOfIslands(int n,int m,vector<vector<int>> &mat) {
    vector<vector<int>> vis(n,vector<int>(m));
    int cnt=0;
    int dr[4]={-1,0,1,0};
    int dc[4]={0,1,0,-1};
    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
            if (!vis[i][j] && mat[i][j]) {
                dfs(i,j,n,m,mat,vis,dr,dc);
                cnt++;
            }
        }
    }
    return cnt;
}
int main() {
    vector<vector<int>> grid = {
        {1, 1, 0, 0, 0},
        {1, 0, 0, 1, 1},
        {0, 0, 1, 0, 0},
        {1, 1, 0, 0, 1},
        {0, 0, 0, 1, 1}
    };
    cout<<numberOfIslands(5,5,grid);
    return 0;
}
