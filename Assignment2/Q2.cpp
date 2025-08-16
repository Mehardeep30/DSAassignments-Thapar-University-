#include <iostream>
using namespace std;
int binarySearch(int arr[],int n,int e) {
    int low=0;
    int high=n-1;
    while (low<=high) {
        int mid=(low+high)/2;
        if (arr[mid]==e) return mid;
        else if (arr[mid]>e) high=mid-1;
        else low=mid+1;
    }
    return -1;
}
int main() {
    int arr[10]={1,2,3,4,5,6,7,8,9,10};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<binarySearch(arr,n,5);
    return 0;
}