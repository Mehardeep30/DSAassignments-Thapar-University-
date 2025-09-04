#include <bits/stdc++.h>
using namespace std;
void printBinaryNumber(int n) {
    queue<string> q;
    q.push("1");
    for (int i=0;i<n;i++) {
        string current=q.front();
        q.pop();
        cout<<current<<" ";
        q.push(current+"0");
        q.push(current+"1");
    }
    return;
}
int main() {
    printBinaryNumber(10);
    return 0;
}
