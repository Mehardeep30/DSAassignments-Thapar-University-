#include <bits/stdc++.h>
using namespace std;
struct node {
public:
    int coeff;
    int pow;
    node*next;
    node(int coeff,int pow) {
        this->coeff=coeff;
        this->pow=pow;
        next=nullptr;
    }
};
node* addPolynomials(node*head1,node*head2) {
    node*result=nullptr;
    node*tail=nullptr;

    while (head1 && head2) {
        node*temp=nullptr;
        if (head1->pow>head2->pow) {
            temp=new node(head1->coeff,head1->pow);
            head1=head1->next;
        }
        else if (head1->pow<head2->pow) {
            temp=new node(head2->coeff,head2->pow);
            head2=head2->next;
        }
        else {
            int sumCoeff=head1->coeff+head2->coeff;
            if (sumCoeff) temp=new node(sumCoeff,head1->pow);
            head1=head1->next;
            head2=head2->next;
        }
        if (temp) {
            if (!result) {
                result=tail=temp;
            }
            else {
                tail->next=temp;
                tail=tail->next;
            }
        }
    }
    while (head1) {
        node*temp=new node(head1->coeff,head1->pow);
        if (!result) {
            result=tail=temp;
        }
        else {
            tail->next=temp;
            tail=tail->next;
            head1=head1->next;
        }
    }
    while (head2) {
        node*temp=new node(head2->coeff,head2->pow);
        if (!result) {
            result=tail=temp;
        }
        else {
            tail->next=temp;
            tail=tail->next;
            head2=head2->next;
        }
    }
    return result;
}
void printPoly(node* head) {
    while (head) {
        cout << "[" << head->coeff << ", " << head->pow << "]";
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}
int main(){
    // Polynomial 1: 5x^3 + 4x^2 + 2
    node* head1 = new node(5, 3);
    head1->next = new node(4, 2);
    head1->next->next = new node(2, 0);

    // Polynomial 2: 3x^2 + 5x + 1
    node* head2 = new node(3, 2);
    head2->next = new node(5, 1);
    head2->next->next = new node(1, 0);

    cout << "Polynomial 1: ";
    printPoly(head1);
    cout << "Polynomial 2: ";
    printPoly(head2);

    node* sum = addPolynomials(head1, head2);
    cout << "Sum: ";
    printPoly(sum);
    return 0;
}
