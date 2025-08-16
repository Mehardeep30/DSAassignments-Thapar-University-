#include <iostream>
#include <string>
using namespace std;
string concat(string s1,string s2) {
    string ans="";
    for (int i=0;i<s1.size()+s2.size();i++) {
        if(i<s1.size()) ans+=s1[i];
        else ans+=s2[i-s1.size()];
    }
    return ans;
}
int main() {
    string s1="Mehardeep";
    string s2="Singh";
    cout<<concat(s1,s2);
    return 0;
}