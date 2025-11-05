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
void pushLeft(node*root,stack<node*>&st) {
    while (root) {
        st.push(root);
        root=root->left;
    }
}
node*mergeBSTs(node*root1,node*root2) {
    stack<node*> st1,st2;
    pushLeft(root1,st1);
    pushLeft(root2,st2);
    node*head=nullptr;
    node*tail=nullptr;
    while (!st1.empty() || !st2.empty()) {
        node*topNode=nullptr;
        if (st2.empty() || (!st1.empty() && st1.top()<=st2.top())) {
            topNode=st1.top();
            st1.pop();
            pushLeft(topNode->right,st1);
        }
        else {
            topNode=st2.top();
            st2.pop();
            pushLeft(topNode->right,st2);
        }
        topNode->left=tail;
        if (tail) {
            tail->right=topNode;
        }
        else {
            head=tail=topNode;
        }
        tail=topNode;
    }
    if (tail) tail->right=nullptr;
    return head;
}
void print(node*root) {
    while (root) {
        cout<<root->data<<" ";
        root=root->right;
    }
}
int main() {
    node* T1 = new node(20);
    T1->left = new node(10);
    T1->right = new node(30);
    T1->right->left = new node(25);

    node* T2 = new node(15);
    T2->left = new node(5);
    T2->right = new node(40);
    T2->right->left = new node(35);

    node*root=mergeBSTs(T1,T2);
    print(root);
    return 0;
}
