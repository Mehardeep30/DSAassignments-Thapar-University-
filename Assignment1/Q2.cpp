#include <iostream>
using namespace std;
void removeDuplicates(int arr[],int n) {
    int i,j;
    i=0;
    j=0;
    while (i<n-1 && j<n-1) {
        while (j<n-1 && arr[j]==arr[j+1]) {
            j++;
        }
        if (i<n-1 && j<n-1) {
            j++;
            i++;
        }
        arr[i]=arr[j];
        if (j<n-1) j++;
    }
    return;
}
int main() {
    int arr[]={1,1,1,1,2,2,2,3,3,5,5,6,6};
    removeDuplicates(arr,sizeof(arr)/sizeof(arr[0]));
    for (int i=0;i<sizeof(arr)/sizeof(arr[0]);i++) {
        cout<<arr[i]<<" ";
    }
    return 0;
}