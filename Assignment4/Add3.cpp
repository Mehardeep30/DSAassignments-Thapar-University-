#include <bits/stdc++.h>
using namespace std;
bool canBeSorted(queue<int> &q) {
    stack<int> st;
    queue<int> q2;
    int prev=INT_MIN;
    while (!q.empty()) {
        int curr=q.front();
        q.pop();
        while (!st.empty() && st.top()<curr) {
            if (prev>st.top()) return false;
            prev=st.top();
            q2.push(st.top());
            st.pop();
        }
        st.push(curr);
    }
    while (!st.empty()) {
        if (prev>st.top()) return false;
        q.push(st.top());
        st.pop();
    }
    return true;
}
int main() {
    queue<int> q;
    q.push(5);
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    cout<<canBeSorted(q);
    return 0;
}
