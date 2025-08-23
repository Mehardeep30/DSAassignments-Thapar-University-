#include <iostream>
#include <string>
#include <stack>
#include <math.h>
using namespace std;
int evaluate(int a,int b,char c) {
    switch (c) {
        case '+':
            return a+b;
        case '-':
            return a-b;
        case '/':
            return a/b;
        case '*':
            return a*b;
        case '^':
            return pow(a,b);
        default:
            cout<<"Invalid Operator";
    }
}
int EvaluatePostfix(string s) {
    int n=s.size();
    int i=0;
    stack<int> st;
    while (i<n) {
        if (s[i]>='0' && s[i]<='9') st.push(s[i]-'0');
        else {
            int a=st.top(); st.pop();
            int b=st.top(); st.pop();
            st.push(evaluate(b,a,s[i]));
        }
        i++;
    }
    return st.top();
}
int main() {
    string s="22^";
    cout<<EvaluatePostfix(s);
    return 0;
}