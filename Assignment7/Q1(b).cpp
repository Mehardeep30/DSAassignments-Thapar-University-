#include <bits/stdc++.h>
using namespace std;
vector<int> insertionSort(vector<int> &arr,int n) {
    for (int i=0;i<=n-1;i++) {
        int j=i;
        while (j>0 && arr[j-1]>arr[j]) {
            int temp=arr[j-1];
            arr[j-1]=arr[j];
            arr[j]=temp;
            j--;
        }
    }
    return arr;
}
int main(){
  vector<int> arr={6,5,4,3,2,1};
  arr=insertionSort(arr,arr.size());
  for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
  }
  return 0;
}
