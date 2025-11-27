#include <bits/stdc++.h>
using namespace std;
void merge(vector<int> &arr,int low,int mid,int high) {
    vector<int> ans;
    int left=low;
    int right=mid+1;
    while (left<=mid && right<=high) {
        if (arr[left]<arr[right]) ans.push_back(arr[left++]);
        else ans.push_back(arr[right++]);
    }
    while (left<=mid) ans.push_back(arr[left++]);
    while (right<=high) ans.push_back(arr[right++]);
    for (int i=low;i<=high;i++) {
        arr[i]=ans[i-low];
    }
}
void ms(vector<int> &arr,int low,int high) {
    if (low>=high) return;
    int mid=(low+high)/2;
    ms(arr,low,mid);
    ms(arr,mid+1,high);
    merge(arr,low,mid,high);
}
void MergeSort(vector<int> &arr,int n) {
    int low=0;
    int high=n-1;
    ms(arr,low,high);
}
int main() {
    vector<int> arr = {5, 2, 8, 3, 1, 6, 4};

    cout << "Original array: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    MergeSort(arr, arr.size());

    cout << "Sorted array:   ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    return 0;
}
