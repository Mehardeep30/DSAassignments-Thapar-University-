#include <iostream>
#include <string>
using namespace std;
bool vowel(char c) {
    if (c=='a' || c=='e' || c=='i' || c=='o' || c=='u' || c=='A' || c=='E' || c=='I' || c=='O' || c=='U') {
        return true;
    }
    return false;
}
string RemoveVowels(string s) {
    string ans="";
    for (int i=0;i<s.size();i++) {
        if (!vowel(s[i])) ans+=s[i];
    }
    return ans;
}
int main() {
    string s="Hello World";
    cout<<RemoveVowels(s);
    return 0;
}