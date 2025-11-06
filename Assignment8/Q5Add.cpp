#include <bits/stdc++.h>
using namespace std;
class node {
public:
    int data;
    node*left;
    node*right;
    node(int data) {
        this->data=data;
        left=right=nullptr;
    }
};
void inorder(node*root) {
    if (!root) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
node*buildTree(vector<int> &preorder,int preStart,int preEnd,vector<int> &inorder,int inStart,int inEnd,map<int,int> &inMap) {
    if (preStart>preEnd || inStart>inEnd) return nullptr;
    node*root=new node(preorder[preStart]);
    int inRoot=inMap[root->data];
    int numsLeft=inRoot-inStart;
    root->left=buildTree(preorder,preStart+1,preStart+numsLeft,inorder,inStart,inRoot-1,inMap);
    root->right=buildTree(preorder,preStart+numsLeft+1,preEnd,inorder,inRoot+1,inEnd,inMap);
    return root;
}
node*build(vector<int> &preorder,vector<int> &inorder) {
    map<int,int> inMap;
    for (int i=0;i<inorder.size();i++) {
        inMap[inorder[i]]=i;
    }
    return buildTree(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,inMap);
}
int main() {
    vector<int> preorder = {8, 3, 1, 6, 4, 7, 10, 14, 13};
    vector<int> Inorder = {1, 3, 4, 6, 7, 8, 10, 13, 14};
    inorder(build(preorder,Inorder));
    return 0;
}
