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
int maxDepth(node*root) {
    if (!root) return 0;
    int lh=maxDepth(root->left);
    int rh=maxDepth(root->right);
    return 1+max(lh,rh);
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
    root->right->right->left = new node(13);
    cout<<maxDepth(root);
    return 0;
}
