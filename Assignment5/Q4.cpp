#include <bits/stdc++.h>
using namespace std;
class node {
public:
    int data;
    node*next;
    node(int data) {
        this->data=data;
        next=nullptr;
    }
};
void display(node*head) {
    node*temp=head;
    while (temp) {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
node*reverseLL(node*head) {
    if (!head || !head->next) return head;
    node*prev=nullptr;
    node*temp=head;
    while (temp) {
        node*nxt=temp->next;
        temp->next=prev;
        prev=temp;
        temp=nxt;
    }
    return prev;
}
int main() {
    node*head=new node(1);
    head->next=new node(2);
    head->next->next=new node(3);
    head->next->next->next=new node(4);
    head->next->next->next->next=new node(5);
    display(head);
    cout<<endl;
    head=reverseLL(head);
    display(head);
    return 0;
}
