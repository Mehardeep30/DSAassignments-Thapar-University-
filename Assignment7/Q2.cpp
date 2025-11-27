#include <bits/stdc++.h>
using namespace std;
void improvedSelectionSort(vector<int> &arr,int n) {
    int low=0;
    int high=n-1;
    while (low<high) {
        int minIndex=low;
        int maxIndex=low;
        for (int i=low;i<=high;i++) {
            if (arr[i]<arr[minIndex]) {
                minIndex=i;
            }
            if (arr[i]>arr[maxIndex]) {
                maxIndex=i;
            }
        }
        swap(arr[minIndex],arr[low]);
        if (maxIndex==low) maxIndex=minIndex;
        swap(arr[maxIndex],arr[high]);

        low++;
        high--;
    }
}
int main() {
    vector<int> arr={9,8,7,6,5,4,3,2,1};
    improvedSelectionSort(arr,arr.size());
    for (auto it:arr) {
        cout<<it<<" ";
    }
    return 0;
}
