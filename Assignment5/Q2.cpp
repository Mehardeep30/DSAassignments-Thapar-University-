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
        cout<<temp->data;
        temp=temp->next;
    }
}
pair<node*,int>CountAndDelete(node*head,int val) {
    if (!head) return {nullptr,0};
    int cnt=0;
    while (head && head->data==val) {
        cnt++;
        node*nxt=head->next;
        delete(head);
        head=nxt;
    }
    node*prev=nullptr;
    node*temp=head;
    while (temp) {
        if (temp->data==val) {
            cnt++;
            node*nxt=temp->next;
            prev->next=nxt;
            delete(temp);
            temp=nxt;
        }
        else {
            prev=temp;
            temp=temp->next;
        }
    }
    return {head,cnt};
}
int main() {
    node*head=new node(2);
    head->next=new node(1);
    head->next->next=new node(2);
    head->next->next->next=new node(1);
    head->next->next->next->next=new node(1);
    head->next->next->next->next->next=new node(2);
    pair<node*,int> x=CountAndDelete(head,1);
    head=x.first;
    display(head);
    cout<<endl;
    cout<<x.second;
    return 0;
}
