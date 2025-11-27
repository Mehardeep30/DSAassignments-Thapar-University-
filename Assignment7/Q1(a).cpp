#include <bits/stdc++.h>
using namespace std;
vector<int> selectionSort(vector<int> &arr,int n) {
    for (int i=0;i<n-1;i++) {
        int mini=i;
        for (int j=i+1;j<n;j++) {
            if (arr[mini]>arr[j]) mini=j;
        }
        int temp=arr[mini];
        arr[mini]=arr[i];
        arr[i]=temp;
    }
    return arr;
}
int main(){
  vector<int> arr={9,8,7,6,5,4,3,2,1};
  arr=selectionSort(arr,arr.size());
  for(int i=0;i<arr.size();i++){
    cout<<arr[i]<<" ";
  }
  return 0;
]
