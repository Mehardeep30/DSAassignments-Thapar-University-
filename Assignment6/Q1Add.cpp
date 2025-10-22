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
    }while (temp!=head);
}
pair<node*,node*> splitLL(node*head) {
    if (!head) return {nullptr,nullptr};
    if (head->next==head) return {head,nullptr};
    int cnt=1;
    int steps=-1;
    node*first=head;
    node*last=head;
    while (last->next!=head) {
        cnt++;
        last=last->next;
    }
    if (cnt%2==0) {
        steps=(cnt/2)-1;
    }
    else steps=cnt/2;
    node*temp=head;
    for (int i=0;i<steps;i++) {
        temp=temp->next;
    }
    node*newHead=temp->next;
    temp->next=first;
    last->next=newHead;
    return {first,newHead};
}
int main() {
    node* head = new node(1);
    node* second = new node(2);
    node* third = new node(3);
    node* fourth = new node(4);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = head; // circular

    // Split
    auto heads = splitLL(head);

    cout << "First half: ";
    display(heads.first);
    cout << endl;

    cout << "Second half: ";
    display(heads.second);
    cout << endl;

    return 0;
}
