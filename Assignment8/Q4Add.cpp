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
void RightSideViewHelper(node*root,int level,map<int,int> &mpp) {
    if (!root) return;
    if (level==mpp.size()) {
        mpp[level]=root->data;
    }
    RightSideViewHelper(root->right,level+1,mpp);
    RightSideViewHelper(root->left,level+1,mpp);
}
vector<int> RighSideView(node*root) {
    map<int,int> mpp;
    vector<int> ans;
    RightSideViewHelper(root,0,mpp);
    for (auto i:mpp) {
        ans.push_back(i.second);
    }
    return ans;
}
int main() {
    node* root = new node(8);
    root->left = new node(3);
    root->right = new node(10);
    root->left->left = new node(1);
    root->left->right = new node(6);
    root->right->right = new node(14);
    root->left->right->left = new node(4);
    root->left->right->right = new node(7);
    vector<int> ans=RighSideView(root);
    for (auto i:ans) {
        cout<<i<<" ";
    }
    return 0;
}
