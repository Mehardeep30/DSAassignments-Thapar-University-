#include <iostream>
using namespace std;
class qIMParr {
    int q[10];
    int size=10;
    int start=-1;
    int end=-1;
    int curr_size=0;
public:
    void push(int x) {
        if (curr_size==size) {
            cout<<"The element cannot be inserted!"<<endl;
        }
        else {
            if (!curr_size) {
                start++;
                end++;
                q[end]=x;
            }
            else {
                end=(end+1)%size;
                q[end]=x;
            }
            curr_size++;
        }
    }
    void pop() {
        if (curr_size==0) {
            cout<<"The queue is empty!"<<endl;
        }
        else {
            if (curr_size==1) {
                start=-1;
                end=-1;
            }
            else {
                start=(start+1)%size;
            }
            curr_size--;
        }
    }
    int top() {
        if (curr_size==0) {
            cout<<"The queue is empty!"<<endl;
        }
        else {
            return q[start];
        }
    }
    int sizeq() {
        return curr_size;
    }
    int peek() {
        return q[start];
    }
    bool isEmpty() {
        return !curr_size;
    }
};
int main() {
    qIMParr q;
    q.push(10);
    cout<<q.top()<<endl;
    q.push(20);
    q.pop();
    cout<<q.top()<<endl;
    cout<<q.peek();
    return 0;
}
