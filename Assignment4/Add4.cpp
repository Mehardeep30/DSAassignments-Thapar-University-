#include <bits/stdc++.h>
using namespace std;

int countStudents(vector<int>& students, vector<int>& sandwiches) {
    queue<int> q;
    for (int s : students) q.push(s);
    
    int n = sandwiches.size();
    int count = 0;

    for (int i = 0; i < n; i++) {
        count = 0;
        while (!q.empty() && q.front() != sandwiches[i]) {
            int s = q.front();
            q.pop();
            q.push(s);
            count++;
            if (count == q.size()) return q.size();
        }
        if (!q.empty() && q.front() == sandwiches[i]) {
            q.pop();
        }
    }
    
    return 0;
}

int main() {
    vector<int> students = {1,1,0,0};
    vector<int> sandwiches = {0,1,0,1};

    cout << countStudents(students, sandwiches) << endl;
}
