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
vector<node*> generate(int start,int end) {
    vector<node*> allTrees;
    if (start>end) {
        allTrees.push_back(nullptr);
    }
    for (int i=start;i<=end;i++) {
        vector<node*> leftTrees=generate(start,i-1);
        vector<node*> rightTrees=generate(i+1,end);
        for (auto left:leftTrees) {
            for (auto right:rightTrees) {
                node*root=new node(i);
                root->left=left;
                root->right=right;
                allTrees.push_back(root);
            }
        }
    }
    return allTrees;
}
void preorder(node* root) {
    if (!root) {
        cout << "null ";
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}
int main() {
    vector<node*> ans=generate(1,3);
    for (auto it:ans) {
        preorder(it);
        cout<<endl;
    }
    return 0;
}
