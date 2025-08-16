#include <iostream>
using namespace std;
int FindMissingBinary(int arr[],int n) {
    if (arr[0]!=1) return 1;
    int low=0;
    int high=n-1;
    while (low<=high) {
        int mid=(low+high)/2;
        int expected=arr[0]+mid;
        if (arr[mid]==expected) low=mid+1;
        else if (arr[mid]>expected) high=mid-1;
    }
    if (arr[0]==1 && low==n) return n+1;
    return arr[low]-1;
}
int main() {
    int arr[5]={1,2,4,5,6};
    cout<<FindMissingBinary(arr,5);
    return 0;
}