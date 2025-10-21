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
node*rotateByKPlaces(node*head,int k) {
    if (!head || !head->next) return head;
    int len=0;
    node*temp=head;
    while (temp->next) {
        temp=temp->next;
        len++;
    }
    len++;
    k=k%len;
    temp->next=head;
    temp=head;
    for (int i=0;i<k-1;i++) {
        temp=temp->next;
    }
    head=temp->next;
    temp->next=nullptr;
    return head;
}
int main() {
    node* head = new node(1);
    head->next = new node(2);
    head->next->next = new node(3);
    head->next->next->next = new node(4);
    head->next->next->next->next = new node(5);
    head->next->next->next->next->next = new node(6);
    head=rotateByKPlaces(head,8);
    display(head);
    return 0;
}
