#include <bits/stdc++.h>
using namespace std;
class node {
public:
    node*left;
    node*right;
    int data;
    node(int data) {
        this->data=data;
        left=right=nullptr;
    }
};
bool searchBST(node*root,int x) {
    if (!root) return false;
    if (root->data==x) return true;
    if (root->data<x) return searchBST(root->right,x);
    if (root->data>x) return searchBST(root->left,x);
}
int maxBST(node*root) {
    if (!root) return -1;
    while (root->right) {
        root=root->right;
    }
    return root->data;
}
int minBST(node*root) {
    if (!root) return -1;
    while (root->left) root=root->left;
    return root->data;
}
void inorderSuccessorHelper(node*root,int val,int &successor) {
    if (!root) return;
    else if (root->data>val) {
        successor=root->data;
        inorderSuccessorHelper(root->left,val,successor);
    }
    else inorderSuccessorHelper(root->right,val,successor);
}
int inorderSucessor(node*root,int val) {
    int sucessor=-1;
    inorderSuccessorHelper(root,val,sucessor);
    return sucessor;
}
void inorderPredecessorHelper(node*root,int val,int &predecessor) {
    if (!root) return;
    if (root->data<val) {
        predecessor=root->data;
        inorderPredecessorHelper(root->right,val,predecessor);
    }
    else {
        inorderPredecessorHelper(root->left,val,predecessor);
    }
}
int inorderPredecessor(node*root,int val) {
    int predecessor=-1;
    inorderPredecessorHelper(root,val,predecessor);
    return predecessor;
}
int main() {
    node* root = new node(10);
    root->left = new node(5);
    root->right = new node(15);

    root->left->left = new node(3);
    root->left->right = new node(7);

    root->right->left = new node(12);
    root->right->right = new node(18);
    cout<<searchBST(root,10)<<endl;
    cout<<maxBST(root)<<endl;
    cout<<minBST(root)<<endl;
    cout<<inorderSucessor(root,3)<<endl;
    cout<<inorderPredecessor(root,5)<<endl;
    return 0;
}
