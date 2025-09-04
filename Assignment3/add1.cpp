#include <bits/stdc++.h>
using namespace std;
vector<int> NSE(vector<int> &arr,int n) {
    vector<int> ans(n);
    stack<int> st;
    for (int i=n-1;i>=0;i--) {
        while (!st.empty() && st.top()>arr[i]) st.pop();
        ans[i]=st.empty() ? -1:st.top();
        st.push(arr[i]);
    }
    return ans;
}
int main() {
    vector<int> arr={10,9,8,7,6,5,4,3,2,1};
    vector<int> ans=NSE(arr,arr.size());
    for (auto i:ans) {
        cout<<i<<" ";
    }
    return 0;
}
