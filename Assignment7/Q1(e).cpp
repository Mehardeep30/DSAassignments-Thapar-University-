#include <bits/stdc++.h>
using namespace std;
int findp(vector<int> &arr,int low,int high) {
    int pivot=arr[low];
    int i=low;
    int j=high;
    while (i<=high && j>=low && i<j) {
        while (i<=high && arr[i]<=pivot) i++;
        while (j>=low && arr[j]>pivot) j--;
        if (i<j) swap(arr[i],arr[j]);
    }
    swap(arr[j],arr[low]);
    return j;
}
void qs(vector<int> &arr,int low,int high) {
    if (low>=high) return;
    int pindex=findp(arr,low,high);
    qs(arr,low,pindex-1);
    qs(arr,pindex+1,high);
}
void QuickSort(vector<int> &arr,int n) {
    int low=0;
    int high=n-1;
    qs(arr,low,high);
}
int main() {
    vector<int> arr = {10, 7, 8, 9, 1, 5};

    cout << "Original array: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    QuickSort(arr, arr.size());

    cout << "Sorted array:   ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    return 0;
}
