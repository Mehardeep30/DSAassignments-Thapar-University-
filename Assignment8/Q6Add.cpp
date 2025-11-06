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
node*buildTree(vector<int> &postorder,int postStart,int postEnd,vector<int> &inorder,int inStart,int inEnd,map<int,int> &inMap) {
    if (postStart>postEnd || inStart>inEnd) return nullptr;
    node*root=new node(postorder[postEnd]);
    int inRoot=inMap[root->data];
    int numsLeft=inRoot-inStart;
    root->left=buildTree(postorder,postStart,postStart+numsLeft-1,inorder,inStart,inRoot-1,inMap);
    root->right=buildTree(postorder,postStart+numsLeft,postEnd-1,inorder,inRoot+1,inEnd,inMap);
    return root;
}
node*build(vector<int> &postorder,vector<int> &inorder) {
    map<int,int> inMap;
    for (int i=0;i<inorder.size();i++) {
        inMap[inorder[i]]=i;
    }
    return buildTree(postorder,0,postorder.size()-1,inorder,0,inorder.size()-1,inMap);
}
int main() {
    vector<int> Inorder = {1, 3, 4, 6, 7, 8, 10, 13, 14};
    vector<int> postorder = {1, 4, 7, 6, 3, 13, 14, 10, 8};
    inorder(build(postorder,Inorder));
    return 0;
}
