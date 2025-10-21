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
node*insertAtBeginning(node*head,int val) {
    if (!head) return new node(val);
    node*temp=new node(val);
    temp->next=head;
    head=temp;
    return head;
}
node*insertAtEnd(node*head,int val) {
    if (!head) return new node(val);
    node*temp=head;
    while (temp->next) {
        temp=temp->next;
    }
    temp->next=new node(val);
    return head;
}
node*insertAfter(node*head,int x,int val) {
    if (!head) return nullptr;
    node*temp=head;
    while (temp && temp->data!=x) {
        temp=temp->next;
    }
    if (!temp) return head;
    node*nxt=temp->next;
    node*newNode=new node(val);
    temp->next=newNode;
    newNode->next=nxt;
    return head;
}
node*insertBefore(node*head,int x,int val) {
    if (!head) return nullptr;
    if (head->data==x) return insertAtBeginning(head,val);
    node*temp=head;
    node*prev=nullptr;
    while (temp && temp->data!=x) {
        prev=temp;
        temp=temp->next;
    }
    if (!temp) return head;
    node*newNode=new node(val);
    prev->next=newNode;
    newNode->next=temp;
    return head;
}
node*deleteFromBeginning(node*head) {
    if (!head) return nullptr;
    node*nxt=head->next;
    delete(head);
    head=nxt;
    return head;
}
node*deleteFromEnd(node*head) {
    if (!head) return nullptr;
    if (!head->next) {
        delete(head);
        return nullptr;
    }
    node*temp=head;
    while (temp->next->next) {
        temp=temp->next;
    }
    delete(temp->next);
    temp->next=nullptr;
    return head;
}
node*deleteNode(node*head,int val) {
    if (!head) return nullptr;
    node*temp=head;
    node*prev=nullptr;
    if (head->data==val) return deleteFromBeginning(head);
    while (temp && temp->data!=val) {
        prev=temp;
        temp=temp->next;
    }
    if (!temp) return head;
    node*nxt=temp->next;
    prev->next=nxt;
    delete(temp);
    return head;
}
int searchNode(node*head,int val) {
    int cnt=0;
    node*temp=head;
    while (temp) {
        cnt++;
        if (temp->data==val) return cnt;
        temp=temp->next;
    }
    return -1;
}
void menu() {

}
int main() {
    node*head=new node(1);
    head->next=new node(2);
    head->next->next=new node(3);
    head->next->next->next=new node(4);
    int choice,val,x;

    do {
        cout << "\n--- Singly Linked List Menu ---\n";
        cout << "1. Insert at beginning\n";
        cout << "2. Insert at end\n";
        cout << "3. Insert after a node\n";
        cout << "4. Insert before a node\n";
        cout << "5. Delete from beginning\n";
        cout << "6. Delete from end\n";
        cout << "7. Delete a specific node\n";
        cout << "8. Search for a node\n";
        cout << "9. Display list\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout<<"Enter value:";
                cin>>val;
                head=insertAtBeginning(head,val);
                break;
            case 2:
                cout<<"Enter value:";
                cin>>val;
                head=insertAtEnd(head,val);
                break;
            case 3:
                cout<<"Enter the node after which to insert";
                cin>>x;
                cout<<"Enter value:";
                cin>>val;
                head=insertAfter(head,x,val);
                break;
            case 4:
                cout<<"Enter the node before which to insert:";
                cin>>x;
                cout<<"Enter value:";
                cin>>val;
                head=insertBefore(head,x,val);
                break;
            case 5:
                head=deleteFromBeginning(head);
                break;
            case 6:
                head=deleteFromEnd(head);
                break;
            case 7:
                cout<<"enter the value to delete:";
                cin>>val;
                head=deleteNode(head,val);
                break;
            case 8:
                cout<<"Enter the value to search:";
                cin>>val;
                cout<<searchNode(head,val);
                break;
            case 9:
                display(head);
                break;
            case 0:
                cout<<"Exiting!";
                break;
            default:
                cout<<"Invalid!";
        }
    }while (choice!=0);
    return 0;
}
