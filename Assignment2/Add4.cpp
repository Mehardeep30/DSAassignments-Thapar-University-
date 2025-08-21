#include <iostram>
using namespace std;
void swap(int &a,int &b) {
    int temp=a;
    a=b;
    b=temp;
}
void sortArray(int arr[],int n) {
    int low=0;
    int high=n-1;
    int mid=0;
    while (mid<=high) {
        if (arr[mid]==0) {
            swap(arr[mid],arr[low]);
            low++;
            mid++;
        }
        else if (arr[mid]==1) {
            mid++;
        }
        else {
            swap(arr[mid],arr[high]);
            high--;
        }
    }
}
int main() {
    int nums[] = {2, 0, 2, 1, 1, 0};
    int n = sizeof(nums) / sizeof(nums[0]);
    sortArray(nums,n);
    for (int i=0;i<n;i++) {
        cout<<nums[i]<<" ";
    }
    return 0;
}