#include <bits/stdc++.h>
using namespace std;
class stUSINGq {
    queue<int> q;
public:
    void push(int x) {
        int n=q.size();
        q.push(x);
        while (n--) {
            q.push(q.front());
            q.pop();
        }
    }
    int top() {
        return q.front();
    }
    int size() {
        return q.size();
    }
    void pop(){
        q.pop();
    }
};
int main() {
    stUSINGq st;
    st.push(10);
    st.push(20);
    cout<<st.top();
    return 0;
}
