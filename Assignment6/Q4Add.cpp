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
    head->back=nullptr;
    node*temp=head;
    while (temp) {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    return;
}
void correctPointer(node*head) {
    if (!head) return;
    node*temp=head;
    while (temp->next) {
        if (temp->next->back!=temp) temp->next->back=temp;
        temp=temp->next;
    }
}
int main() {
    node* n1 = new node(1);
    node* n2 = new node(2);
    node* n3 = new node(3);

    n1->next = n2;
    n2->next = n3;
    n3->next = nullptr;


    n1->back = nullptr;
    n2->back = n1;
    n3->back = n1;

    node* head = n1;
    correctPointer(head);
    display(head);
    return 0;
}
