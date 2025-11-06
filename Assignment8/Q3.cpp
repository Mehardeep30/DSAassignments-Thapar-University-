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
void inorder(node*root) {
    if (!root) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
node* insertElement(node*root,int el) {
    if (!root) return new node(el);
    node*curr=root;
    while (true) {
        if (curr->data>el) {
            if (curr->left) curr=curr->left;
            else {
                curr->left=new node(el);
                break;
            }
        }
        else {
            if (curr->right) curr=curr->right;
            else {
                curr->right=new node(el);
                break;
            }
        }
    }
    return root;
}
node*findLastRight(node*root) {
    if (!root->right) return root;
    return findLastRight(root->right);
}
node*helper(node*root) {
    if (!root->left) return root->right;
    else if (!root->right) return root->left;
    node*rightChild=root->right;
    node*lastRight=findLastRight(root->left);
    lastRight->right=rightChild;
    return root->left;
}
node*deleteNode(node*root,int key) {
    if (!root) return nullptr;
    if (root->data==key) return helper(root);
    node*dummy=root;
    while (root) {
        if (root->data>key) {
            if (root->left && root->left->data==key) {
                root->left=helper(root->left);
                break;
            }
            else {
                root=root->left;
            }
        }
        else {
            if (root->right && root->right->data==key) {
                root->right=helper(root->right);
                break;
            }
            else root=root->right;
        }
    }
    return dummy;
}
int maxDepth(node*root) {
    if (!root) return 0;
    int lh=maxDepth(root->left);
    int rh=maxDepth(root->right);
    return 1+max(lh,rh);
}
int minDepth(node*root) {
    if (!root) return 0;
    int lh=minDepth(root->left);
    int rh=minDepth(root->right);
    return 1+min(lh,rh);
}
int main() {
    node* root = new node(10);
    root->left = new node(5);
    root->right = new node(15);

    root->left->left = new node(3);
    root->left->right = new node(7);

    root->right->left = new node(12);
    root->right->right = new node(18);
    insertElement(root,100);
    inorder(root);
    cout<<endl;
    deleteNode(root,100);
    inorder(root);
    cout<<endl;
    cout<<maxDepth(root)<<endl;
    cout<<minDepth(root)<<endl;
    return 0;
}
