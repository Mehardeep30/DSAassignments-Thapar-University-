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
void display(node*head) {
    if (!head) return;
    node*temp=head;
    while (temp) {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    return;
}
node*findKthNode(node*head,int k) {
    node*temp=head;
    while (temp && --k) temp=temp->next;
    return temp;
}
node*reverse(node*head) {
    node*temp=head;
    node*prev=nullptr;
    while (temp) {
        node*a=temp->next;
        temp->next=temp->back;
        temp->back=a;
        prev=temp;
        temp=a;
    }
    return prev;
}
node*reverseDLLinK(node*head,int k) {
    node*temp=head;
    node*prevNode=nullptr;
    node*nextNode;
    while (temp) {
        node*kthNode=findKthNode(temp,k);
        if (!kthNode) {
            if (prevNode) prevNode->next=temp;
            break;
        }
        node*nextNode=kthNode->next;
        if (nextNode)nextNode->back=nullptr;
        kthNode->next=nullptr;
        if (temp==head) head=kthNode;
        else {
            prevNode->next=kthNode;
            kthNode->back=prevNode;
        }
        reverse(temp);
        prevNode=temp;
        temp=nextNode;
    }
    return head;
}
int main() {
    node* head = new node(1);
    node* n2 = new node(2);
    node* n3 = new node(3);
    node* n4 = new node(4);
    node* n5 = new node(5);

    head->next = n2;
    n2->back = head;
    n2->next = n3;
    n3->back = n2;
    n3->next = n4;
    n4->back = n3;
    n4->next = n5;
    n5->back = n4;
    display(head);
    cout<<endl;
    head=reverseDLLinK(head,3);
    display(head);
    return 0;
}
