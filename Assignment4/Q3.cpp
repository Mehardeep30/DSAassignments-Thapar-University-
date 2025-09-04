#include <bits/stdc++.h>
using namespace std;
string interleave(string s) {
    queue<char> q;
    string ans;
    int n=s.size();
    for (int i=0;i<n/2;i++) {
        q.push(s[i]);
    }
    for (int i=n/2;i<n;i++) {
        if (!q.empty()) {
            ans.push_back(q.front());
            q.pop();
        }
        ans.push_back(s[i]);
    }
    return ans;
}
int main() {
    string s="12345";
    cout<<interleave(s);
    return 0;
}
