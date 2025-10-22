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
int sizeCircular(node*head) {
    if (!head) return 0;
    int cnt=0;
    node*temp=head;
    do {
        cnt++;
        temp=temp->next;
    }while (temp!=head);
    return cnt;
}
int main() {
    node* head = new node(10);
    node* second = new node(20);
    node* third = new node(30);
    node* fourth = new node(40);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = head;
    cout<<sizeCircular(head);
    return 0;
}
