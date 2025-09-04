#include <bits/stdc++.h>
using namespace std;
vector<int> NGE(vector<int> &arr,int n) {
    vector<int> ans(n);
    stack<int> st;
    for (int i=n-1;i>=0;i--) {
        while (!st.empty() && st.top()<arr[i]) st.pop();
        ans[i]=st.empty() ? -1:st.top();
        st.push(arr[i]);
    }
    return ans;
}
int main() {
    vector<int> arr={1,2,3,4,5,6,7,8,9,10};
    vector<int> ans=NGE(arr,arr.size());
    for (auto i:ans) {
        cout<<i<<" ";
    }
    return 0;
}
