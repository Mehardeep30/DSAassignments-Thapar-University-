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
int middleOfLL(node*head) {
    if (!head) return -1;
    node*slow=head;
    node*fast=head;
    while (fast && fast->next) {
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow->data;
}
int main() {
    node*head=new node(1);
    head->next=new node(2);
    head->next->next=new node(3);
    head->next->next->next=new node(4);
    head->next->next->next->next=new node(5);
    cout<<middleOfLL(head);
    return 0;
}
