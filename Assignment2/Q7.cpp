#include <iostream>
using namespace std;
int cntInversions(int arr[],int n){
    int cnt=0;
    for (int i=0;i<n-1;i++) {
        for (int j=i+1;j<n;j++) {
            if (arr[i]>arr[j]) cnt++;
        }
    }
    return cnt;
}
int main() {
    int arr[5]={5,4,3,2,1};
    cout<<cntInversions(arr,5);
    return 0;
}