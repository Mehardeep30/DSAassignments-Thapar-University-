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
    if (!head)return;
    node*temp=head;
    do{
        cout<<temp->data<<" ";
        temp=temp->next;
    }while (temp!=head);
    cout<<endl;
}
node*insertFirstCLL(node*head,int val) {
    if (!head) {
        head=new node(val);
        head->next=head;
        return head;
    }
    node*temp=head;
    while (temp->next!=head) {
        temp=temp->next;
    }
    node*newNode=new node(val);
    temp->next=newNode;
    newNode->next=head;
    head=newNode;
    return head;
}
node*insertLastCLL(node*head,int val) {
    if (!head) {
        head=new node(val);
        head->next=head;
        return head;
    }
    node*temp=head;
    while (temp->next!=head) {
        temp=temp->next;
    }
    node*newNode=new node(val);
    temp->next=newNode;
    newNode->next=head;
    return head;
}
node*afterNode(node*head,int x,int val) {
    if (!head) return nullptr;
    if (head->data==x) {
        node*newNode=new node(val);
        node*nextNode=head->next;
        head->next=newNode;
        newNode->next=nextNode;
        return head;
    }
    node*temp=head->next;
    while (temp!=head && temp->data!=x) {
        temp=temp->next;
    }
    if (temp!=head) {
        node*newNode=new node(val);
        node*nextNode=temp->next;
        temp->next=newNode;
        newNode->next=nextNode;
    }
    return head;
}
node*beforeNode(node*head,int x,int val) {
    if (!head) return nullptr;
    if (head->data==x) {
        node*temp=head;
        while (temp->next!=head) {
            temp=temp->next;
        }
        node*newNode=new node(val);
        temp->next=newNode;
        newNode->next=head;
        head=newNode;
        return head;
    }
    node*temp=head;
    do {
        if (temp->next->data==x) {
            node*newNode=new node(val);
            node*nextNode=temp->next;
            temp->next=newNode;
            newNode->next=nextNode;
            return head;
        }
        temp=temp->next;
    }while (temp!=head);
    return head;
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
node*deleteLastNode(node*head) {
    if (!head || head->next==head) return nullptr;
    node*temp=head;
    while (temp->next->next!=head) {
        temp=temp->next;
    }
    node*nextNode=temp->next->next;
    node*delNode=temp->next;
    delete(delNode);
    temp->next=nextNode;
    return head;
}
node*deleteSpecific(node*head,int x) {
    if (!head) return nullptr;
    if (head->data==x) return deleteHead(head);
    node*temp=head;
    do {
        if (temp->next->data==x) {
            node*nextNode=temp->next->next;
            node*delNode=temp->next;
            delete(delNode);
            temp->next=nextNode;
            break;
        }
        temp=temp->next;
    }while (temp!=head);
    return head;
}
bool searchForNode(node*head,int x) {
    if (!head) return false;
    node*temp=head;
    do {
        if (temp->data==x) return true;
        temp=temp->next;
    }while (temp!=head);
    return false;
}
int main() {
    node* head = nullptr;
    int choice, val, x;

    do {
        cout << "\n--- Circular Linked List Menu ---\n";
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
                head = insertFirstCLL(head, val);
                break;
            case 2:
                cout << "Enter value to insert at end: ";
                cin >> val;
                head = insertLastCLL(head, val);
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
                head = deleteHead(head);
                break;
            case 6:
                head = deleteLastNode(head);
                break;
            case 7:
                cout << "Enter value to delete: ";
                cin >> x;
                head = deleteSpecific(head, x);
                break;
            case 8:
                cout << "Enter value to search: ";
                cin >> x;
                if (searchForNode(head, x))
                    cout << x << " found in the list.\n";
                else
                    cout << x << " not found in the list.\n";
                break;
            case 9:
                display(head);
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
