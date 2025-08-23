#include <iostream>
using namespace std;
class stIMP {
    int st[10];
    int curr=-1;
public:
    int top() {
        if (curr==-1) cout<<"There are no elements in the stack!";
        else {
            return st[curr];
        }
    }
    void push(int x) {
        curr++;
        if (curr==10) {
            curr--;
            cout<<"The stack is full!";
        }
        else {
            st[curr]=x;
        }
    }
    void pop() {
        if (curr==-1) cout<<"There is no element in the stack to pop!";
        else curr--;
    }
    int size() {
        return curr+1;
    }
};
int main() {
    stIMP st;
    st.push(10);
    st.push(20);
    cout<<st.top();
    st.pop();
    cout<<st.top();
    return 0;
}