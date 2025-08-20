#include <bits/stdc++.h>
using namespace std;
void BubbleSort(int arr[],int n) {
    for (int i=0;i<n-1;i++) {
        bool check=true;
        for (int j=0;j<n-1-i;j++) {
            if (arr[j+1]<arr[j]) {
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                check=false;
            }
        }
        if (check) return;
    }
    return;
}
int countpairs(int arr[],int n,int k) {
    int i=0;
    int j=0;
    BubbleSort(arr,n);
    int cnt=0;
    while (i<n && j<n) {
        int diff=arr[j]-arr[i];
        if (diff>k) i++;
        else if (diff<k) j++;
        else {
            int ele1=arr[i];
            int ele2=arr[j];
            int cnt1=0;
            int cnt2=0;
            while (i<n && arr[i]==ele1) {
                cnt1++;
                i++;
            }
            while (j<n && arr[j]==ele2) {
                cnt2++;
                j++;
            }
            if (ele1==ele2) {
                cnt+=cnt1*(cnt1-1)/2;
            }
            else cnt+=cnt1*cnt2;
        }
    }
    return cnt;
}
int main() {
    int arr[6] = {2, 2, 2, 3, 3, 4};
    cout<<countpairs(arr,6,0);
    return 0;
}
