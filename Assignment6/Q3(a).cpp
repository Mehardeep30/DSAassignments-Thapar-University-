#include <bits/stdc++.h>
using namespace std;
class node {
public:
    int data;
    node*next;
    node*back;
    node(int data,node*next,node*back) {
        this->data=data;
        this->next=next;
        this->back=back;
    }
    node(int data) {
        this->data=data;
        next=back=nullptr;
    }
};
int sizeDoubly(node*head) {
    int cnt=0;
    node*temp=head;
    while (temp) {
        temp=temp->next;
        cnt++;
    }
    return cnt;
}
int main() {
    node* head = new node(10);
    node* second = new node(20);
    node* third = new node(30);
    node* fourth = new node(40);

    // Linking nodes
    head->next = second;
    second->back = head;

    second->next = third;
    third->back = second;

    third->next = fourth;
    fourth->back = third;
    cout<<sizeDoubly(head);
    return 0;
}
