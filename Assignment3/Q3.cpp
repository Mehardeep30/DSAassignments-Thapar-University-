#include <iostream>
#include <string>
#include <stack>
using namespace std;
bool balancedParenthesis(string s) {
    int n=s.size();
    stack<char> st;
    for (int i=0;i<n;i++) {
        if (s[i]=='(' || s[i]=='{' || s[i]=='[') st.push(s[i]);
        else {
            if (st.empty()) return false;
            char ch=st.top(); st.pop();
            if (ch=='(' && s[i]==')' || ch=='{' && s[i]=='}' || ch=='[' && s[i]==']') continue;
            else return false;
        }
    }
    return st.empty();
}
int main() {
    string s="[{()}]";
    cout<<balancedParenthesis(s);
    return 0;
}