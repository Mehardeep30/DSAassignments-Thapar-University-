#include <bits/stdc++.h>
using namespace std;
class node {
public:
    char data;
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
bool palindrome(node*head) {
    if (!head) return false;
    node*last=head;
    while (last->next) last=last->next;
    node*first=head;
    while (first!=last && first->back!=last) {
        if (first->data==last->data) {
            first=first->next;
            last=last->back;
        }
        else return false;
    }
    return true;
}
int main() {
    node* head = new node('w');
    node* second = new node('x');
    node* third = new node('x');
    node* fourth = new node('w');

    head->next = second; second->back = head;
    second->next = third; third->back = second;
    third->next = fourth; fourth->back = third;
    cout<<palindrome(head);
    return 0;
}
