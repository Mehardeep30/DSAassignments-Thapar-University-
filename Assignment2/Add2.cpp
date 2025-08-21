#include <iostream>
using namespace std;
bool canSplit(string &s) {
    int fre[26]={0};
    for (int i=0;i<s.size();i++) {
        fre[s[i]-'a']++;
        if (fre[s[i]-'a']>=3) return true;
    }
    return false;
}
int main() {
    string s="abcababc";
    cout<<canSplit(s);
    return 0;
}