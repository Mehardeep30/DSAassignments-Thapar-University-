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
node*findKthNode(node*head,int k) {
    node*temp=head;
    while (temp && --k) {
        temp=temp->next;
    }
    return temp;
}
node*reverse(node*head) {
    node*prev=nullptr;
    node*temp=head;
    while (temp) {
        node*nxtNode=temp->next;
        temp->next=prev;
        prev=temp;
        temp=nxtNode;
    }
    return prev;
}
node*reverseLLinK(node*head,int k) {
    node*temp=head;
    node*prevNode=nullptr;
    node*nextNode;
    while (temp) {
        node*kthNode=findKthNode(temp,k);
        if (!kthNode) {
            if (prevNode)prevNode->next=temp;
            break;
        }
        nextNode=kthNode->next;
        kthNode->next=nullptr;
        reverse(temp);
        if (temp==head) head=kthNode;
        else {
            prevNode->next=kthNode;
        }
        prevNode=temp;
        temp=nextNode;
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
    head->next->next->next->next->next->next = new node(7);
    head->next->next->next->next->next->next->next = new node(8);
    head->next->next->next->next->next->next->next->next = new node(9);
    head=reverseLLinK(head,3);
    display(head);
    return 0;
}
