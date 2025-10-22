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
bool checkCircular(node*head) {
    if (!head) return false;
    node*temp=head;
    do {
        temp=temp->next;
    }while (temp && temp!=head);
    if (!temp) return false;
    return true;
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
    fourth->next = nullptr;
    cout<<checkCircular(head);
    return 0;
}
