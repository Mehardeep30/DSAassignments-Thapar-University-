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
node*insertFirst(node*head,int val) {
    if (!head) return new node(val,nullptr,nullptr);
    node*newNode=new node(val,head,nullptr);
    head->back=newNode;
    head=newNode;
    return head;
}
node*insertLast(node*head,int val) {
    if (!head) return nullptr;
    node*temp=head;
    while (temp->next!=nullptr) {
        temp=temp->next;
    }
    node*newNode=new node(val,nullptr,temp);
    temp->next=newNode;
    return head;
}
node*afterNode(node*head,int x,int val) {
    if (!head) return nullptr;
    node*temp=head;
    while (temp && temp->data!=x) {
        temp=temp->next;
    }
    if (!temp) return head;
    node*nextNode=temp->next;
    node*newNode=new node(val,nextNode,temp);
    temp->next=newNode;
    if (nextNode)nextNode->back=newNode;
    return head;
}
node*beforeNode(node*head,int x,int val) {
    if (!head) return nullptr;
    node*temp=head;
    while (temp && temp->data!=x) {
        temp=temp->next;
    }
    if (!temp) return head;
    node*prevNode=temp->back;
    node*newNode=new node(val,temp,prevNode);
    if (prevNode) prevNode->next=newNode;
    temp->back=newNode;
    if (temp==head) return newNode;
    return head;
}
node*delHead(node*head) {
    if (!head || !head->next) return nullptr;
    node*delNode=head;
    node*nextNode=head->next;
    nextNode->back=nullptr;
    delNode->next=nullptr;
    delete(delNode);
    return nextNode;
}
node*delLast(node*head) {
    if (!head || !head->next) return nullptr;
    node*temp=head;
    while (temp->next) temp=temp->next;
    node*prevNode=temp->back;
    prevNode->next=nullptr;
    temp->back=nullptr;
    delete(temp);
    return head;
}
node*delNode(node*head,int x) {
    if (!head || !head->next) return nullptr;
    if (head->data==x) return delHead(head);
    node*temp=head;
    while (temp && temp->data!=x) {
        temp=temp->next;
    }
    if (!temp) return head;
    if (!temp->next) return delLast(head);
    node*prevNode=temp->back;
    node*nextNode=temp->next;
    prevNode->next=nextNode;
    nextNode->back=prevNode;
    temp->next=temp->back=nullptr;
    delete(temp);
    return head;
}
bool searchNode(node*head,int x) {
    if (!head) return false;
    node*temp=head;
    while (temp) {
        if (temp->data==x) return true;
        temp=temp->next;
    }
    return false;
}
int main() {
    node* head = nullptr;
    int choice, val, x;

    do {
        cout << "\n--- Doubly Linked List Menu ---\n";
        cout << "1. Insert at beginning\n";
        cout << "2. Insert at end\n";
        cout << "3. Insert after a node\n";
        cout << "4. Insert before a node\n";
        cout << "5. Delete head\n";
        cout << "6. Delete last node\n";
        cout << "7. Delete specific node\n";
        cout << "8. Search for a node\n";
        cout << "9. Display list\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert at beginning: ";
                cin >> val;
                head = insertFirst(head, val);
                break;
            case 2:
                cout << "Enter value to insert at end: ";
                cin >> val;
                head = insertLast(head, val);
                break;
            case 3:
                cout << "Enter node after which to insert: ";
                cin >> x;
                cout << "Enter value to insert: ";
                cin >> val;
                head = afterNode(head, x, val);
                break;
            case 4:
                cout << "Enter node before which to insert: ";
                cin >> x;
                cout << "Enter value to insert: ";
                cin >> val;
                head = beforeNode(head, x, val);
                break;
            case 5:
                head = delHead(head);
                break;
            case 6:
                head = delLast(head);
                break;
            case 7:
                cout << "Enter value to delete: ";
                cin >> x;
                head = delNode(head, x);
                break;
            case 8:
                cout << "Enter value to search: ";
                cin >> x;
                if (searchNode(head, x))
                    cout << x << " found in the list.\n";
                else
                    cout << x << " not found in the list.\n";
                break;
            case 9:
                display(head);
                cout << endl;
                break;
            case 0:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 0);

    return 0;
}
