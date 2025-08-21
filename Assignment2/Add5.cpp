#include <iostream>
using namespace std;
int count2(int arr[],int n) {
    int twos=0;
    for (int i=0;i<n;i++) {
        if (arr[i]==2) twos++;
    }
    return twos;
}
void Duplicate2(int arr[],int n) {
    int twos=count2(arr,n);
    int i=n-1;
    int j=n+twos-1;
    while (i>=0 && j>=0) {
        if (arr[i]!=2) {
            arr[j]=arr[i];
            i--;
            j--;
        }
        else {
            arr[j--]=2;
            arr[j--]=2;
            i--;
        }
    }
}
int main() {
    int arr[50]={1,2,2,3,4,2,5,6};
    int n=8;
    int twos=count2(arr,n);
    Duplicate2(arr,n);
    for (int i=0;i<n+twos;i++) {
        cout<<arr[i]<<" ";
    }
    return 0;
}