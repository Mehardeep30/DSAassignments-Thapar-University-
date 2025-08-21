#include <iostream>
using namespace std;
bool CheckAnagram(string &s1,string &s2) {
    int freq[26]={0};
    if (s1.size()!=s2.size()) return false;
    for (int i=0;i<s1.size();i++) freq[s1[i]-'a']++;
    for (int i=0;i<s2.size();i++) freq[s1[i]-'a']--;
    for (int i=0;i<26;i++) {
        if (freq[i]!=0) return false;
    }
    return true;
}
int main() {
    string s1="listen";
    string s2="silent";
    cout<<CheckAnagram(s1,s2);
    return 0;
}