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
node*removeLoop(node*head) {
    if (!head || !head->next) return nullptr;
    node*slow=head;
    node*fast=head;
    node*prev=nullptr;
    while (fast && fast->next) {
        slow=slow->next;
        fast=fast->next->next;
        if (slow==fast) {
            slow=head;
            while (slow!=fast) {
                slow=slow->next;
                prev=fast;
                fast=fast->next;
            }
            prev->next=nullptr;
        }
    }
    return head;
}
int main() {
    node* head = new node(1);
    head->next = new node(2);
    head->next->next = new node(3);
    head->next->next->next = new node(4);
    head->next->next->next->next = new node(5);
    head->next->next->next->next->next = new node(6);
    head->next->next->next->next->next->next = head->next->next;
    head=removeLoop(head);
    display(head);
    return 0;
}
