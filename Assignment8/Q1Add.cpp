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
int leftleaf(node*root) {
    int sum=0;
    if (!root) return sum;
    queue<node*> q;
    q.push(root);
    while (!q.empty()) {
        node*curr=q.front(); q.pop();
        if (curr->left) {
            if (curr->left->left==nullptr && curr->left->right==nullptr) {
                sum+=curr->left->data;
            }
            else q.push(curr->left);
        }
        if (curr->right) {
            q.push(curr->right);
        }
    }
    return sum;
}
int main() {
    node* root = new node(10);
    root->left = new node(5);
    root->right = new node(15);
    root->left->left = new node(2);
    root->left->right = new node(7);
    root->left->right->left = new node(6);
    root->right->right = new node(20);
    cout<<leftleaf(root);
    return 0;
}
