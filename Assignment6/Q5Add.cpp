#include <bits/stdc++.h>
using namespace std;
class node {
public:
    int data;
    node*next;
    node*back;
    node*up;
    node*down;
    node(int data,node*next,node*back,node*up,node*down) {
        this->data=data;
        this->next=next;
        this->back=back;
        this->up=up;
        this->down=down;
    }
    node(int data) {
        this->data=data;
        next=back=up=down=nullptr;
    }
};
node*MatrixDLL(vector<vector<int>> &mat,int n,int m) {
    if (n==0 && m==0) return nullptr;
    vector<vector<node*>> grid(n,vector<node*>(m,nullptr));
    for (int r=0;r<n;r++) {
        for (int c=0;c<m;c++) {
            grid[r][c]=new node(mat[r][c]);
        }
    }
    int delRow[4]={-1,0,1,0};
    int delCol[4]={0,1,0,-1};
    for (int r=0;r<n;r++) {
        for (int c=0;c<m;c++) {
            for (int i=0;i<4;i++) {
                int newR=r+delRow[i];
                int newC=c+delCol[i];
                if (newR>=0 && newR<n && newC>=0 && newC<m) {
                    if (i==0) grid[r][c]->up=grid[newR][newC];
                    if (i==1) grid[r][c]->next=grid[newR][newC];
                    if (i==2) grid[r][c]->down=grid[newR][newC];
                    if (i==3) grid[r][c]->back=grid[newR][newC];
                }
            }
        }
    }
    return grid[0][0];
}
int main() {
    return 0;
}
