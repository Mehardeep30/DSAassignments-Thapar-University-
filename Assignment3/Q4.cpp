#include <iostream>
#include <string>
#include <stack>
using namespace std;
int priority(char c) {
    switch (c) {
        case '^':
            return 3;
        case '*':
            return 2;
        case '/':
            return 2;
        case '+':
            return 1;
        case '-':
            return 1;
        default:
            return -1;
    }
}
string infixToPostfix(string s) {
    int n=s.size();
    stack<char> st;
    string ans="";
    int i=0;
    while (i<n) {
        if (s[i]>='a' && s[i]<='z' || s[i]>='A' && s[i]<='Z' || s[i]>='0' && s[i]<='9') ans+=s[i];
        else if (s[i]=='(') st.push(s[i]);
        else {
            if (s[i]==')') {
                while (!st.empty() && st.top()!='(') {
                    ans+=st.top(); st.pop();
                }
                if (!st.empty()) st.pop();
            }
            else {
                while (!st.empty() && priority(st.top())>=priority(s[i])) {
                    ans+=st.top();
                    st.pop();
                }
                st.push(s[i]);
            }
        }
        i++;
    }
    while (!st.empty()) {
        ans+=st.top();
        st.pop();
    }
    return ans;
}
int main() {
    string s="A+B*(C+D)/E";
    cout<<infixToPostfix(s);
    return 0;
}