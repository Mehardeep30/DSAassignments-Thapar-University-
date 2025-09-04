#include <bits/stdc++.h>
using namespace std;
bool canBeSorted(vector<int> &arr,int n) {
    stack<int> st;
    vector<int> b;
    int prev=INT_MIN;
    for (int i=0;i<n;i++) {
        while (!st.empty() && st.top()<arr[i]) {
            if (st.top()<prev) return false;
            b.push_back(st.top());
            prev=st.top();
            st.pop();
        }
        st.push(arr[i]);
    }
    while (!st.empty()) {
        if (prev>st.top()) return false;
        b.push_back(st.top());
        st.pop();
    }
    return true;
}
int main() {
    vector<int> arr={1,3,4,5,6,2};
    cout<<canBeSorted(arr,arr.size());
    return 0;
}
