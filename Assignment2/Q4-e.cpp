#include <iostream>
#include <string>
using namespace std;
void lowerToUpper(string &s) {
    for (int i=0;i<s.size();i++) {
        if ((int)s[i]>=97 && (int)s[i]<=122) {
            s[i]=(char)((int)s[i]-32);
        }
    }
    return;
}
int main() {
    string s="abcdefABCDEF";
    lowerToUpper(s);
    cout<<s;
    return 0;
}