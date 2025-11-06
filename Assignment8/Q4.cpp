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
bool checkBSTHelper(node*root,int mini,int maxi) {
    if (!root) return true;
    if (root->data>=maxi && root->data<=mini) return false;
    return checkBSTHelper(root->left,mini,root->data) && checkBSTHelper(root->right,root->data,maxi);
}
bool checkBST(node*root) {
    return checkBSTHelper(root,INT_MIN,INT_MAX);
}
int main() {
    node* root = new node(10);
    root->left = new node(5);
    root->right = new node(15);

    root->left->left = new node(3);
    root->left->right = new node(7);

    root->right->left = new node(12);
    root->right->right = new node(18);
    cout<<checkBST(root);
    return 0;
}
