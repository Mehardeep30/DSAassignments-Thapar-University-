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
int intersectionY(node*head1,node*head2) {
    if (!head1 || !head2) return -1;
    node*t1=head1;
    node*t2=head2;
    while (t1!=t2) {
        t1=t1->next;
        t2=t2->next;
        if (t1==t2) {
            if (!t1) return -1;
            return t1->data;
        }
        if (!t1) t1=head2;
        if (!t2) t2=head1;
    }
    return t1->data;
}
int main() {
    // Create common part
    node* common = new node(6);
    common->next = new node(7);
    common->next->next = new node(8);

    // List 1
    node* head1 = new node(1);
    head1->next = new node(2);
    head1->next->next = new node(3);
    head1->next->next->next = common; // attach intersection

    // List 2
    node* head2 = new node(4);
    head2->next = new node(5);
    head2->next->next = common; // attach intersection
    cout<<intersectionY(head1,head2);
    return 0;
}
