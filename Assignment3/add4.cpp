#include <bits/stdc++.h>
using namespace std;
vector<int> waiting(vector<int> &temp,int n) {
    vector<int> ans(n);
    stack<int> st;
    for (int i=n-1;i>=0;i--) {
        while (!st.empty() && temp[st.top()]<temp[i]) {
            st.pop();
        }
        ans[i]=st.empty() ? -1:st.top()-i;
        st.push(i);
    }
    return ans;
}
int main() {
    vector<int> arr={73,74,75,71,69,72,76,73};
    vector<int> ans=waiting(arr,arr.size());
    for (auto i:ans) {
        cout<<i<<" ";
    }
    return 0;
}
