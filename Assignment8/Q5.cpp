#include <bits/stdc++.h>
using namespace std;
void heapify(int arr[],int index,int n) {
    int left=2*index+1;
    int right=2*index+2;
    int largest=index;
    if (left<n && arr[left]>arr[largest]) {
        largest=left;
    }
    if (right<n && arr[right]>arr[largest]) {
        largest=right;
    }
    if (largest!=index) {
        swap(arr[index],arr[largest]);
        return heapify(arr,largest,n);
    }
    else {
        return;
    }
}
void BuildMaxHeap(int arr[],int n) {
    //step down approach(using heapify)
    for (int i=(n/2)-1;i>=0;i--) {
        heapify(arr,i,n);
    }
}
void sortArray(int arr[],int n) {
    BuildMaxHeap(arr,n);
    for (int i=n-1;i>=0;i--) {
        swap(arr[i],arr[0]);
        heapify(arr,0,i);
    }
}
void print(int arr[],int n) {
    for (int i=0;i<n;i++) {
        cout<<arr[i]<<" ";
    }
}
int main() {
    int arr[]={1,2,3,4,5,6,7,8,9,10};
    sortArray(arr,10);
    print(arr,10);
    return 0;
}
