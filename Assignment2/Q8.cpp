#include <iostream>
using namespace std;
int distinct(int arr[],int n) {
    int cnt=0;
    int maxi=arr[0];
    for (int i=0;i<n;i++) {
        if (arr[i]>maxi) maxi=arr[i];
    }
    int hash[maxi+1]={0};
    for (int i=0;i<n;i++) {
        hash[arr[i]]++;
    }
    for (int i=0;i<maxi+1;i++) {
        if (hash[i]==1) cnt++;
    }
    return cnt;
}
int main() {
    int arr[5]={1,2,3,4,4};
    cout<<distinct(arr,5);
    return 0;
}