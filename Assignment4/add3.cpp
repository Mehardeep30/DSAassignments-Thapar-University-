#include <iostream>
#include <queue>
using namespace std;
void insertSorted(queue<int> &q,int x) {
    int n=q.size();
    bool inserted=false;
    for (int i=0;i<n;i++) {
        int curr=q.front();
        q.pop();
        if (!inserted && curr>x) {
            q.push(x);
            inserted=true;
        }
        q.push(curr);
    }
    if (!inserted) q.push(x);
    return;
}
void sortQueue(queue<int> &q) {
    if (q.empty()) return;
    int x=q.front();
    q.pop();
    sortQueue(q);
    insertSorted(q,x);
}
int main() {
    queue<int> q;
    q.push(3);
    q.push(1);
    q.push(4);
    q.push(2);

    sortQueue(q);

    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

    return 0;
}
