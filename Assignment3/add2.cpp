class minStack {
    int mini=INT_MIN;
    stack<int> st;
public:
    void push(int x) {
        if (!st.size()) {
            st.push(x);
            mini=x;
        }
        else {
            if (x<mini) {
                st.push(2*x-mini);
                mini=x;
            }
            else {
                st.push(x);
            }
        }
    }
    void pop() {
        if (!st.empty() && st.top()<mini) {
            mini=2*mini-st.top();
            st.pop();
        }
        else {
            st.pop();
        }
    }
    int top() {
        if (st.top()<mini) {
            return mini;
        }
        else return st.top();
    }
    int Pmini() {
        return mini;
    }
    int size() {
        cout<<st.size();
    }
};
