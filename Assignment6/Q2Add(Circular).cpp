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
void display(node* head) {
    if (!head) return;
    node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}
bool hasEvenParity(int x) {
    int cnt=0;
    while (x) {
        if (x%2) cnt++;
        x=x/2;
    }
    return (cnt%2==0);
}
node*deleteHead(node*head) {
    if (!head || head->next==head) {
        return nullptr;
    }
    node*nextNode=head->next;
    node*temp=head;
    while (temp->next!=head) {
        temp=temp->next;
    }
    delete(head);
    temp->next=nextNode;
    head=nextNode;
    return head;
}
node*removeEvenParity(node*head) {
    if (!head) return nullptr;
    while (head && hasEvenParity(head->data)) {
        head=deleteHead(head);
    }
    node*temp=head;
    do {
        if (hasEvenParity(temp->next->data)) {
            node*delNode=temp->next;
            node*nextNode=delNode->next;
            delNode->next=nullptr;
            delete(delNode);
            temp->next=nextNode;
        }
        else temp=temp->next;
    }while (temp!=head);
    return head;
}
int main() {
    node* head = new node(9);
    node* n2 = new node(11);
    node* n3 = new node(34);
    node* n4 = new node(6);
    node* n5 = new node(13);
    node* n6 = new node(21);

    head->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n6;
    n6->next = head;
    head=removeEvenParity(head);
    display(head);
    return 0;
}
