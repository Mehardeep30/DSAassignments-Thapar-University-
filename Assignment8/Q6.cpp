#include <bits/stdc++.h>
using namespace std;
class BinaryHeap {
public:
    int capacity;
    int size;
    int *arr;
    BinaryHeap(int cap) {
        capacity=cap;
        size=0;
        arr=new int[capacity];
    }
    int parent(int i) {
        return (i-1)/2;
    }
    int left(int i) {
        return 2*i+1;
    }
    int right(int i) {
        return 2*i+2;
    }
    void insert(int x) {
        if (size==capacity) {
            cout<<"Binary Heap Overflow!"<<endl;
            return;
        }
        arr[size]=x;
        int k=size;
        size++;
        while (k!=0 && arr[parent(k)]<arr[k]) {
            swap(arr[k],arr[parent(k)]);
            k=parent(k);
        }
    }
    void heapify(int ind) {
        int ri=right(ind);
        int le=left(ind);
        int largest=ind;
        if (ri<size && arr[ri]>arr[largest]) largest=ri;
        if (le<size && arr[le]>arr[largest]) largest=le;
        if (largest!=ind) {
            swap(arr[largest],arr[ind]);
            return heapify(largest);
        }
        else return;
    }
    int getMax() {
        return arr[0];
    }
    int ExtractMax() {
        if (size<=0) {
            return INT_MAX;
        }
        if (size==1) {
            size--;
            return arr[0];
        }
        int mini=arr[0];
        arr[0]=arr[size-1];
        size--;
        heapify(0);
        return mini;
    }
    void increaseKey(int i,int newVal) {
        if (i>=size) {
            cout<<"Invalid index!"<<endl;
            return;
        }
        if (newVal<arr[i]) {
            cout<<"New value is lesser!"<<endl;
            return;
        }
        arr[i]=newVal;
        while (i!=0 && arr[parent(i)]<arr[i]) {
            swap(arr[parent(i)],arr[i]);
            i=parent(i);
        }
    }
    void Delete(int i){
        if (i>=size) {
            cout<<"Invalid index!"<<endl;
            return;
        }
        increaseKey(i,INT_MAX);
        ExtractMax();
    }
    void print() {
        for (int i=0;i<size;i++) {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};
int main() {
    BinaryHeap pq(5);
    pq.insert(1);
    pq.insert(2);
    pq.insert(3);
    pq.print();
    return 0;
}
