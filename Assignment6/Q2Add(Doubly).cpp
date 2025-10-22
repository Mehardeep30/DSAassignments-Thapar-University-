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
node*delHead(node*head) {
    if (!head || !head->next) return nullptr;
    node*delNode=head;
    node*nextNode=head->next;
    nextNode->back=nullptr;
    delNode->next=nullptr;
    delete(delNode);
    return nextNode;
}
bool hasEvenParity(int x) {
    int cnt=0;
    while (x) {
        if (x%2) cnt++;
        x=x/2;
    }
    return (cnt%2==0);
}
void display(node* head) {
    node* temp = head;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
node*evenParityRemoval(node*head) {
    if (!head) return nullptr;
    while(head && hasEvenParity(head->data)) head=delHead(head);
    node*temp=head;
    node*nextNode;
    while (temp) {
        if (hasEvenParity(temp->data)) {
            node*prevNode=temp->back;
            nextNode=temp->next;
            temp->back=temp->next=nullptr;
            delete(temp);
            prevNode->next=nextNode;
            temp=nextNode;
        }
        else temp=temp->next;
    }
    return head;
}
int main() {
    node* head = new node(18);
    node* n2 = new node(15);
    node* n3 = new node(8);
    node* n4 = new node(9);
    node* n5 = new node(14);

    head->next = n2;
    n2->back = head;

    n2->next = n3;
    n3->back = n2;

    n3->next = n4;
    n4->back = n3;

    n4->next = n5;
    n5->back = n4;
    head=evenParityRemoval(head);
    display(head);
    return 0;
}
