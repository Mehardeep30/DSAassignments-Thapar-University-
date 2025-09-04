#include <bits/stdc++.h>
using namespace std;
class stUSINGq {
    queue<int> q;
    queue<int> temp;
public:
    void push(int x) {
        while (!q.empty()) {
            temp.push(q.front()); q.pop();
        }
        q.push(x);
        while (!temp.empty()) {
            q.push(temp.front()); temp.pop();
        }
    }
    void pop() {
        q.pop();
    }
    int size() {
        return q.size();
    }
    int top() {
        return q.front();
    }
};
int main() {
    stUSINGq st;
    st.push(10);
    st.push(20);
    cout<<st.top();
    return 0;
}
