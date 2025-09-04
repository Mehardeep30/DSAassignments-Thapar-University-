using namespace std;
void firstNonRepeating(string s) {
    int n=s.size();
    string ans;
    queue<char> q;
    unordered_map<char,int> mpp;
    for (int i=0;i<n;i++) {
        mpp[s[i]]++;
        q.push(s[i]);
        while (!q.empty() && mpp[q.front()]>1)q.pop();
        if (!q.empty()) cout<<q.front()<<" ";
        else cout<<"-1 ";
    }
    return;
}
int main() {
    string a="aabc";
    firstNonRepeating(a);
    return 0;
}
