#include <bits/stdc++.h>
using namespace std;
vector<int> bubbleSort(vector<int> &arr,int n) {
    for (int i=0;i<n-1;i++) {
        bool check=true;
        for (int j=0;j<n-1-i;j++) {
            if (arr[j]>arr[j+1]) {
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                check=false;
            }
        }
        if (check) return arr;
    }
    return arr;
}
int main(){
  vector<int> arr={5,4,3,2,1};
  arr=bubbleSort(arr,arr.size());
  for(int i=0;i<arr.size();i++){
      cout<<arr[i]<<" ";
  }
  return 0;
}
