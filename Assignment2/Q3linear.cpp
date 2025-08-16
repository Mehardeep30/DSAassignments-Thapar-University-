#include <iostream>
using namespace std;
int findMissing(int arr[],int n) {
    if(arr[0]!=1) return 1;
    for (int i=0;i<n-1;i++) {
        if (arr[i+1]!=arr[i]+1) return arr[i]+1;
    }
    return n+1;
}
int main() {
    int arr[5]={1,2,3,5,6};
    cout<<findMissing(arr,5);
    return 0;
}