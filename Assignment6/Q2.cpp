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
    if (!head) return;
    node*temp=head;
    do {
        cout<<temp->data<<" ";
        temp=temp->next;
    }while(temp!=head);
    cout<<head->data<<" ";
}
int main() {
    node* head = new node(10);
    node* second = new node(20);
    node* third = new node(30);
    node* fourth = new node(40);

    // Linking nodes
    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = head;
    display(head);
    return 0;
}
