#include <iostream>
#include <string>
using namespace std;
string reverse(string s) {
    int low=0;
    int high=s.size()-1;
    while (low<high) {
        char temp=s[low];
        s[low++]=s[high];
        s[high--]=temp;
    }
    return s;
}
int main() {
    string s="MANNU";
    cout<<reverse(s);
    return 0;
}